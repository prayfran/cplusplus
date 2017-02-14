
CXXFLAGS=-Wall -Wextra -ansi -pedantic

a.out: main.o ll.o 
	g++ main.o ll.o

main.o: main.cc

ll.o: ll.cc ll.h
	
clean:
	-rm *.o
	-rm a.out
