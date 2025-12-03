CC = gcc
FLAGS = -Wall

LATEXFLAG = 0
VALGRIND = 1

ifeq ($(LATEXFLAG), 1)
	FLAGS += -DLATEX_OUT
endif

ifeq ($(VALGRIND), 1)
	FLAGS += -g
endif

pqSieve: pqSieve.c pqSieve.h eratosthenes.o
	$(CC) $(FLAGS) eratosthenes.o $@.c -o pqSieve -lm

pkSieve: pkSieve.c pkSieve.h eratosthenes.o
	$(CC) $(FLAGS) eratosthenes.o $@.c -o pkSieve -lm

eratosthenes.o: eratosthenes.c eratosthenes.h
	$(CC) $(FLAGS) -c $(*F).c

.PHONY clean:
	rm -f $(OBFILES)
