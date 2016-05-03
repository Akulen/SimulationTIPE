CC=g++
CFLAGS=-Wall -Wextra -std=c++14
#DEPS=

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

all: main.o Kademlia.o Node.o
	$(CC) main.o Kademlia.o Node.o $(CFLAGS) -o Simulation
#
#all: main.o fonctions.o
#        gcc main.o fonctions.o -o Simulation
# 
#main.o: main.c fonctions.h
#        gcc -c main.c -o main.o
# 
#fonctions.o: fonctions.c
#        gcc -c fonctions.c -o fonctions.o
# 
clean:
	rm -rf *.o
 
#mrproper: clean
#        rm -rf Simulation
#
