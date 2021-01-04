CXX=g++
CXXFLAGS=-Wall -std=c++14
LDFLAGS= -ljack
SOURCE= synthesizer.o oscillator.o sine.o square.o saw.o jack_module.o melodyGenerator.o main.o

synth: $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $<

clean:
	rm -f synth *.o
