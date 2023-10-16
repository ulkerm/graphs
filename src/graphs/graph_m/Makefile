PROGRAM = graph
ARGUMENTS =

CC = gcc
CFLAGS = -pedantic -Wall -Wextra -Wvla -std=c99 -ggdb3

LD = gcc
LDFLAGS = -lm

CFILES = $(wildcard *.c)
OFILES = $(CFILES:.c=.o)
DEPENDFILE = .depend

all: depend $(PROGRAM)

$(PROGRAM): $(OFILES)
	$(LD) -o $@ $(OFILES) $(LDFLAGS)

.PHONY: clean run debug depend

clean:
	rm -f $(OFILES) $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM) $(ARGUMENTS)

debug: $(PROGRAM)
	gdb $(PROGRAM) $(ARGUMENTS)

depend:
	$(CC) $(CCFLAGS) -MM $(CFILES) > $(DEPENDFILE)

-include $(DEPENDFILE)