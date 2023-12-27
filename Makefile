ifeq ($(OS),Windows_NT)
	SHELL = cmd
	RM = del
	CP = copy
	EXT=.exe
	BIN = $(USERPROFILE)\bin
else
	BIN = $(HOME)/bin
endif

CC=gcc
CFLAGS = -Wall -g

TARGETS = simple leaky random batch

ifdef EXT
	TARGETS := $(addsuffix .exe, $(TARGETS))
endif

default: $(TARGETS)

# Windows
simple.exe: simple.c allocator_win.o
	$(CC) $(CFLAGS) -o $@ $^ -ldl

leaky.exe: leakyalloc.c allocator_win.o
	$(CC) $(CFLAGS) -o $@ $^ -ldl

allocator_win.o: allocator.c
	$(CC) $(CFLAGS) -c allocator.c -o allocator_win.o

random.exe: randomalloc.c allocator_win.o
	$(CC) $(CFLAGS) -o $@ $^ -ldl

batch.exe: batchalloc.c allocator_win.o
	$(CC) $(CFLAGS) -o $@ $^ -ldl

# Linux
simple: simple.c allocator.o
	$(CC) $(CFLAGS) -o $@ $^
leaky: leakyalloc.c allocator.o
	$(CC) $(CFLAGS) -o $@ $^
batch: batchalloc.c allocator.o
	$(CC) $(CFLAGS) -o $@ $^
random: randomalloc.c allocator.o
	$(CC) $(CFLAGS) -o $@ $^

allocator.o: allocator.c
	$(CC) $(CFLAGS) -c allocator.c


.PHONY: clean

clean:
	$(RM) $(TARGETS)
	$(RM) *.o *.exe allocs.log a.out
