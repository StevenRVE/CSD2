#! /bin/bash

g++ -c oscillator.cpp
g++ -c oscillator_main.cpp
g++ -o osc_test oscillator.o oscillator_main.o
