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

# Input number of repititions
numPlaybackTimes = 0
numPlaybackTimes = input ("How many times do you want to play the sample? ")

# check if input was an integer, if not, repeat input
while str.isdigit(numPlaybackTimes) == False:
    numPlaybackTimes = input ("Heey vriendschap, das geen nummer hè. Doe ekkes gewoon een nummertje nu. ")
else:
    numPlaybackTimes = int(numPlaybackTimes)

# Enter list with note values
note_list = []

for i in range(numPlaybackTimes):
    note_list.append(float(input("Enter note values one by one: ")) * float(bpm))

# Play sound and repeat till numPlaybackTimes = 0 (forLoop)
def playSample(numPlaybackTimes):
    for i in range(numPlaybackTimes):
        print (playSound)
        time.sleep(note_list[i])
    if int(numPlaybackTimes) == 0:
        return print ("finished")

# run playSample
playSample(numPlaybackTimes)
