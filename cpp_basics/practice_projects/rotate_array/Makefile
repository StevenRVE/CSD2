CXX=g++
CXXFLAGS=-Wall -std=c++14
LDFLAGS= -ljack
SOURCE= main.o

rotate_array: $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $<

clean:
	rm -f rotate_array *.o
