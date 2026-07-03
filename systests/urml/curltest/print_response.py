#!/usr/bin/env python3

import json

# response={"id":"chatcmpl-220","object":"chat.completion","created":1782655161,"model":"qwen3.5:9b","system_fingerprint":"fp_ollama","choices":[{"index":0,"message":{"role":"assistant","content":"{\n  \"profile\": \"educational\",\n  \"behavior\": {\n    \"type\": \"sequence\",\n    \"on_error\": \"abort_and_report\",\n    \"steps\": [\n      {\n        \"speak\": {\n          \"utterance\": \"Executing a URML program\"\n        }\n      }\n    ]\n  }\n}","reasoning":"The user wants me to announce that I'm executing a URML program. This is speaking via the `speech` output endpoint which exists in the manifest (`Output endpoints: speech, run_log`).\n\nI need to create a simple behavior with one step - the speak primitive - to emit this announcement message."},"finish_reason":"stop"}],"usage":{"prompt_tokens":20071,"completion_tokens":79,"total_tokens":20150}} 
with open('response.json', 'r', encoding='utf-8') as file:
  response=json.load(file)
print("RESPONSE:\n")
print(json.dumps(response, indent=4))
print("\n")

print("CONTENT:\n")
urml=response["choices"][0]["message"]["content"]
# clean_urml= urml.replace(r'\"', '"')
#print(json.dumps(urml, indent=4))
print(urml)
print("\n")


