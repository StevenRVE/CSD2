# import simpleaudio as sa
import time
import threading as th

# wave_obj = sa.WaveObject.from_wave_file("BMR_Splash_1.wav")
# play_obj = wave_obj.play()
playSound = "dong"

# play_obj.wait_done()

# Program title
print("_____/<<<<<<<<<<<<<<<<<<<<|>>>>>>>>>>>>>>>>>>>\_____")
print("<<<<<<<<<<<<<<<<<<<< BeatMachine >>>>>>>>>>>>>>>>>>>")
print("\u203e\u203e\u203e\u203e\u203e\\<<<<<<<<<<<<<<<<<<<<|>>>>>>>>>>>>>>>>>>>/\u203e\u203e\u203e\u203e\u203e")

time.sleep(0.5)

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
""")

# Input bpm and convert to seconds
bpmCorrect = False

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

# Import list with note values from inputList.txt
noteList = [line.rstrip('\r\n') for line in open('inputList.txt')]

# Convert strings in list to float
noteList = list(map(float,noteList))

# Input number of repititions
numPlaybackTimes = len(noteList)

# Play sound and repeat till numPlaybackTimes = 0 (forLoop)
def playSample(numPlaybackTimes):
    for i in range(numPlaybackTimes):
        print (playSound)
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

run_PlaySample()

# Closing comment
print("_____/<<<<<<<<<<<<<<<<<<<<|>>>>>>>>>>>>>>>>>>>\_____")
print("<<<<<<<<<<<<<<<<<<<< BeatMachine >>>>>>>>>>>>>>>>>>>")
print("\u203e\u203e\u203e\u203e\u203e\\<<<<<<<<<<<<<<<<<<<<|>>>>>>>>>>>>>>>>>>>/\u203e\u203e\u203e\u203e\u203e")
