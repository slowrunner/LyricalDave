#!/usr/bin/env python3

# FILE: ollama_mcp_client.py

# Reads the LLM intent, calls local server, and injects time.

# ollama_mcp_client.py
import json
import ollama
from time_server import get_system_datetime
from vbatt_server import get_gopigo3_vbatt
import datetime
import re

MODEL_NAME = 'qwen2.5:0.5b'

def extract_tool_name(tool_calls):
    if tool_calls:
        return tool_calls[0].function.name
    else:
        return None

def run_conversation(user_prompt):
    # 1. Send the user prompt and the tool definition to the LLM
    response = ollama.chat(
        messages=[{'role': 'user', 'content': user_prompt}],
        model=MODEL_NAME,
        tools=[{
            'type': 'function',
            'function': {
                'name': 'get_system_datetime',
                'description': 'Get the current date and time',
            },
        },
        {
            'type': 'function',
            'function': {
                'name': 'get_gopigo3_vbatt',
                'description': 'Get battery voltage',
            },
        }]
    )

    print("tool_calls: ", response.get('message', {}).get('tool_calls'))
    print("tool_name: ", extract_tool_name(response.get('message', {}).get('tool_calls')))

    # 2. Check if the LLM decided to call the local system clock tool
    if extract_tool_name(response.get('message', {}).get('tool_calls'))=='get_system_datetime':
        t=datetime.datetime.now().strftime("%H:%M:%S")
        print(t+": 🤖 "+ MODEL_NAME +" triggered the local MCP tool...")
        
        # Execute the Python clock function locally
        tool_output = get_system_datetime()
        print(f"⏰ System Clock Output: {tool_output}")

        # 2a. Send the system time back to the LLM so it can finish its sentence
        final_response = ollama.chat(
            model=MODEL_NAME,
            messages=[
                {'role': 'user', 'content': user_prompt},
                response['message'],
                {'role': 'tool', 'content': tool_output, 'name': 'get_system_datetime'}
            ]
        )
        return final_response['message']['content']
    
    # 3. Check if the LLM decided to call the local tool
    if extract_tool_name(response.get('message', {}).get('tool_calls'))=='get_gopigo3_vbatt':
        t=datetime.datetime.now().strftime("%H:%M:%S")
        print(t+": 🤖 "+ MODEL_NAME +" triggered the local MCP tool...")
        
        # Execute the Python clock function locally
        tool_output = get_gopigo3_vbatt()
        print(f"GoPiGo3 Battery: {tool_output} volts")

        # 3a. Send the tool output back to the LLM so it can finish its sentence
        final_response = ollama.chat(
            model=MODEL_NAME,
            messages=[
                {'role': 'user', 'content': user_prompt},
                response['message'],
                {'role': 'tool', 'content': tool_output, 'name': 'get_gopigo3_vbatt'}
            ]
        )
        return final_response['message']['content']


    return response['message']['content']

# Test the connection
if __name__ == "__main__":
    # prompt = "What is the exact time and date right now?"
    prompt = input("Question? (about time, vbatt, or anything): ")
    t=datetime.datetime.now().strftime("%H:%M:%S")
    print(f"{t}: User: {prompt}")
    answer = run_conversation(prompt)
    t=datetime.datetime.now().strftime("%H:%M:%S")
    print(f"{t}: {MODEL_NAME}: {answer}\n")

