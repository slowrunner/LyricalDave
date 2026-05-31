# Setup Ubuntu 26.04 Resolute Raccoon for LyricalDave

Raspberry Pi 4 Setup

Setup 64-bit Ubuntu 26.04 Server Resolute Racoon


As Of: 31 May  2026

Ubuntu 26.04 server for Raspberry Pi Image

** Get Latest Raspberry Pi Imager (will list latest OS options) **
https://www.raspberrypi.com/software/

v2.0.7

**Write Ubuntu 26.04 Server 64-bit to SDcard with Raspberry Pi Imager**
  - Choose OS -> Other General Purpose (or Custom) -> Ubuntu 26.04 64-bit Server
  - User: ubuntu
  - Hostname: U26LDave

=== Diable IPv6 ===
- mount  
- nano current/cmdline.txt  
   - add ipv6.disable=1 to end of line

==== First Boot ====
  - arp -a to find ip  
  - user: ubuntu  machine: U26LDave , WiFi connect  
  - ps -ef | grep unattended  
  - sudo kill xxxx  
  - wait for any ```ps -ef | grep dpkg``` to complete  

=== UPDATE AND UPGRADE ===  

sudo apt update && sudo apt upgrade -y  


===   
```
uname -a
Linux U26LDave 7.0.0-1010-raspi #10-Ubuntu SMP PREEMPT_DYNAMIC Wed Apr 29 16:04:13 UTC 2026 aarch64 GNU/Linux


ubuntu@U26LDave:~$ cat /etc/os-release 
PRETTY_NAME="Ubuntu 26.04 LTS"
NAME="Ubuntu"
VERSION_ID="26.04"
VERSION="26.04 (Resolute Raccoon)"
VERSION_CODENAME=resolute
ID=ubuntu
ID_LIKE=debian

```


==== Check Disk Space ====  
```
ubuntu@U26LDave:~$ df
Filesystem     1K-blocks    Used Available Use% Mounted on
tmpfs             773932    1316    772616   1% /run
/dev/mmcblk0p2  30082508 3240508  25561560  12% /
tmpfs            1934824       0   1934824   0% /dev/shm
none                1024       0      1024   0% /run/credentials/systemd-journald.service
tmpfs            1934828       0   1934828   0% /tmp
none                1024       0      1024   0% /run/credentials/systemd-resolved.service
/dev/mmcblk0p1    516204  210189    306016  41% /boot/firmware
none                1024       0      1024   0% /run/credentials/systemd-networkd.service
none                1024       0      1024   0% /run/credentials/getty@tty1.service
none                1024       0      1024   0% /run/credentials/serial-getty@ttyS0.service
tmpfs             386964       8    386956   1% /run/user/1000

```

===== Check memory =======
```
ubuntu@U26LDave:~$ free -h
               total        used        free      shared  buff/cache   available
Mem:           3.7Gi       426Mi       3.0Gi       1.3Mi       426Mi       3.3Gi
Swap:             0B          0B          0B
```

=== CONFIGURE PASSWORD-LESS SUDO
```
sudo nano /etc/sudoers

make sudo group look like:
# Allow members of group sudo to execute any command
%sudo	ALL=(ALL:ALL) NOPASSWD: ALL
```

======= Bring Down Git Repo =======  
On GitHub, navigate to the main page of the repository.  

Code button next to the repository name, click Clone HTTPS, Click copy  
```
cd ~
git clone https://github.com/slowrunner/LyricalDave.git
cd LyricalDave
```

=== configure shortcut to ROS2 workspace ===
```
cd config
cp tilde_go.sh ~/go.sh
```

==== Disable unattended upgrades ===
```
sudo systemctl disable --now unattended-upgrades.service
sudo systemctl disable --now apt-daily.timer
sudo systemctl disable --now apt-daily-upgrade.timer
sudo nano /etc/apt/apt.conf.d/20auto-upgrades
- set both variables to 0


```
==== Configure git credentials =======
```
cd ~/LyricalDave

git config --global user.name "slowrunner"
git config --global user.email "slowrunner@users.noreply.github.com"  (does not expose)
git config --global credential.helper store
git config --list

edit README.md
add/commit/push (paste token)
```
=== configure plib ====

## Install numpy for wheellog
```
pip3 install numpy
```

