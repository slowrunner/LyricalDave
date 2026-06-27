#!/bin/bash

# optional:      --envelope envelope.yaml \
#     --provider openai \
#     --model $model \
#     --save-rejected remote.$fn.gopigo3_t1.rejected.out \
#     --out remote.$fn.gopigo3_t1.program.urml.yaml
#     --no-policy \

model="qwen3.5:9b"
fn="${model//:/_}"

# urml emit-prompt "Announce 'Driving forward 10 centimeters', and then execute the action" \
urml emit-prompt \
    --manifest gopigo3.manifest.yaml \
    --profile educational \
    --out prompt.gopigo3_without_prompt.yaml
