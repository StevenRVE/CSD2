CXX=g++
CXXFLAGS=-Wall -std=c++14
LDFLAGS=-ljack
SOURCE=pet.o main.o

example: $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $<

clean:
	rm -f example *.o
