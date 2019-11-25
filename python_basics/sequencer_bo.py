import simpleaudio as sa
import time
import random

state = ("init")
answer = ("x")

if state == ("init"):
    # set default bpm
    bpm = 120
    del answer

    print("Welcome to Multi Sample Sequencer!")
    print("The current bpm is " + str(bpm) + ".")
    print("Would you like to change the bpm?")
    answer = input("Answer yes or no ->" + " ")
    if answer == ("yes"):
        bpm = input("What bpm would you like the sequence to be played at? ")
        try:
            val = int(bpm) # Check if the entered bpm value can be converted to integer
            bpm = int(bpm) # Converts bpm to integer

            if bpm < 1: # if the enetered value is a negative number
                print("That's not a valid answer, I'm looking for a positive number.")
                time.sleep(1)
                print("Returning to initial state")
                time.sleep(1)
                state = ("init")
            else:
                print("Bpm set at " + str(bpm) + ("."))
                time.sleep(1)
                state = ("play")
        except ValueError: # If eneter value isn't an integer
            print("That's not a valid answer, I'm looking for a number.")
            time.sleep(1)
            print("Returning to initial state")
            state = ("init")
    if answer == ("no"):
        state = ("play")
    # else:
    #     print("That's not the answer I was looking for... asdfasdf")
    #     time.sleep(1)
    #     print("Returning to initial state")
    #     time.sleep(1)
    #     state = ("init")

if state == ("play"):
    # loads 2 audioFiles and store it into a list
    pop = sa.WaveObject.from_wave_file("samples/16_bit/Hihat.wav")
    laser = sa.WaveObject.from_wave_file("samples/16_bit/Kick.wav")
    samples = [pop, laser]

    quarterNoteDuration = 60 / bpm
    # calculate the duration of a sixteenth note
    sixteenthNoteDuration = quarterNoteDuration / 4.0

    # create a list to hold the timestamps
    timestamps = []

    # create a list with 'note timestamps' specified as 16th notes, indicating
    # the time at which the sample must be played
    timestamps16th = [0, 4, 8, 12]

    # transform the sixteenthTimestamps to a timestamps list with time values
    for timestamp in timestamps16th:
      timestamps.append(timestamp * sixteenthNoteDuration)

    # creates a list to hold dictionarys
    dictList = []

    # converts timestamps into dictionarys and adding information
    for stamp in timestamps:
        stamp = {'timestamp': stamp, 'instrument': random.randint(0, 1)}
        dictList.append(stamp)

    # copys timestamps into a new list
    dictListBank = dictList.copy()

    loopAmount = 2

    for i in range(loopAmount):
        # pops the first dictionary off the list
        # pops the timestamp and payload out of the dictionary
        dictionary = dictList.pop(0)
        timestamp = dictionary['timestamp']
        sample = dictionary['instrument']

        startTime = time.time()
        # play the sequence
        while True:
          # retrieve current time
          currentTime = time.time()

          # check whether the current time is beyond the timestamp's time,
          # meaning it is time to play the sample
          if(currentTime - startTime >= timestamp):
            samples[sample].play()
            print(timestamp)

            # if there are timestamps left in the timestamps list
            if dictList:
              # retrieve the next payload
              dictionary = dictList.pop(0)
              timestamp = dictionary['timestamp']
              sample = dictionary['instrument']
            else:
              # replenishes the timestamps list
              dictList = list.copy(dictListBank)
              time.sleep(quarterNoteDuration)
              # list is empty, stop the loop
              break

          else:
            # short wait to prevent we'll keep the processor busy when there's
            # nothing to do
            time.sleep(0.001)

        time.sleep(0.1)
