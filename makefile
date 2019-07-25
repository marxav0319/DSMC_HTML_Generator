#
# Use this makefile to compile the program. 
#
# Author: Mark Xavier
#

CC = g++ -std=c++11
CFLAGS = -g -O2
MAIN = src/main.cpp
MODULES = src/modules/src/*.cpp

all: 
	rm -rf bin
	mkdir bin
	$(CC) $(CFLAGS) -o bin/DSMC_HTML_Generator $(MAIN) $(MODULES)

clean:
	rm -rf bin test/test_outputs

compile_and_test:
	rm -rf bin test/test_outputs
	mkdir bin test/test_outputs
	$(CC) $(CFLAGS) -o bin/DSMC_HTML_Generator $(MAIN) $(MODULES)
	./bin/DSMC_HTML_Generator test/test_inputs/test_input.txt test/test_outputs/test_output.html
