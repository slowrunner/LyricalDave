# MY README for GoPiGo3 URML

FILE:  README_MY.md


This folder contains a modified gopigo3_adapter.py
- implements "wait 5 seconds" (wait->wait_passively 5)  
- corrects speak implementation to use espeak-ng (if installed)

USE CAUTION IF ISSUE ```./run_gopigo3.py --execute``` - ROBOT WILL TRAVEL

Announce and move 10cm forward:
```
./run_gopigo3.py remote.qwen3.5_9b.gopigo3_t1.program.urml.yaml --execute  
```

Test announce and wait primitives: (no movement)  
```
./run_gopigo3.py remot.qwen3.5_9b.gopigo3_t2.program.urml.yaml --execute  
```

Examples of sending NLU prompts to a remote LLM to generate URML programs:
- ./gopigo3_t1_remote.sh  sends 
```
"Announce 'Driving forward 10 centimeters', and then execute the action"
```
and the result is "validated urml program":  
```
profile: educational
behavior:
  type: sequence
  on_error: abort_and_report
  steps:
  - speak:
      utterance: Driving forward 10 centimeters
  - drive:
      distance: 0.1

```
- ./gopigo3_t2_remote.sh  sends:
```
"Announce 'This is a test of the emit_speech primitive with the GoPiGo3 URML runtime', 
 wait 5 seconds and then Announce 'execution after wait beginning'"
```
No movement commands in this test


