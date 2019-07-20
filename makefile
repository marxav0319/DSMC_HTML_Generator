#
# To do...
#
# Author: Mark Xavier
#

CC = g++ -std=c++11
CFLAGS = -g -O2
MAIN = src/main.cpp
MODULES = src/modules/src/*.cpp

all: 
	mkdir bin
	$(CC) $(CFLAGS) -o bin/DSMC_HTML_Generator $(MAIN) $(MODULES)

clean:
	rm -rf bin