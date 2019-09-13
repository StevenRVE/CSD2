# import simpleaudio as sa
import time


# wave_obj = sa.WaveObject.from_wave_file("BMR_Splash_1.wav")
# play_obj = wave_obj.play()
playSound = "dong"

# play_obj.wait_done()

# Program title
print("<<<<<<<<<<<<<<<<<<<< BeatMachine >>>>>>>>>>>>>>>>>>>")

time.sleep(1)

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
bpm = 60 / (float(input ("What is the bpm? ")))

# Import list with note values from inputList.txt
noteList = [line.rstrip('\r\n') for line in open('inputList.txt')]

# Convert strings in list to float
noteList = list(map(float,noteList))

# Input number of repititions
numPlaybackTimes = len(noteList)

# check if input was an integer, if not, repeat input
# while str.isdigit(numPlaybackTimes) == False:
#     numPlaybackTimes = input ("Heey vriendschap, das geen nummer hè. Doe ekkes gewoon een nummertje nu. ")
# else:
#     numPlaybackTimes = int(numPlaybackTimes)

# Play sound and repeat till numPlaybackTimes = 0 (forLoop)
def playSample(numPlaybackTimes):
    for i in range(numPlaybackTimes):
        print (playSound)
        time.sleep(noteList[i]*bpm)
    if int(numPlaybackTimes) == 0:
        print ("finished")

# run playSample
playSample(numPlaybackTimes)
