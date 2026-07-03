#!/usr/bin/env bash

# Good question, and your instinct at the end is correct: it is a loop, not a single call.

# What emit-prompt gives you is the system message. The actual prompt urml translate sends is a normal two-message chat call:

# role: system = the emit-prompt output (schema + your manifest + envelope + profile few-shots)
# role: user = your instruction string, e.g. Announce 'Executing a URML program'
# So nothing is hidden. 
# The "real prompt" is just those two messages. One correction on your env: OPENAI_API_KEY=qwen3.5:9b is putting the model where the key goes. 
# The model name belongs in the request body, and Ollama ignores the key entirely (any value works).

#!/usr/bin/env bash

exec > >(tee -a curl_test.out) 2>&1

uptime
echo "Starting curl_test"
set -euo pipefail

INSTRUCTION=$(jq -Rs . < user_prompt.txt)

# The system message. Add --include-few-shots so it matches what
# `urml translate` actually sends (translate includes profile few-shots).
urml emit-prompt \
  --manifest gopigo3.manifest.yaml \
  --profile educational \
  --no-few-shots \
  --out system_prompt.txt

uptime
echo "Curling prompts to remote Ollama"

SYSTEM=$(jq -Rs . < system_prompt.txt)
USER=$(jq -Rs . <<< "$INSTRUCTION")

curl -sS "${OPENAI_BASE_URL}/chat/completions" \
  -H "Authorization: Bearer ${OPENAI_API_KEY:-ollama}" \
  -H "Content-Type: application/json" \
  -d "{
    \"model\": \"qwen3.5:9b\",
    \"messages\": [
      {\"role\": \"system\", \"content\": ${SYSTEM}},
      {\"role\": \"user\",   \"content\": ${USER}}
    ],
    \"response_format\": {\"type\": \"json_object\"},
    \"stream\": false
  }"

uptime
echo "Curl Completion"


# Now the part you guessed right. That curl is one POST, 
# which is exactly attempt 1. If the model's first emission passes validation, that is the whole translate, one round trip. 
# If it does not, the bridge takes the validator's structured errors, appends them to the system prompt as revision context, 
#   and asks again, up to 3 times by default. 
#   curl alone will not do that validate-then-revise loop; 
#   running the loop is the entire reason the bridge exists. 
# So your "this would not work as a single request" is correct: a single request is only the happy path where the model gets it right the first time.



