# Says hello to someone

import pyttsx3

engine = pyttsx3.init()
name = input("What's your name? ")
engine.say(f"hello, {name}")
engine.runAndWait()
#-------------------------------------
# Says "This was CS50"

import pyttsx3

engine = pyttsx3.init()
engine.say("This was CS50")
engine.runAndWait()