# MCP for Ollama

### Installation

1) Install Prereqs
```
(in the venv)
pip3 install mcp ollama

```

2) Create Local MCP Server (tool) Scripts
- get_system_datetime
- get_gopigo3_vbatt

3) Add tools to ollama_mcp_client.py
(hack: only checking first tool if more than one in prompt)


4) Run ollama_mcp_client.py
- ask "What time is it now?"
- ask "What is Dave's current battery voltage?"
- ask "What do you know about the GoPiGo3 robot?"


### Models  (ollama pull model_name)

Model Location:  Linux: /usr/share/ollama/.ollama/models  

- tinylamma: does not allow tools
- qwen2.5:0.5b:  allows tools



