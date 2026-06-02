#!/usr/bin/env python3
'''
#
# Usage:  ./try_espeak-ng.py
#         Enter the Text: (enter line of text (with or without quotes - no printed char restrictions)

# PreREQ:  
#  sudo apt install ffmpeg
#  sudo apt install alsa-utils
#  use amixer to set volume on sound card
#    then sudo alsactl store to save settings
#    check systemctl status alsa-restore  (service that restores hardware settings after reboots)
'''

import os
import time

text = input("Enter the Text: ")
print(text)

#Replacing ' ' with '_' to identify words in the text entered
#text = text.replace(' ', '_')
text = text.replace("'","")
text = text.replace('"',' quote ')

#Calls the espeak TTS Engine to read aloud a Tex
print('espeak-ng ',text)
os.system("espeak-ng \""+text+" spoken by e speak n g.\"")

time.sleep(5)

#Use espeak-ng TTS engine to write to a wav file
print("expeak-ng -w espeak-ng.wav \""+text+"\"")
os.system("espeak-ng -w espeak-ng.wav \""+text+" in a wave file\"")

time.sleep(5)

#Use aplay to replay the espeak-ng.wav file"
print("aplay espeak-ng.wav")
os.system("aplay espeak-ng.wav 2>/dev/null")

time.sleep(5)

#Use ffplay to replay the espeak-ng wav file"
print("ffplay -nodisp -autoexit espeak-ng.wav 2>/dev/null")
os.system("ffplay  -nodisp -autoexit espeak-ng.wav 2>/dev/null")

time.sleep(5)
