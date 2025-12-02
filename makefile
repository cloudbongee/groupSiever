CC = gcc
FLAGS = -Wall -lm
SRCDIR = ./
NAMES = main
FILENAMES = $(addprefix $(SRCDIR), $(NAMES))
OBFILES = $(addsuffix .o,$(FILENAMES))
SRCFILES = $(addsuffix .c, $(FILENAMES))

LATEXFLAG = 1
VALGRIND = 1

ifeq ($(LATEXFLAG), 1)
	FLAGS += -DLATEX_OUT
endif

ifeq ($(VALGRIND), 1)
	FLAGS += -g
endif

pqSieve: main.c main.h
	$(CC) $(FLAGS) main.c -o pqSieve

.PHONY clean:
	rm -f $(OBFILES)
