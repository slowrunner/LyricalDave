# Setup Ubuntu 26.04 Resolute Raccoon for LyricalDave

Raspberry Pi 4 Setup

Setup 64-bit Ubuntu 26.04 Server Resolute Racoon


As Of: 28 May  2026

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

=== configure life.log ====
```
more config/crontab-e (copy the lines to paste buffer)
sudo crontab -e
1 for nano
paste lines to end of file, save

cd ../logs
cp life.log.sav life.log
sudo chmod 666 life.log
sudo chmod 666 life.log.bak

sudo reboot
```

=== Install htop
```
sudo snap install htop
```


=== [Do Not Perform Yet] To disable boot to desktop:
- sudo systemctl set-default multi-user.target
- reboot
(to re-enable sudo systemctl set-default graphical.target)

Memory without desktop:
```
$ free -h
               total        used        free      shared  buff/cache   available
Mem:           3.9Gi       368Mi       3.1Gi       3.8Mi       490Mi       3.5Gi
Swap:          1.0Gi          0B       1.0Gi
```

=== [Not Yet]  Install ROS 2 Lyrical Luth Desktop ====


===== DONE =====
