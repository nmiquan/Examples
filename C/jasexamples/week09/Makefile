# Makefile for week 09 examples

CC=dcc
BINS=llist list0

all : $(BINS)

llist : llist.o lists.o
llist.o : llist.c lists.h
lists.o : lists.c lists.h

list0 : list0.c
	dcc -o list0 list0.c

clean :
	rm -f $(BINS) *.o
