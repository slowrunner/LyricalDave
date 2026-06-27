#!/bin/bash

# optional:      --envelope envelope.yaml \

model="qwen3.5:9b"
fn="${model//:/_}"

urml translate "Announce 'Driving forward 10 centimeters', and then execute the action" \
    --manifest gopigo3.manifest.yaml \
    --profile educational \
    --no-policy \
    --provider openai \
    --model $model \
    --save-rejected remote.$fn.gopigo3_t1.rejected.out \
    --out remote.$fn.gopigo3_t1.program.urml.yaml
