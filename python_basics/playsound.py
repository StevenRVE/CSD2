#import simpleaudio as sa

#wave_obj = sa.WaveObject.from_wave_file("BMR_Splash_1.wav")
#play_obj = wave_obj.play()

amount = int(input ("How many times do you want to play the sample? "))

#play_obj.wait_done()

playSound = "dong"

def playSample(amount):
    if int(amount) == 0:
        return print ("finished")
    else:
        print (playSound)
        return playSample(amount-1)

playSample(amount)
