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

INFILE = H:/ISCHEMIA/Git_Repositories/personal/DSMC_HTML_Generator/test/test_inputs/test_input.txt
OUTFILE = H:/ISCHEMIA/Git_Repositories/personal/DSMC_HTML_Generator/test/test_outputs/test_output.html

all: 
	rm -rf $(EXE)
	rm -rf test/test_outputs/*
	$(CC) $(CFLAGS) $(MODULES) $(MAIN) -o $(EXE)

clean:
	rm -rf $(EXE)
	rm -rf test/test_outputs/*

compile_and_test:
	rm -rf $(EXE) test/test_outputs/*
	$(CC) $(CFLAGS) $(INCLUDE) $(LIB_DIR) $(MAIN) $(MODULES) $(LIBS) -o $(EXE)
	./$(EXE) test/test_inputs/test_input.txt test/test_outputs/test_output.html
