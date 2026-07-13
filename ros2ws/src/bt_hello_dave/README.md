# bt_hello_dave

ROS 2 BehaviorTree.ROS2 "Hello Dave" dialog system.


## REQUIREMENTS STATEMENTS

### Speech Recognition Input

- Recognize grammar phrases from /stt/result topic published by voskros STT server
- Grammar phrase list loaded from YAML file at /home/ubuntu/LyricalDave/ros2ws/params/bt_hello_dave_grammar.yaml
- Grammar pushed to voskros /stt/set_grammar service on activation with retries covering ~10s startup window
- Accept phrases with extra words before/after the grammar phrase (substring matching)
- Accept phrases split across two consecutive /stt/result messages (2-message window matching)
- Drop non-matching single or paired STT messages from the blackboard after a 3-second stale timeout
- Consume matched STT entries from the blackboard after response is dispatched

### Greeting Responses (hello dave / hey dave / hi dave)

- Respond to "hello dave", "hey dave", "hi dave" with a random response from a configurable pool
- Anti-repeat: never repeat a response that was used in the 3 prior picks
- Random pool configurable in YAML without recompiling

### Fixed Phrase Responses (data-driven from YAML)

- "shalom dave" → speak "[[sh'ahLohm]]" with 5-second post-delay to prevent feedback
- "bokair tov dave" → speak "bokair tov" with 5-second post-delay
- "good morning dave" → speak "good morning to you" with 5-second post-delay
- "good afternoon dave" → speak "good afternoon to you" with 5-second post-delay
- "good evening dave" → speak "good evening to you" with 5-second post-delay
- "good night dave" → speak "good night, I'll be going to sleep now", enter sleep mode
- "lie lah tov dave" → speak "lie la tov, going to sleep now", enter sleep mode
- "go to sleep dave" → speak "Going To Sleep Now" at volume 75 anytime=true, enter sleep mode
- "wake up dave" → speak "I am awake now" at volume 75 anytime=true, exit sleep mode
- All fixed responses and their volume/anytime/post_delay/sleep_mode flags configurable in YAML

### Battery State Report

- "battery state dave" → read /battery_state topic and speak a formatted report
- Report voltage to one decimal place
- Report "Charging at NNN milliamps" if milliamps negative, "Discharging at NNN milliamps" if positive (no decimal)
- Report power to one decimal place in watts
- Report battery percent as integer
- Battery report spoken at normal volume with anytime=true

### Sleep Mode

- While asleep, all in-grammar phrases are logged but produce no spoken response
- "wake up dave" is the only phrase that produces a response while asleep
- Sleep mode state persisted on the BT blackboard as a global entry

### TTS Feedback Prevention

