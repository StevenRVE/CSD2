from midiutil.MidiFile import MIDIFile
import random
import simpleaudio as sa
import sys
import threading as th
import time as tm
import math

# Define instrument
samples = [sa.WaveObject.from_wave_file("samples/16_bit/Hihat.wav"),
            sa.WaveObject.from_wave_file("samples/16_bit/Kick.wav"),
            sa.WaveObject.from_wave_file("samples/16_bit/Snare.wav")]

# Program title
print("_____/<<<<<<<<<<<<<<<<<<<<|>>>>>>>>>>>>>>>>>>>\_____")
print("<<<<<<<<<<<<<<<<<<<< BietMeister >>>>>>>>>>>>>>>>>>>")
print("\u203e\u203e\u203e\u203e\u203e\\<<<<<<<<<<<<<<<<<<<<|>>>>>>>>>>>>>>>>>>>/\u203e\u203e\u203e\u203e\u203e")

tm.sleep(0.5)

# program introduction and instruction
print("""
             Welcome to the BietMachine!

""")

tm.sleep(1)

print(""" ___________________________________________________
|.................. Instructions ..................|
|                                                  |
|You can choose to use default settings for the bpm|
|and number of repeats. Or you can take control and|
|enter those settings yourself. If you do, make    |
|sure to enter in numbers like 1, 10, 100, etc.    |
|                                                  |
|                    Have fun!                     |
|__________________________________________________|

""")

tm.sleep(1)

# Input default bpm convert to seconds
bpm = 120

bpmCorrect = False

# input function for bpm
def ask_BPM():
    global bpm
    global bpmCorrect

    while (bpmCorrect == False):
         try:
             bpm = (float(input ("What is the bpm? ")))
             zeroCheck = 1/bpm
         except ValueError:
             print("Wrong value. Try again: ")
         except NameError:
             print("That\"s not a number. Try again: ")
         except TypeError:
             print("I need a whole number please. Try again: ")
         except ZeroDivisionError:
             print("Bpm can't be zero. Try again: ")
         except Exception as e:
             print("Something went wrong. ",e)
             print("Try again: ")
         else:
             if bpm < 0:
                 bpm = bpm * -1
                 print("""I don't think a negative value would be usefull, let me fix that.""")
             bpmCorrect = True
             print("The bpm is now: " + str(bpm))

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
        if default is not None and choice == "":
            print("The default bpm is %d" % bpm)
            return valid[default]
        elif (choice in valid) == True:
            if valid[choice] == True:
                print("The default bpm is %d" % bpm)
                return
            if valid[choice] == False:
                ask_BPM()
                return
        else:
            sys.stdout.write("Please respond with 'yes' or 'no' "
                             "(or 'y' or 'n').\n")

change_BPM_yes_no("Do you want to use the default BPM? ", bpmCorrect)

# convert bpm to notelengths in seconds
quarterNoteDuration = 60 / bpm
sixteenthNoteDuration = quarterNoteDuration / 4.0

# create a list to hold the timestamps
timestamps = []

##### import presets #####
# # Import list with note values from inputList.txt
# noteList = [line.rstrip('\r\n') for line in open('inputList.txt')]
#
# # Convert strings in list to float
# noteList = list(map(float,noteList))

# create a list with "note timestamps" specified as 16th notes, indicating
# the time at which the sample must be played
timestamps16th = [0,3,4,6,9,10,13,15,17]
# timestamps16th = [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17]

# transform the sixteenthTimestamps to a timestamps list with time values
for timestamp in timestamps16th:
  timestamps.append(timestamp * sixteenthNoteDuration)

dictList = []

# create dictionarys from timestamps and add random samples
for stamp in timestamps:
    stamp = {
    "timestamp": stamp,
    "instrument": random.randint(0, 2),
    "chanceHihat": random.randint(0,100),
    "chanceKick": random.randint(0,100),
    "chanceSnare": random.randint(0,100),
    }
    dictList.append(stamp)

# copy dictList into new list for later re-copy
dictListBank = dictList.copy()

# copy dictList into new list for later re-copy
dictionaryMidiBank = dictList.copy()

######################################MIDI######################################
# create your MIDI object
mf = MIDIFile(1)     # only 1 track

# set default values
track    = 0
channel  = 10
time     = 0   # In beats
duration = 1   # In beats
tempo    = bpm  # In BPM
volume   = 100 # 0-127, as per the MIDI standard

time = 0    # start at the beginning
mf.addTrackName(track, time, "Sample Track")
mf.addTempo(track, time, 120)

###################################USER-INPUT###################################

# input the amount of times that the sequence has to be looped
loopTimes = 4
loopedTimes = 0
loopTimesCorrect = False

# input function for loopTimes
def ask_loopTimes():
    global loopTimes
    global loopTimesCorrect

    while (loopTimesCorrect == False):
         try:
             loopTimes = (int(input ("How many times must I play the loop? ")))
             zeroCheck =  1/loopTimes
         except ValueError:
             print("Wrong value. Try again: ")
         except NameError:
             print("That\"s not a number. Try again: ")
         except TypeError:
             print("I need a whole number please. Try again: ")
         except ZeroDivisionError:
             print("Please pick a number higher than zero: ")
         except Exception as e:
             print("Something went wrong. ",e)
             print("Try again: ")
         else:
             if loopTimes < 0:
                 loopTimes = loopTimes * -1
                 print("""I don't think a negative value would be usefull, let me fix that.""")
             loopTimesCorrect = True
             print("I'm gonna play it " + str(loopTimes) + " times.")

