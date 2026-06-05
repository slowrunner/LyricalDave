#!/usr/bin/env python3

# FILE: say_node.py

"""
    Uses espeak-ng TTS via plib/speak.say(text,vol,anytime)  to speak string phrases sent to /say service request

    dave_interfaces.srv.Say.srv
       string saystring
       int8   volume
       bool   anytime
       ---
       bool spoken

    CLI:   ros2 service call /say dave_interfaces/srv/Say "{saystring: 'hello', volume: 45, anytime: False}"

    volume:
     - 100  Loudest
     -  40  Normal
     -  10  Whisper

    anytime:
     - True  speak the request anytime, regardless of quiet hours  
     - False do not speak the request during quiet hours  
"""

DEBUG = False
# DEBUG = True

from dave_interfaces.srv import Say

import rclpy
from rclpy.node import Node
import sys
sys.path.insert(0,"/home/ubuntu/LyricalDave/plib")

from speak import say

import logging
import wave
import os
# from piper.voice import PiperVoice
from time import sleep
import subprocess
import datetime as dt


filename = 'temp.say_node.wav'

DT_FORMAT = "%Y-%m-%d %H:%M:%S.%f"

# voicedir = os.path.expanduser('~/LyricalDave/models/piper-tts/') #Where onnx model files are stored on my machine
# voicedir = '/home/ubuntu/LyricalDave/models/piper-tts/'  # Where onnx model files are stored on my machine
# model = voicedir+"en_US-arctic-medium.onnx"
# if DEBUG: print("say_node: model=",model)
# voice = PiperVoice.load(model)
# if DEBUG: print("PiperVoice Object Created")


class SayService(Node):

    def __init__(self):
        super().__init__('say')
        self.srv = self.create_service(Say, 'say', self.say_cb)
        # create logger
        self.logger = logging.getLogger(__name__)
        self.logger.setLevel(logging.INFO)

        self.loghandler = logging.FileHandler('/home/ubuntu/LyricalDave/logs/ros_speak.log')

        logformatter = logging.Formatter('%(asctime)s|%(message)s',"%Y-%m-%d %H:%M")
        self.loghandler.setFormatter(logformatter)
        self.logger.addHandler(self.loghandler)





    def say_cb(self, request, response):
        text = request.saystring
        vol = request.volume
        anytime = request.anytime


        logStr='Say request:"{}" vol:{} anytime:{}'.format(text,vol,anytime)
        self.get_logger().info(logStr)
        if DEBUG: 
            dtstr = dt.datetime.now().strftime(DT_FORMAT)
            print(dtstr,logStr)
            print("type(vol):",type(vol)," type(anytime):",type(anytime))
        # wav_file = wave.open(filename, 'w')
        # audio = voice.synthesize(text,wav_file)
        # if DEBUG:
        #     dtstr = dt.datetime.now().strftime(DT_FORMAT)
        #     print(dtstr,"say_node: file written, calling aplay")

        # subprocess.check_output(['aplay -D plughw:2,0 -r 22050 -f S16_LE ' + filename], stderr=subprocess.STDOUT, shell=True)
        try:
            # os.system('aplay -D plughw:2,0 -r 22050 -f S16_LE ' + filename)
            spoken=say(text,vol,anytime)
            if (spoken != None):
              response.spoken = spoken
            else:
              response.spoken = True
              if DEBUG: print("response from say() was None, forcing True")
        except Exception as e:
            logStr = "Exception: {}".format(str(e))
            self.get_logger().info(logStr)
            response.spoken = False
        if DEBUG:
            dtstr = dt.datetime.now().strftime(DT_FORMAT)
            print(dtstr,"say_node: after say() spoken:",response.spoken)

        # if os.path.isfile(filename):  
        #     os.remove(filename)
        #     if DEBUG:
        #         dtstr = dt.datetime.now().strftime(DT_FORMAT)
        #         print(dtstr,"say_node: file removed")

        self.logger.info("say_node: " + text + " - spoken: " + str(response.spoken) )

        return response


def main():
    rclpy.init()

    say_svc = SayService()

    try:
        rclpy.spin(say_svc)
    except KeyboardInterrupt:
        pass

    # rclpy.shutdown()


if __name__ == '__main__':
    main()




