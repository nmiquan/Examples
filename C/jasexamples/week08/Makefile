# Makefile for week 08 examples

CC=dcc
BINS=search1 search2 search3 search4 sort1 sort2 sort3 sort4 points fines ex1 ex2 ex3

all : $(BINS)

search1 : search1.o arraylib.o
search2 : search2.o arraylib.o
search3 : search3.o arraylib.o
search4 : search4.o arraylib.o
sort1 : sort1.o arraylib.o
sort2 : sort2.o arraylib.o
sort3 : sort3.o arraylib.o
sort4 : sort4.o arraylib.o
points : points.o
fines : fines.o
ex1 : ex1.o
ex2 : ex2.o
ex3 : ex3.o

arraylib.o : arraylib.c

clean :
	rm -f $(BINS) *.o
