#import simpleaudio as sa

#wave_obj = sa.WaveObject.from_wave_file("BMR_Splash_1.wav")
#play_obj = wave_obj.play()
playSound = "dong"

numPlaybackTimes = int(input ("How many times do you want to play the sample? "))
list = []

#play_obj.wait_done()

# Add noteLength to each note
for i in range(numPlaybackTimes):
    noteLength = float(input ("Add duration in miliseconds "))
    print(i,":", noteLength)
    if i == (numPlaybackTimes-1):
        print ("That was the last one! ")
        bpm = 60000 / (int(input ("What is the bpm? ")))
        print ("bpm in miliseconds: ", bpm)

# Multiply noteLength with bpm




def playSample(numPlaybackTimes):
    if int(numPlaybackTimes) == 0:
        return print ("finished")
    else:
        print (playSound)
        return playSample(numPlaybackTimes-1)

# playSample(numPlaybackTimes)
