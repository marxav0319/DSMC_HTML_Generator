#
# Use this makefile to compile the program. 
#
# Author: Mark Xavier
#

CC = g++ -std=c++11
CFLAGS = -g -O3 -Wall
MAIN = src/main.cpp
MODULES = src/modules/src/*.cpp
EXE = bin/HTML_Generator

all: 
	rm -rf bin
	mkdir bin
	$(CC) $(CFLAGS) $(MAIN) $(MODULES) -o $(EXE)

clean:
	rm -rf bin test/test_outputs

compile_and_test:
	rm -rf bin test/test_outputs
	mkdir bin test/test_outputs
	$(CC) $(CFLAGS) $(MAIN) $(MODULES) -o $(EXE)
	./$(EXE) test/test_inputs/test_input.txt test/test_outputs/test_output.html
