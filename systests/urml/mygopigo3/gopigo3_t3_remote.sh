#!/bin/bash

# optional:      --envelope envelope.yaml \

testnum=3
phrase="Announce 'Measuring distance',wait 3, measure distance, wait 3, announce the distance the sensor returned." \
model="qwen3.5:9b"
fn="${model//:/_}"

uptime
echo "Starting remote translate"
echo -e "phrase: $phrase"

time urml translate "$phrase" \
    --manifest gopigo3.manifest.yaml \
    --profile educational \
    --no-policy \
    --provider openai \
    --model $model \
    --save-rejected remote.$fn.gopigo3_t$testnum.rejected.out \
    --out remote.$fn.gopigo3_t$testnum.program.urml.yaml

uptime
echo "Done"
