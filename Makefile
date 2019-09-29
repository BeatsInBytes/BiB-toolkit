.PHONY: all

CC = g++
compiled = bin/bib
BINDIR = bin

all: compile

compile:
	@${CC} -std=c++11 src/main.cpp src/kern.cpp -o ${compiled}