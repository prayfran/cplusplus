
CXXFLAGS=-g -O3 -std=c++11 -Wall -Wextra -pedantic -Wctor-dtor-privacy -Werror -Wfatal-errors -Winit-self -Wshadow -Wlogical-op -Wcomment -pedantic -Wctor-dtor-privacy $$(pkg-config --cflags gtkmm-3.0)
CC = /usr/bin/g++


all: hangman


hangman: Hangman.h Hangman.cc
	clear;$(CC) $(CXXFLAGS) -o $@ Hangman.cc `pkg-config gtkmm-3.0 --cflags --libs`


clean:
	-rm -f hangman *.o *.gch *~ hangman hangman.tar

tar:
	tar -cvf hangman.tar *
