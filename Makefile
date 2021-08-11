SHELL=/bin/sh
.SUFFIXES:
.SUFFIXES: .c .o
CC=gcc
VPATH=src

OBJFILES = build/ppgen.o build/functions.o

all: ppgen

functions.o: functions.h functions.c ; $(CC) -c -o build/functions.o src/functions.c

ppgen.o: ppgen.c functions.h ; $(CC) -c -o build/ppgen.o src/ppgen.c

ppgen: ppgen.o functions.o ; $(CC) -o build/ppgen $(OBJFILES)

clean: ; rm -f $(OBJFILES) build/ppgen

.PHONY: all clean
