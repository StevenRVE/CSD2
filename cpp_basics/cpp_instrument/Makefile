
inst_test : instrument.o instrument_main.o
				g++ -o inst_test instrument.o instrument_main.o

instrument.o : instrument.cpp instrument.h
				g++ -c instrument.cpp

instrument_main.o : instrument_main.cpp instrument.h
				g++ -c instrument_main.cpp

clean:
				rm -f *.o inst_test
