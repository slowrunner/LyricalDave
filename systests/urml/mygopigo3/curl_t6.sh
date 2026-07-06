#!/usr/bin/env bash


testnum=6
exec > >(tee -a curl_t$testnum.out) 2>&1

uptime
echo "Starting curl_t$testnum.sh"
set -euo pipefail

INSTRUCTION=$(jq -jRs . < user_prompt.txt)
echo "INSTRUCTION=$INSTRUCTION"

urml emit-prompt \
  --manifest gopigo3.manifest.yaml \
  --profile educational \
  --out system_prompt.txt

uptime
echo "Curling prompts to remote Ollama"

SYSTEM=$(jq -Rs . < system_prompt.txt)
USERSTR=$(jq -Rs . <<< "$INSTRUCTION")

echo "USERSTR:"
echo $USERSTR
echo " "

curl -sS "${OPENAI_BASE_URL}/chat/completions" \
  -H "Authorization: Bearer ${OPENAI_API_KEY:-ollama}" \
  -H "Content-Type: application/json" \
  -d "{
    \"model\": \"qwen3.5:9b\",
    \"messages\": [
      {\"role\": \"system\", \"content\": ${SYSTEM}},
      {\"role\": \"user\",   \"content\": ${USERSTR}}
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



