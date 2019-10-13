import random
import simpleaudio as sa
import sys
import threading as th
import time


# Define instrument
samples = [sa.WaveObject.from_wave_file("samples/16_bit/Hihat.wav"),
            sa.WaveObject.from_wave_file("samples/16_bit/Kick.wav"),
            sa.WaveObject.from_wave_file("samples/16_bit/Snare.wav")]

# Program title
print("_____/<<<<<<<<<<<<<<<<<<<<|>>>>>>>>>>>>>>>>>>>\_____")
print("<<<<<<<<<<<<<<<<<<<< BeatMeister >>>>>>>>>>>>>>>>>>>")
print("\u203e\u203e\u203e\u203e\u203e\\<<<<<<<<<<<<<<<<<<<<|>>>>>>>>>>>>>>>>>>>/\u203e\u203e\u203e\u203e\u203e")

time.sleep(0.25)

# # program introduction and instruction
# print("""....................... Index ......................
# Notevalues:
# 4 = whole note;
# 2 = half note;
# 1 = quarter note;
# 0.5 = eight note;
# 0.25 = sixteenth note;
# etc, etc, etc.
#
# Actual values are based on the BPM.
#
# While playing press [Enter] to finish the sequence and stop playing
# """)

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
         except ValueError:
             print("Wrong value. Try again: ")
         except NameError:
             print("That\"s not a number. Try again: ")
         except TypeError:
             print("I need a whole number please. Try again: ")
         except Exception as e:
             print("Something went wrong. ",e)
             print("Try again: ")
         else:
             bpmCorrect = True
             print("Thanks! The bpm is now: " + str(bpm))

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
            ask_BPM()
            return valid[choice]
        else:
            sys.stdout.write("Please respond with 'yes' or 'no' "
                             "(or 'y' or 'n').\n")

change_BPM_yes_no("Do you want to use the default BPM? ", bpmCorrect)

# convert bpm to notelengths in seconds
quarterNoteDuration = 60 / bpm
sixteenthNoteDuration = quarterNoteDuration / 4.0

# create a list to hold the timestamps
timestamps = []

# # Import list with note values from inputList.txt
# noteList = [line.rstrip("\r\n") for line in open("inputList.txt")]
#
# # Convert strings in list to float
# noteList = list(map(float,noteList))
#
# # Input number of repititions
# numPlaybackTimes = len(noteList)

# create a list with "note timestamps" specified as 16th notes, indicating
# the time at which the sample must be played
# timestamps16th = [0,3,4,6,9,10,13,15]
timestamps16th = [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]

# transform the sixteenthTimestamps to a timestamps list with time values
for timestamp in timestamps16th:
  timestamps.append(timestamp * sixteenthNoteDuration)

dictList = []

# create dictionarys from timestamps and add random samples
for stamp in timestamps:
    stamp = {"timestamp": stamp, "instrument": random.randint(0, 2)}
    dictList.append(stamp)

# copy dictList into new list for later re-copy
dictListBank = dictList.copy()

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
             bpm = (float(input ("How many times must I play the loop? ")))
         except ValueError:
             print("Wrong value. Try again: ")
         except NameError:
             print("That\"s not a number. Try again: ")
         except TypeError:
             print("I need a whole number please. Try again: ")
         except Exception as e:
             print("Something went wrong. ",e)
             print("Try again: ")
         else:
             loopTimesCorrect = True
             print("Thanks! I'm gonna play it " + str(bpm) + "times.")


# Check if user wants to use preset bpm or input own bpm
def change_loopTimes_yes_no(question, loopTimesCorrect, default="yes"):
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
            print("The default loop number is %d" % loopTimes)
            return valid[default]
        elif (choice in valid) == True:
            ask_loopTimes()
            return valid[choice]
        else:
            sys.stdout.write("Please respond with 'yes' or 'no' "
                             "(or 'y' or 'n').\n")

change_loopTimes_yes_no("Do you want to use the default loop number? ", loopTimesCorrect)

def playSequence():
    for i in range(loopTimes):
        global loopedTimes
        global dictList

        # retrieve the startime: current time
        startTime = time.time()

        # get a random value to be used as sample index
        randomIndex = random.randint(0, 2)

        # The total duration of 1 sequence
        totalSequenceTime = (60/bpm) * 4

        dictionary = dictList.pop(0)
        timestamp = dictionary["timestamp"]
        sample = dictionary["instrument"]

        # play the sequence
        while True:
            # retrieve current time
            currentTime = time.time()

            # check whether the current time is beyond the timestamp"s time,
            # meaning it is time to play the sample
            if((currentTime - startTime) % totalSequenceTime >= timestamp):
                samples[sample].play()

                # if there are timestamps left in the timestamps list
                if dictList:
                    # retrieve the next timestamp
                    dictionary = dictList.pop(0)
                    timestamp = dictionary["timestamp"]
                    sample = dictionary["instrument"]
                else:
                    # copy the dictionary from the bank
                    dictList = dictListBank.copy()
                    # reset startTime
                    startTime = time.time()
                    print("Sequence done. ")
                    time.sleep(sixteenthNoteDuration)
                    break

            else:
                # short wait to prevent we"ll keep the processor busy when there"s
                # nothing to do
                time.sleep(0.001)

playSequence()

# # run playSample
# keep_going = True
#
# def key_capture_thread():
#     global keep_going
#     input()
#     keep_going = False
#
# def run_PlaySequence():
#     th.Thread(target=key_capture_thread, args=(), name="key_capture_thread", daemon=True).start()
#     while keep_going:
#         playSequence(startTime, timestamp)
#
# run_PlaySequence()

# Closing comment
print("_____/<<<<<<<<<<<<<<<<<<<<|>>>>>>>>>>>>>>>>>>>\_____")
print("<<<<<<<<<<<<<<<<<<<< BeatMeister >>>>>>>>>>>>>>>>>>>")
print("\u203e\u203e\u203e\u203e\u203e\\<<<<<<<<<<<<<<<<<<<<|>>>>>>>>>>>>>>>>>>>/\u203e\u203e\u203e\u203e\u203e")