- Mute incoming STT results while a /say service call is in flight (blocking during speech)
- After speech completes (spoken==true), hold a 500ms grace period mute to absorb room/mic tail
- If spoken==false (quiet time: 11pm-10am), lift mute immediately with no grace period
- Auto-clear stuck mute after 20-second safety ceiling to prevent permanent deafness
- Flush muted STT messages cleanly (log the drop, don't enqueue)

### Text-to-Speech Output

- All spoken responses via /say service call (dave_interfaces/srv/Say)
- Service call format: {saystring: '<text>', volume: <int8>, anytime: <bool>}
- Normal voice volume: 50 (configurable in YAML)
- Sleep/wake volume: 75
- Service timeout: 15 seconds (covers longest battery report sentence)

### Logging

- Every matched in-grammar phrase logged to /home/ubuntu/LyricalDave/logs/heard.log
- Log format: YYYY-MM-DD HH:MM:SS|<phrase> matching original Python logging formatter
- All STT messages (matched or not) logged to ROS console via RCLCPP_INFO
- Muted/dropped STT messages logged to ROS console with reason

### Blackboard

- All global BT state entries use @-prefixed keys for cross-subtree visibility
- Every blackboard entry annotated with both ROS time and local wall-clock time at receipt
- @stt_queue: deque of up to 2 pending STT entries with timestamps
- @battery_state: latest battery reading with timestamps and validity flag
- @sleep_mode: current sleep/wake state
- @speaking, @speaking_since, @mute_until: TTS mute state with stuck-mute timeout

### Operator Debug and Control Services

- /hello_dave_bt/get_blackboard_debug (Trigger) — dump all key blackboard state as human-readable string
- /hello_dave_bt/force_unmute (Trigger) — manually clear stuck mute immediately
- /hello_dave_bt/reload_grammar (Trigger) — hot-reload grammar YAML and re-push phrase list to voskros without restart

### Testing

- stt_test_publisher executable to inject simulated /stt/result phrases without speaking
- bt_hello_dave_test_phrase.sh script wrapping the test publisher for single or split-phrase injection

### Lifecycle and Launch

- hello_dave_lifecycle_node implements full ROS 2 lifecycle (unconfigured → configured → active → deactivated → cleaned up → shutdown)
- bt_hello_dave.launch.yaml launches voskros and hello_dave_lifecycle_node together
- bt_hello_dave_activate.sh — configure and activate the lifecycle node
- bt_hello_dave_shutdown.sh — deactivate/cleanup/shutdown lifecycle node then SIGINT the launch process group with fallback explicit kills
- bt_hello_dave_reload_grammar.sh — call the hot-reload service

### Architecture

- BehaviorTree.ROS2 tree with ParallelAll root: STT subscriber branch, battery subscriber branch, dialog branch run concurrently
- EventsCBGExecutor with 3 threads: tick timer, ROS callbacks, debug/control services and lifecycle transitions each in separate MutuallyExclusive callback groups
- Separate internal rclcpp::Node (hello_dave_bt_internal) for ROS-aware BT nodes, alongside lifecycle node in same executor
- SetGrammar service client on dedicated callback group to avoid deadlock during on_activate() blocking wait
- Tick timer on dedicated callback group so on_deactivate() can cancel it without deadlocking
- Grammar YAML hot-reloadable at runtime; fixed responses and random pool update immediately, grammar list re-pushed to voskros

======= End of Requirements =======

## Status

2026-07-11: Testing complete - all planned requirements fully met and working

## Layout

```
(gopigo3) ubuntu@U26LDave:~/LyricalDave/ros2ws/src$ tree bt_hello_dave/
bt_hello_dave/
├── CMakeLists.txt
├── config
│   ├── bt_hello_dave_grammar.yaml
│   └── bt_hello_dave_tree.xml
├── include
│   └── bt_hello_dave
│       ├── battery_state_subscriber_node.hpp
│       ├── delay_seconds_node.hpp
│       ├── dispatch_nodes.hpp
│       ├── grammar_store.hpp
│       ├── hello_dave_lifecycle_node.hpp
│       ├── match_grammar_node.hpp
│       ├── register_nodes.hpp
│       ├── say_service_node.hpp
│       ├── set_grammar_node.hpp
│       ├── stt_queue_nodes.hpp
│       ├── stt_result_subscriber_node.hpp
│       └── types.hpp
├── launch
│   └── bt_hello_dave.launch.yaml
├── package.xml
├── README.md
├── scripts
│   ├── bt_hello_dave_activate.sh
│   ├── bt_hello_dave_blackboard_state.sh
│   ├── bt_hello_dave_clear_mute.sh
│   ├── bt_hello_dave_launch.sh
│   ├── bt_hello_dave_reload_grammar.sh
│   ├── bt_hello_dave_shutdown.sh
│   ├── bt_hello_dave_test_phrase.sh
│   ├── compile_debug_bt_hello_dave.sh
│   └── gdb_bt_hello_dave.sh
└── src
    ├── battery_state_subscriber_node.cpp
    ├── delay_seconds_node.cpp
    ├── dispatch_nodes.cpp
    ├── hello_dave_lifecycle_node.cpp
    ├── match_grammar_node.cpp
    ├── register_nodes.cpp
    ├── say_service_node.cpp
    ├── set_grammar_node.cpp
    ├── stt_queue_nodes.cpp
    ├── stt_result_subscriber_node.cpp
    └── stt_test_publisher.cpp

7 directories, 38 files
```

## Install into your workspace

```bash
# Copy package into your ROS 2 workspace src/
cp -r bt_hello_dave ~/LyricalDave/ros2ws/src/

# Copy config files to params (as you requested)
cp bt_hello_dave/config/bt_hello_dave_grammar.yaml ~/LyricalDave/ros2ws/params/
cp bt_hello_dave/config/bt_hello_dave_tree.xml      ~/LyricalDave/ros2ws/params/

# Copy helper scripts to cmds
cp bt_hello_dave/scripts/*.sh ~/LyricalDave/ros2ws/cmds/

# Build
cd ~/LyricalDave/ros2ws
colcon build --packages-select bt_hello_dave
source install/setup.bash
```

## Run

```bash
# Terminal 1: launch everything
ros2 launch bt_hello_dave bt_hello_dave.launch.yaml
or
cmds/bt_hello_dave_launch.sh

# Terminal 2: bring the BT lifecycle node up (waits for voskros internally)
~/LyricalDave/ros2ws/cmds/bt_hello_dave_activate.sh

# Terminal 3: test without speaking
~/LyricalDave/ros2ws/cmds/bt_hello_dave_test_phrase.sh "hello dave"
~/LyricalDave/ros2ws/cmds/bt_hello_dave_test_phrase.sh "battery state dave"
~/LyricalDave/ros2ws/cmds/bt_hello_dave_test_phrase.sh "good morning" "dave"

# Hot-reload grammar/responses YAML without restarting
~/LyricalDave/ros2ws/cmds/bt_hello_dave_reload_grammar.sh

# Shut everything down
~/LyricalDave/ros2ws/cmds/bt_hello_dave_shutdown.sh
```

## Customizing responses

Edit `bt_hello_dave_grammar.yaml`:

- `grammar.list` — phrases pushed to `/stt/set_grammar`
- `responses.fixed` — phrase -> {text, volume, anytime, post_delay,
  sets_sleep_mode/clears_sleep_mode} for simple no-processing replies
  (handled entirely by the `SayFixed` node, data-driven, no recompile
  needed)
- `random_pool` — pool for `SayRandomGreeting`'s anti-repeat picker
- `greeting_phrases` / `battery_phrases` — phrases routed to the two
  C++-logic nodes (`SayRandomGreeting`, `BuildBatteryReport`)

After editing, run `bt_hello_dave_reload_grammar.sh` to apply without
restarting.


### Test Sequence

- Build clean — colcon build --packages-select bt_hello_dave with no errors
- Launch + activate — no warning/crash on startup; "Activated. Ticking tree every 100ms" appears
- Single greeting — say "hello dave"; exactly one random response spoken, no repeats in launch log
- Anti-repeat greeting — say "hello dave" 4× in a row; confirm no response repeats in the last 3 picks
- Mute during speech — say "hello dave"; watch launch log for stt_result received: lines being suppressed during TTS, then resuming after grace period
- Battery state — say "battery state dave"; full report spoken; no false re-trigger from TTS feedback afterward
- Sleep mode enter — say "go to sleep dave"; confirms "Going To Sleep Now" spoken
- Sleep mode deaf test — while asleep say "hello dave"; confirm logged in heard.log but no TTS response
- Wake up — say "wake up dave"; confirms "I am awake now"; next "hello dave" responds normally
- Blackboard debug — call /hello_dave_bt/get_blackboard_debug; verify all keys reported correctly
- Force unmute — while muted (or simulate stuck mute), call /hello_dave_bt/force_unmute; confirm system hears again
- Grammar reload — edit bt_hello_dave_grammar.yaml (add a random_pool entry); call bt_hello_dave_reload_grammar.sh; verify new response appears
- Shutdown — bt_hello_dave_shutdown.sh; confirm voskros also terminates; no orphan processes


### Development Report

This project began with stating the requirments to Claude AI in a web browser, 
and asking for C++, ROS 2 Lyrical Luth coding utilizing the existing nodes:
- ROSVosk  speech recognition
- say_node Dave's TTS speech server 

and subscribing to:
- /battery_state
- /stt/result

Successful 27 day #ROS2 #LyricalLuth #C++ #BehaviorTree (with #Blackboard ) 
#SpeechRecognition #TextToSpeech  #LifestyleNodes project integrated with 
my #RaspberryPi4 #GoPiGo3 #Robot written, debugged, and full functionality 
testing with one to two daily "token limit reached" sessions on the free 
#ClaudeAI web browser interface.

I had to remind/request Claude use #MultiTheadedExecutors and 
#ReentrantCallbackGroups and some #MutuallyExclusives but all 
other implementation decisions were as I would choose.