# Function for looptimes default or user input
def change_loopTimes_yes_no(question, loopTimesCorrect, default="yes"):
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
        if default is not None and choice == "":
            print("The default loop number is %d" % loopTimes)
            return valid[default]
        elif (choice in valid) == True:
            if valid[choice] == True:
                print("The default loop number is %d" % loopTimes)
                return
            if valid[choice] == False:
                ask_loopTimes()
                return
        else:
            sys.stdout.write("Please respond with 'yes' or 'no' "
                             "(or 'y' or 'n').\n")

# Function for looptimes default or user input
def replay_loop_yes_no(question, default="yes"):
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
        if default is not None and choice == "":
            global keep_going
            keep_going = True
            playSequence()
            return valid[default]
        elif (choice in valid) == True:
            if valid[choice] == True:
                keep_going = True
                playSequence()
                return
            if valid[choice] == False:
                global replay
                replay = False
                return
        else:
            sys.stdout.write("Please respond with 'yes' or 'no' "
                             "(or 'y' or 'n').\n")

# Function for asking to write midi file or not
def writeMidi(question, default="no"):
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
        if default is not None and choice == "":
            return
        elif (choice in valid) == True:
            if valid[choice] == True:
                # write it to disk
                with open("drumloop.mid", 'wb') as output_file:
                    mf.writeFile(output_file)
                    return
            if valid[choice] == False:
                return
        else:
            sys.stdout.write("Please respond with 'yes' or 'no' "
                             "(or 'y' or 'n').\n")

# Check if user wants to use preset loopTimes or input own loopTimes
change_loopTimes_yes_no("Do you want to use the default loop number? ",
loopTimesCorrect)

# make sure the sequence keeps going till number of loops is reached
keep_going = True

# function for playing the sequence
def playSequence():
    for i in range(loopTimes):
        global loopedTimes
        global dictList
        global keep_going

        loopedTimes = loopedTimes + 1
        # retrieve the startime: current time
        startTime = tm.time()

        # get a random value to be used as sample index
        randomIndex = random.randint(0, 2)

        # get information from dictionary
        dictionary = dictList.pop(0)
        timestamp = dictionary["timestamp"]
        sample = dictionary["instrument"]
        chanceHihat = dictionary["chanceHihat"]
        chanceKick = dictionary["chanceKick"]
        chanceSnare = dictionary["chanceSnare"]

        # set chances for kick or snare to be played
        chanceKickNumber = 50
        chanceSnareNumber = 40

        # play the sequence
        while True:
            # retrieve current time
            currentTime = tm.time()

            # check whether the current time is beyond the timestamp"s time,
            # meaning it is time to play the sample
            if((currentTime - startTime)  >= timestamp):
                if timestamp == 0:
                    chanceKickNumber = 85
                if chanceHihat < 70:
                    samples[0].play()
                    mf.addNote(track, channel, 62, timestamp, duration, volume)
                if chanceKick < chanceKickNumber:
                    samples[1].play()
                    mf.addNote(track, channel, 60, timestamp, duration, volume)
                if chanceSnare < chanceSnareNumber:
                    samples[2].play()
                    mf.addNote(track, channel, 64, timestamp, duration, volume)

                # if there are timestamps left in the timestamps list
                if dictList:
                    # retrieve the next timestamp
                    dictionary = dictList.pop(0)
                    timestamp = dictionary["timestamp"]
                    sample = dictionary["instrument"]
                    chanceHihat = dictionary["chanceHihat"]
                    chanceKick = dictionary["chanceKick"]
                    chanceSnare = dictionary["chanceSnare"]
                else:
                    # copy the dictionary from the bank
                    dictList = dictListBank.copy()
                    # reset startTime
                    startTime = tm.time()
                    print("Sequence done. ")
                    tm.sleep(sixteenthNoteDuration)
                    break

            else:
                # short wait to prevent we"ll keep the processor busy when
                # there's nothing to do
                tm.sleep(0.001)

    if (loopedTimes - loopTimes == 0):
        keep_going = False

# play the sequence
playSequence()

#############################POST-PLAYING-FUNCTIONS#############################

# Ask if midi file should be written
writeMidi("Do you want to save this beat as a MIDIfile?")

# while loop for replaying the same sequence
replay = True

while replay == True:
    replay_loop_yes_no("Do you want to replay the loop? ")

# Closing comment
print("_____/<<<<<<<<<<<<<<<<<<<<|>>>>>>>>>>>>>>>>>>>\_____")
print("<<<<<<<<<<<<<<<<<<<< bietMeister >>>>>>>>>>>>>>>>>>>")
print("\u203e\u203e\u203e\u203e\u203e\\<<<<<<<<<<<<<<<<<<<<|>>>>>>>>>>>>>>>>>>>/\u203e\u203e\u203e\u203e\u203e")
