# Vosk Local Speech Recognition for Lyrical-Dave

Very lightweight speech to text good for wake word recognition  

DOCS: https://alphacephei.com/vosk/  
GIT: https://github.com/alphacep/vosk-api/tree/master  


### === Installation  
```
pip3 install vosk   
pip3 install sounddevice  
sudo apt install portaudio19-dev  


mkdir ~/LyricalDave/models  
pushd ~/LyricalDave/models  
wget https://alphacephei.com/vosk/models/vosk-model-small-en-us-0.15.zip  
sudo apt install unzip
unzip *.zip  
rm *.zip  
popd  
```

### === Find Mic Device ===
```
(With tiny USB mic and reboot)
(gopigo3) ubuntu@U26LDave:~/LyricalDave/systests/vosk$ lsusb
Bus 001 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub
Bus 001 Device 002: ID 2109:3431 VIA Labs, Inc. Hub
Bus 001 Device 003: ID 0d8c:013c C-Media Electronics, Inc. CM108 Audio Controller
Bus 001 Device 004: ID 4c4a:4155 Jieli Technology UACDemoV1.0
Bus 001 Device 005: ID 0079:0126 DragonRise Inc. Controller
Bus 002 Device 001: ID 1d6b:0003 Linux Foundation 3.0 root hub
Bus 003 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub


(gopigo3) ubuntu@U26LDave:~/LyricalDave/systests/vosk$ arecord --list-devices
**** List of CAPTURE Hardware Devices ****
card 3: Device [USB PnP Sound Device], device 0: USB Audio [USB Audio]
  Subdevices: 1/1
  Subdevice #0: subdevice #0


sudo alsamixer
- raise PCM audio to max below red
- sudo alsactl store
- systemctl status alsa-restore  make sure enabled - appears "active (exited)"


(gopigo3) ubuntu@U26LDave:~/LyricalDave/systests/vosk$ arecord --device="hw:3,0" -d 15 -r 44100  -f hello_dave.wav
Recording WAVE 'test_s16_le_44100.wav' : Signed 16 bit Little Endian, Rate 44100 Hz, Mono


(gopigo3) ubuntu@U26LDave:~/LyricalDave/systests/vosk$ aplay hello_dave.wav 
Playing WAVE 'test_s16_le_44100.wav' : Signed 16 bit Little Endian, Rate 44100 Hz, Mono

(It will be soft volume)

```

### === Test file recognition ===

Edit test_file.py for new model path

```
model = Model("/home/ubuntu/LyricalDave/models/vosk-model-small-en-us-0.15")
```

```
(gopigo3) ubuntu@U26LDave:~/LyricalDave/systests/vosk$ ./test_file.py hello_dave.wav 
LOG (VoskAPI:ReadDataFiles():model.cc:213) Decoding params beam=10 max-active=3000 lattice-beam=2
LOG (VoskAPI:ReadDataFiles():model.cc:216) Silence phones 1:2:3:4:5:6:7:8:9:10
LOG (VoskAPI:RemoveOrphanNodes():nnet-nnet.cc:948) Removed 0 orphan nodes.
LOG (VoskAPI:RemoveOrphanComponents():nnet-nnet.cc:847) Removing 0 orphan components.
LOG (VoskAPI:ReadDataFiles():model.cc:248) Loading i-vector extractor from /home/ubuntu/LyricalDave/models/vosk-model-small-en-us-0.15/ivector/final.ie
LOG (VoskAPI:ComputeDerivedVars():ivector-extractor.cc:183) Computing derived variables for iVector extractor
LOG (VoskAPI:ComputeDerivedVars():ivector-extractor.cc:204) Done.
LOG (VoskAPI:ReadDataFiles():model.cc:282) Loading HCL and G from /home/ubuntu/LyricalDave/models/vosk-model-small-en-us-0.15/graph/HCLr.fst /home/ubuntu/LyricalDave/models/vosk-model-small-en-us-0.15/graph/Gr.fst
LOG (VoskAPI:ReadDataFiles():model.cc:308) Loading winfo /home/ubuntu/LyricalDave/models/vosk-model-small-en-us-0.15/graph/phones/word_boundary.int

.
.
.
{
  "partial" : ""
}
{
  "result" : [{
      "conf" : 0.528581,
      "end" : 1.380000,
      "start" : 0.000000,
      "word" : "hello"
    }, {
      "conf" : 0.635461,
      "end" : 1.830000,
      "start" : 1.380000,
      "word" : "day"
    }],
  "text" : "hello day"
}
{
  "partial" : ""
}
.
.
.


```

### === Test Hello Dave Grammar ====

```
./test_hello_dave.py
```
Try: "hey dave", "Hello Dave", "Good Morning Dave", "Good Afternoon Dave", and "Good Night Dave" (to exit test)


### === Test Micropone Language Model Reco ====
```
./test_microphone.py
```