If need to change user and repo on all plib files:
```
sed -i 's/old_user/new_user/g' *
sed -i 's/old_repo/new_repo/g' *
```
Tests:

```
./wheellog.py
```
=== Configure ALSA and PulseAudio for USB Audio (UACDemoV10) ===

## Install packages
```
sudo apt install alsa-utils pavucontrol ffmpeg espeak-ng
```

## Configure ALSA default device
```
cp config/tilde_dot_asoundrc ~/.asoundrc
```

--- tilde_dot_asoundrc ---
```
pcm.!default {
  type plug
  slave {
    pcm "hw:UACDemoV10,0"
  }
}

ctl.!default {
  type hw
  card UACDemoV10
}
```

## Verify USB card is present and get its name

```
aplay -l
cat /proc/asound/cards

Expected: card N: UACDemoV10 [UACDemoV1.0] ... Jieli Technology
```

## Store ALSA state bound to named card (not card number)
```
sudo alsactl store UACDemoV10
systemctl status alsa-restore    # verify service exists
```
## Test ALSA directly (bypasses PulseAudio)

speaker-test -c2 -t wav -D hw:UACDemoV10,0

## Configure PulseAudio default sink

PulseAudio runs on top of ALSA and overrides .asoundrc for most apps.  
Must be set separately.  

## Verify PulseAudio is running
```
systemctl --user status pulseaudio
```
Check available sinks
```
pactl list sinks short
```
Set USB card as default sink
```
pactl set-default-sink alsa_output.usb-Jieli_Technology_UACDemoV1.0_1120040804060316-00.analog-stereo
```
Persist across reboots via client.conf
```
echo "default-sink = alsa_output.usb-Jieli_Technology_UACDemoV1.0_1120040804060316-00.analog-stereo" > ~/.config/pulse/client.conf
```
Restart PulseAudio to apply
```
systemctl --user restart pulseaudio
```
Verify default sink changed
```
pactl info | grep -i "default sink"
Expected: Default Sink: alsa_output.usb-Jieli_Technology_UACDemoV1.0_1120040804060316-00.analog-stereo
```
## Test PulseAudio path (no -D flag = uses PulseAudio default)
```
speaker-test -c2 -t wav
espeak-ng hello

plib/speak.py

```

## Notes
- The dB range warnings in journalctl for the PCM element are harmless  
- The HDMI module-alsa-card failures are harmless (Pi4 HDMI audio quirk)  
- Card numbers (hw:0, hw:1) can shift on reboot; always use names (UACDemoV10)  
- .asoundrc controls ALSA-direct apps; client.conf controls PulseAudio apps  
- pavucontrol is useful for runtime sink switching and volume control  

## Reboot and verify
```
reboot
pactl info | grep -i "default sink"
espeak-ng "audio is working"
```

try systests/audio/tts/try_espeak-ng.py


=== configure non-root vcgencmd access ====
```
cd config
./install_99-vcio_rules.sh

try:
vcgencmd measure_temp
plib/status.py

```


=== configure life.log ====
```
mkdir ~/LyricalDave/logs

more config/crontab-e (copy the lines to paste buffer)
sudo crontab -e
1 for nano
paste lines to end of file, save

cd ../logs
cp life.log.sav life.log
sudo chmod 666 life.log
mkdir tmp/
touch tmp/life.log.bak
sudo chmod 666 tmp/life.log.bak

sudo reboot

(Had to add virtual environment python for each nohup and in crontab-e)
(Had to add multiprocessing start with fork line for Python 3.14)
```

=== Install htop
```
sudo snap install htop
```

==== Setup 2GB Swap ====

```
sudo fallocate -l 2G /swapfile
sudo chmod 600 /swapfile
sudo mkswap /swapfile
sudo swapon /swapfile
sudo swapon --show
echo '/swapfile none swap sw 0 0' | sudo tee -a /etc/fstab

# lower "swappiness" for uSDcard operation
sudo sysctl vm.swappiness=10
echo 'vm.swappiness=10' | sudo tee -a /etc/sysctl.conf

```




```
ubuntu@U26LDave:~/LyricalDave$ free -h
               total        used        free      shared  buff/cache   available
Mem:           3.7Gi       487Mi       2.9Gi       1.4Mi       474Mi       3.2Gi
Swap:          2.0Gi          0B       2.0Gi
```

=== READY for ROS 2 Lyrical Luth Install ====


===== DONE =====
