CXX=g++
CXXFLAGS=-Wall -std=c++14
LDFLAGS=-ljack
SOURCE=instrument.o main.o

synth: $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $<
clean:
	rm -f synth *.o
