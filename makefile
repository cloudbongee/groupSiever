CC = gcc
FLAGS = -Wall

LATEXFLAG = 0
VALGRIND = 1
BRUTEFORCE_VERBOSE = 0

GROUPS = 167

ifeq ($(LATEXFLAG), 1)
	FLAGS += -DLATEX_OUT
endif

ifeq ($(VALGRIND), 1)
	FLAGS += -g
endif

ifeq ($(BRUTEFORCE_VERBOSE), 0)
	FLAGS += -DSUPRESS_VERBOSE
endif

all:
	make pqSieve
	make pkSieve
	make nSieve
	make indexSieve
	make indexSieveBruteForce
	make indexSieveSylow
	make twoOddSieve
	make remaining
	make remainingList

remainingList: pqSieve pkSieve nSieve twoOddSieve remaining
	./pqSieve $(GROUPS) > list
	./pkSieve $(GROUPS) >> list
	./nSieve  $(GROUPS) >> list
	./twoOddSieve $(GROUPS) >> list
	./remaining $(GROUPS) list > remainingList
	rm list

pqSieve: pqSieve.c pqSieve.h eratosthenes.o eratosthenes.h
	$(CC) $(FLAGS) eratosthenes.o pqSieve.c -o pqSieve -lm

pkSieve: pkSieve.c pkSieve.h eratosthenes.o eratosthenes.h
	$(CC) $(FLAGS) eratosthenes.o pkSieve.c -o pkSieve -lm

nSieve: extendedEratosthenes.o eratosthenes.o nSieve.c nSieve.h
	$(CC) $(FLAGS) eratosthenes.o extendedEratosthenes.o nSieve.c -o nSieve -lm

indexSieve: indexSieve.c indexSieve.h
	$(CC) $(FLAGS) indexSieve.c -o indexSieve -lm

indexSieveBruteForce: indexSieveBruteForce.c indexSieveBruteForce.h
	$(CC) $(FLAGS) indexSieveBruteForce.c -o indexSieveBruteForce -lm

indexSieveSylow: indexSieveSylow.c indexSieveSylow.h eratosthenes.o
	$(CC) $(FLAGS) eratosthenes.o indexSieveSylow.c -o indexSieveSylow -lm

twoOddSieve: twoOddSieve.c twoOddSieve.h
	$(CC) $(FLAGS) twoOddSieve.c -o twoOddSieve

eratosthenes.o: eratosthenes.c eratosthenes.h
	$(CC) $(FLAGS) -c eratosthenes.c

extendedEratosthenes.o: extendedEratosthenes.c eratosthenes.h
	$(CC) $(FLAGS) -c extendedEratosthenes.c

remaining: remaining.c eratosthenes.o extendedEratosthenes.o eratosthenes.h
	$(CC) $(FLAGS) eratosthenes.o extendedEratosthenes.o remaining.c -o remaining



.PHONY clean:
	rm -f $(OBFILES)
