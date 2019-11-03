//Program de teste pentru comenzile vocale. Versiunea finala a fost refacuta in javascript.
import speech_recognition as sr
from gtts import gTTS 
from datetime import datetime
from random import randint
from tkinter import *
import json
import time
import sys
import os
import commands

r = sr.Recognizer()
with sr.Microphone() as source:
    print("Speak Anything :")
    r.dynamic_energy_threshold = False
    audio = r.listen(source, timeout=1.0)
    try:
        text_ro = r.recognize_google(audio, language="ro-RO")

        #text_en = r.recognize_google(audio)
        print("Ai spus : {}".format(text_ro))
        #print("You said : {}".format(text_en))
    except:
        text_ro = "Sorry could not recognize what you said"

command = text_ro.lower()

if command == "cât este ceasul":
    command = commands.getDateTime("hour")

if command == "în cât suntem astăzi":
    command = commands.getDateTime("date")

if command == "închide lumina":
    command = "Am închis lumina"

voce = gTTS(text=command, lang="ro", slow=False) 
voce.save("command.mp3") 
os.system("afplay command.mp3")


