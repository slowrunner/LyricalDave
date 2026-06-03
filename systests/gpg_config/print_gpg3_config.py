#!/usr/bin/env  python3

import sys
import json

homedir='/home/ubuntu'

def getgpg3_config(dataname=None):
    try:
        with open(homedir + '/.gpg3_config.json', 'r') as infile:
            print("file:",infile)
            lgpg3_config = json.load(infile)
            print("lgpg3_config:",lgpg3_config)
            if (dataname == None):
                return lgpg3_config
            else:
                return lgpg3_config[dataname]
    except Exception as e:
        print("   getgpg3_config() exception:", e)
        return None

def printgpg3_config():
    print(homedir + "/.gpg3_config.json contents:")
    lgpg3_config = getgpg3_config()
    for i in lgpg3_config:
        print("  ",i," : ",lgpg3_config[i])

printgpg3_config()
