#!/usr/bin/env python3

# FILE: test_hello_dave_grammar.py

# PREREQ: pip3 install vosk 
#         wget https://alphacephei.com/vosk/models/vosk-model-small-en-us-0.15.zip to ~/LyricalDave//models
#         unzip the model

# Listens for "Hello Dave","Hey Dave", "Good Morning Dave", "Good Afternoon Dave", and speaks a response
# Listens for "Good Night Dave" - speaks "Good Night. Going to sleep now" and exits.
#
import argparse
import queue
import sys
import sounddevice as sd
sys.path.append('/home/ubuntu/LyricalDave/plib')
MODEL_PATH="/home/ubuntu/LyricalDave/models/vosk-model-small-en-us-0.15"
LOG_PATH="/home/ubuntu/LyricalDave/logs/heard.log"

ANYTIME=False
ANYTIME=True

import speak
import logging
from time import sleep

from vosk import Model, KaldiRecognizer
import random



class Random_Hello_Response:
    def __init__(self):
        # Master list of all available robot phrases
        self.robot_responses = [
            "Hello.",                 # Index 0
            "Hi.",                    # Index 1
            "Greetings.",             # Index 2
            "Hello there.",           # Index 3
            "Back at ya.",            # Index 4
            "Ready to slay dragons.", # Index 5
            "[[sh'ahLohm]]",          # Index 6
            "Yo.",                    # Index 7
            "I'm here.",              # Index 8
            "What's up.",             # Index 9
            "Did you bring me something?",  # Index 10
        ]

        # Instance history list tracking up to the last 3 choices
        self.last_three_responses = []

    def get_filtered_response(self) -> str:
        # 1. Filter out any phrase currently sitting in the history list
        available_choices = [
            response for response in self.robot_responses 
            if response not in self.last_three_responses
        ]

        # Fallback safeguard: if history somehow blocks all options, use the full list
        if not available_choices:
            available_choices = self.robot_responses

        # 2. Pick a random phrase from the filtered pool
        new_response = random.choice(available_choices)

        # 3. Add the new selection to the end of the history tracker
        self.last_three_responses.append(new_response)

        # 4. Evict the oldest choice if history exceeds three items
        if len(self.last_three_responses) > 3:
            self.last_three_responses.pop(0)

        return new_response





def int_or_str(text):
    """Helper function for argument parsing."""
    try:
        return int(text)
    except ValueError:
        return text



def main():

    q = queue.Queue()

    def callback(indata, frames, time, status):
        """This is called (from a separate thread) for each audio block."""
        if status:
            print(status, file=sys.stderr)
        q.put(bytes(indata))


    # create logger
    logger = logging.getLogger('heardLog')
    logger.setLevel(logging.INFO)

    loghandler = logging.FileHandler(LOG_PATH)
    logformatter = logging.Formatter('%(asctime)s|%(message)s',"%Y-%m-%d %H:%M:%S")
    loghandler.setFormatter(logformatter)
    logger.addHandler(loghandler)



    # Create Random Hellow Response class object
    rhr = Random_Hello_Response()

    parser = argparse.ArgumentParser(add_help=False)
    parser.add_argument(
        "-l", "--list-devices", action="store_true",
        help="show list of audio devices and exit")
    args, remaining = parser.parse_known_args()
    if args.list_devices:
        print(sd.query_devices())
        parser.exit(0)
    parser = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter,
        parents=[parser])
    parser.add_argument(
        "-f", "--filename", type=str, metavar="FILENAME",
        help="audio file to store recording to")
    parser.add_argument(
        "-d", "--device", type=int_or_str,
        help="input device (numeric ID or substring)")
    parser.add_argument(
        "-r", "--samplerate", type=int, help="sampling rate")
    parser.add_argument(
        "-m", "--model", type=str, help="language model; e.g. en-us, fr, nl; default is en-us")
    args = parser.parse_args(remaining)

    try:
        if args.samplerate is None:
            device_info = sd.query_devices(args.device, "input")
            # soundfile expects an int, sounddevice provides a float:
            args.samplerate = int(device_info["default_samplerate"])
            
        if args.model is None:
            # model = Model(lang="en-us")
            model = Model(MODEL_PATH)
        else:
            model = Model(lang=args.model)

        if args.filename:
            dump_fn = open(args.filename, "wb")
        else:
            dump_fn = None

        with sd.RawInputStream(samplerate=args.samplerate, blocksize = 8000, device=args.device,
                dtype="int16", channels=1, callback=callback):
            print("#" * 80)
            print("Press Ctrl+C to stop the recording")
            print("#" * 80)

            rec = KaldiRecognizer(model, args.samplerate)
            # multi-line grammar string - ensure no comma after "[unk]"
            hi_dave_grammar='''[
                "hey dave", 
                "hello dave", 
                "hi dave", 
                "shalom dave", 
                "good morning dave", 
                "boker tov dave", 
                "good afternoon dave", 
                "good evening dave", 
                "good night dave", 
                "lie la tov dave", 
                "[unk]"
                ]'''

            rec.SetGrammar(hi_dave_grammar)
            while True:
                data = q.get()
                if rec.AcceptWaveform(data):
                    result=rec.Result()
                    # print(rec.Result())
                    if "hello dave" in result:
                      response=rhr.get_filtered_response()
                      print(response)
                      speak.say(response,anytime=ANYTIME)
                      logger.info("hello dave")
                    elif "hey dave" in result:
                      logger.info("hey dave")
                      response=rhr.get_filtered_response()
                      print(response)
                      speak.say(response,anytime=ANYTIME)
                    elif "hi dave" in result:
                      logger.info("hi dave")
                      response=rhr.get_filtered_response()
                      print(response)
                      speak.say(response,anytime=ANYTIME)
                    elif "shalom dave" in result:
                      logger.info("shalom dave")
                      print("shalom")
                      speak.say("[[sh'ahLohm]]",anytime=ANYTIME)
                      sleep(5)  # prevent feedback
                    elif "good morning dave" in result:
                      logger.info("good morning dave")
                      print("good morning to you")
                      speak.say("good morning to you",anytime=ANYTIME)
                      sleep(5)  # prevent feedback
                    elif "boker tov dave" in result:
                      logger.info("boker tov dave")
                      print("boker tov")
                      speak.say("bokair tov ",anytime=ANYTIME)
                      sleep(5)  # prevent feedback
                    elif "good afternoon dave" in result:
                      logger.info("good afternoon dave")
                      print("good afternoon to you")
                      speak.say("good afternoon to you",anytime=ANYTIME)
                      sleep(5)  # prevent feedback
                    elif "good evening dave" in result:
                      logger.info("good evening dave")
                      print("good evening to you")
                      speak.say("good evening to you",anytime=ANYTIME)
                      sleep(5)   # prevent feedback loop
                    elif "good night dave" in result:
                      logger.info("good night dave")
                      print("good night, I'll be going to sleep now")
                      speak.say("good night, going to sleep now",anytime=True)
                      print("\nExiting test_hello_dave.py")
                      parser.exit(0)
                      exit(0)

                else:
                    partial=rec.PartialResult()

                if dump_fn is not None:
                    dump_fn.write(data)

    except KeyboardInterrupt:
        print("\nDone")
        parser.exit(0)
    except Exception as e:
        parser.exit(type(e).__name__ + ": " + str(e))


if __name__ == "__main__":
    main()
