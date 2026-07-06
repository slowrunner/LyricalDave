#!/bin/bash

# optional:      --envelope envelope.yaml \

testnum=7
INSTRUCTION=$(jq -Rs . < user_prompt.t$testnum.txt)
# INSTRUCTION=""
model="qwen3.5:9b"
fn="${model//:/_}"

echo "TEST: $testnum"
echo "For instructions:"
echo $INSTRUCTION
echo "performing urml translate to remote Ollama server"
echo "with $model"
date
urml translate "$INSTRUCTION" \
    --manifest gopigo3.manifest.yaml \
    --profile educational \
    --no-policy \
    --provider openai \
    --model $model \
    --save-rejected remote.$fn.gopigo3_t$testnum.rejected.out \
    --out remote.$fn.gopigo3_t$testnum.program.urml.yaml
echo "Done"
date
