import simpleaudio as sa
import time
import threading as th
import random
import sys

# Define instrument
Hihat = sa.WaveObject.from_wave_file("samples/16_bit/Hihat.wav")
Kick = sa.WaveObject.from_wave_file("samples/16_bit/Kick.wav")
Snare = sa.WaveObject.from_wave_file("samples/16_bit/Snare.wav")

# Program title
print("_____/<<<<<<<<<<<<<<<<<<<<|>>>>>>>>>>>>>>>>>>>\_____")
print("<<<<<<<<<<<<<<<<<<<< BeatMeister >>>>>>>>>>>>>>>>>>>")
print("\u203e\u203e\u203e\u203e\u203e\\<<<<<<<<<<<<<<<<<<<<|>>>>>>>>>>>>>>>>>>>/\u203e\u203e\u203e\u203e\u203e")

time.sleep(0.25)

# program introduction and instruction
print("""....................... Index ......................
Notevalues:
4 = whole note;
2 = half note;
1 = quarter note;
0.5 = eight note;
0.25 = sixteenth note;
etc, etc, etc.

Actual values are based on the BPM.

While playing press [Enter] to finish the sequence and stop playing
""")

# Input default bpm convert to seconds
bpm = 120

bpmCorrect = False

# input function for bpm
def ask_BPM(bpmCorrect):
    while (bpmCorrect == False):
         try:
             bpm = 60 / (float(input ("What is the bpm? ")))
         except ValueError:
             print("Wrong value. Try again: ")
         except NameError:
             print("That\'s not a number. Try again: ")
         except TypeError:
             print("I need a whole number please. Try again: ")
         except Exception as e:
             print("Something went wrong. ",e)
             print("Try again: ")
         else:
             bpmCorrect = True
             print("Thanks!")

# Check if user wants to use preset bpm or input own bpm
def change_BPM_yes_no(question, bpmCorrect, default="yes"):
    """Ask a yes/no question via input() and return their answer.

    "question" is a string that is presented to the user.
    "default" is the presumed answer if the user just hits <Enter>.
        It must be "yes" (the default), "no" or None (meaning
        an answer is required of the user).

    The "answer" return value is True for "yes" or False for "no".
    """
    valid = {"yes": True, "y": True, "ye": True,
             "no": False, "n": False}
    if default is None:
        prompt = " [y/n] "
    elif default == "yes":
        prompt = " [Y/n] "
    elif default == "no":
        prompt = " [y/N] "
    else:
        raise ValueError("invalid default answer: '%s'" % default)

    while True:
        sys.stdout.write(question + prompt)
        choice = input().lower()
        if default is not None and choice == '':
            return valid[default]
        elif (choice in valid) == True:
            return valid[choice]
        else:
            sys.stdout.write("Please respond with 'yes' or 'no' "
                             "(or 'y' or 'n').\n")

change_BPM_yes_no("Do you want to use the default BPM? ", bpmCorrect)
print(bpm)

# convert bpm to notelengths in seconds
quarterNoteDuration = 60 / bpm
sixteenthNoteDuration = quarterNoteDuration / 4.0

# create a list to hold the timestamps
timestamps = []

# Import list with note values from inputList.txt
noteList = [line.rstrip('\r\n') for line in open('inputList.txt')]

# Convert strings in list to float
noteList = list(map(float,noteList))

# Input number of repititions
numPlaybackTimes = len(noteList)

# Play sound and repeat till numPlaybackTimes = 0 (forLoop)
def playSample(numPlaybackTimes):
    for i in range(numPlaybackTimes):
        play_obj = wave_obj.play()
        time.sleep(noteList[i]*bpm)
    if int(numPlaybackTimes) == 0:
        print ("finished")

# run playSample
keep_going = True

def key_capture_thread():
    global keep_going
    input()
    keep_going = False

def run_PlaySample():
    th.Thread(target=key_capture_thread, args=(), name='key_capture_thread', daemon=True).start()
    while keep_going:
        playSample(numPlaybackTimes)

# run_PlaySample()

# Closing comment
print("_____/<<<<<<<<<<<<<<<<<<<<|>>>>>>>>>>>>>>>>>>>\_____")
print("<<<<<<<<<<<<<<<<<<<< BeatMeister >>>>>>>>>>>>>>>>>>>")
print("\u203e\u203e\u203e\u203e\u203e\\<<<<<<<<<<<<<<<<<<<<|>>>>>>>>>>>>>>>>>>>/\u203e\u203e\u203e\u203e\u203e")
