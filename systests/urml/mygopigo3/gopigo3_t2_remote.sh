#!/bin/bash

# optional:      --envelope envelope.yaml \

phrase="Announce 'This is a test of the emit_speech primitive with the GoPiGo3 URML runtime', wait 5 seconds and then Announce 'execution after wait beginning'" \
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
    --save-rejected remote.$fn.gopigo3_t2.rejected.out \
    --out remote.$fn.gopigo3_t2.program.urml.yaml

uptime
echo "Done"
