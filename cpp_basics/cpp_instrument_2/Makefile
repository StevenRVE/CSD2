CXX=g++
CXXFLAGS=-Wall -std=c++14
LDFLAGS=
SOURCE= instrument.o leadSynth.o bassSynth.o main.o

example: $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $<
clean:
	rm -f example *.o

# inst_test : instrument.o instrument_main.o
# 				g++ -o inst_test instrument.o instrument_main.o
#
# instrument.o : instrument.cpp instrument.h
# 				g++ -c instrument.cpp
#
# main.o : main.cpp instrument.h
# 				g++ -c instrument_main.cpp
#
# clean:
# 				rm -f *.o inst_test
