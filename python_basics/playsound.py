# import simpleaudio as sa
import time


# wave_obj = sa.WaveObject.from_wave_file("BMR_Splash_1.wav")
# play_obj = wave_obj.play()
playSound = "dong"

# play_obj.wait_done()

# Program title
print("<<<<<<<<<<<<<<<<<<<< BeatMachine >>>>>>>>>>>>>>>>>>>")

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
playSample(numPlaybackTimes)

# Closing comment
print("<<<<<<<<<<<<<<<<<<<< BeatMachine >>>>>>>>>>>>>>>>>>>")
