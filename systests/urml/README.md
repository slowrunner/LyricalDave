# Setup and Configure Ollama For URML




- set environment variables:  source set_openai_env.sh
```
#!/bin/bash

# Uncomment for local Ollama server
export OPENAI_BASE_URL="http://127.0.0.1:11434/v1"

# Uncomment and set IP for remote Ollama server
# export OPENAI_BASE_URL="http://x.x.x.x:11434/v1"

# Example small local model that just barely fits in a 4MB Raspberry Pi
export OPENAI_API_KEY="qwen2.5:3b"

# Example remote LLM with larger memory, larger context avail
# export OPENAI_API_KEY="qwen3.5:4b"
```
- urml options:  ```--provider openai``` and ```--model "qwen2.5:3b"

Note:  The default Ollama server context is 4k which is too small for URML use:
Enlarge the context by:
- sudo systemctl edit ollama.service
- sudo systemctl daemon-reload
- sudo systemctl restart ollama

Editing the service file for local server:
```
### Editing /etc/systemd/system/ollama.service.d/override.conf
### Anything between here and the comment below will become the contents of the drop-in file

[Service]
Environment="OLLAMA_CONTEXT_LENGTH=32000"

### Edits below this comment will be discarded
```

Editing the service file for remote server:
```
### Editing /etc/systemd/system/ollama.service.d/override.conf
### Anything between here and the comment below will become the contents of the>

[Service]
Environment="OLLAMA_HOST=0.0.0.0"
Environment="OLLAMA_CONTEXT_LENGTH=128000"

### Edits below this comment will be discarded
```



