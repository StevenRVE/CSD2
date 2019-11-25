import simpleaudio as sa
import time
import threading as th

# Define instrument
hihat = sa.WaveObject.from_wave_file("samples/16_bit/Hihat.wav")
kick = sa.WaveObject.from_wave_file("samples/16_bit/Kick.wav")
snare = sa.WaveObject.from_wave_file("samples/16_bit/Snare.wav")



# timestamps16th = [0,1,4,5,7,11,14,15]
timestamps16th = [ts for ts in range(16)] # fill every position
quarterNoteDuration = 500
sixteenthNoteDuration = quarterNoteDuration/4


"""
timeZero=1000*time.time(); # get time in milliseconds
# events are popped from the list at each iteration, even when the previous
# ones haven't been dealt with
# We need a mechanism that observes an event and only moves on to the next
# event when the current one has been handled
for ts in timestamps16th:
  now=time.time()*1000
  # check whether it's time for the next event
  if now-timeZero >= ts*sixteenthNoteDuration:
    print(ts)
    play_obj = snare.play()
  else:
    time.sleep(0.001)
"""


timeZero=1000*time.time(); # get time in milliseconds

if timestamps16th: # if events in list
  ts=timestamps16th.pop(0) # take event from the start of the list
else:
  exit() # nothing to be done


while True:
  now=time.time()*1000
  if now-timeZero >= ts*sixteenthNoteDuration:
    print(ts)
    play_obj = snare.play()
    if timestamps16th: # if events left in list
      ts=timestamps16th.pop(0)
    else:
      break # if no events left, break from the loop
  else:
    # if time for event hasn't come,
    #   wait a short while before checking again
    #   so as not to keep the processor busy doing nothing
    time.sleep(0.001)


#
# let the last one ring out
#
play_obj.wait_done()
