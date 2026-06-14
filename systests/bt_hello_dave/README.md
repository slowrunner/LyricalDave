# bt_hello_dave

ROS 2 BehaviorTree.ROS2 "Hello Dave" dialog system.

## Status

This is a **design starting point**, assembled from discussion/snippets.
It is structurally complete (CMakeLists, package.xml, headers, sources,
XML tree, YAML config, launch, scripts) but **has not been
compiled/tested**. Expect to fix:

- Exact message/service field names for `dave_interfaces/msg/BatteryState`
  and `dave_interfaces/srv/Say` (assumed: `voltage`, `milliamps`, `watts`,
  `percent` / `saystring`, `volume`, `anytime`).
- `voskros/srv/SetGrammar` field names (assumed: `list`).
- `behaviortree_ros2` API specifics for your installed version
  (`RosTopicSubNode`, `RosServiceNode`, `RosNodeParams` signatures can
  vary between releases).
- `say_node_pkg` / `dave_interfaces_pkg` placeholder package names in
  the launch file.
- The `ParallelAll` / `KeepRunningUntilFailure` node names against your
  BT.CPP version's built-in node library (names have changed across
  BT.CPP 3 vs 4).

## Layout

```
bt_hello_dave/
├── CMakeLists.txt
├── package.xml
├── include/bt_hello_dave/      # headers
├── src/                          # implementations + main + test publisher
├── config/                       # YAML grammar + BT XML tree
│   ├── bt_hello_dave_grammar.yaml
│   └── bt_hello_dave_tree.xml
├── launch/
│   └── bt_hello_dave.launch.yaml
└── scripts/
    ├── bt_hello_dave_activate.sh
    ├── bt_hello_dave_shutdown.sh
    ├── bt_hello_dave_reload_grammar.sh
    └── bt_hello_dave_test_phrase.sh
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
