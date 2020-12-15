
osc_test : oscillator.o oscillator_main.o
				g++ -o osc_test oscillator.o oscillator_main.o

oscillator.o : oscillator.cpp oscillator.h
				g++ -c oscillator.cpp

oscillator_main.o : oscillator_main.cpp oscillator.h
				g++ -c oscillator_main.cpp

clean:
				rm -f *.o osc_test
