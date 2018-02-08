# Makefile for week 05 examples

CC=dcc
BINS=add2a add2b sum sum1 matrx \
     cat nlc chr \
     rocks1 rocks2 rocks3 strings1 strings2 \
     fgets1 fgets2

all : $(BINS)

add2a : add2a.o johnslib.o
add2a.o : add2a.c

add2b : add2b.o johnslib.o
add2b.o : add2b.c

sum : sum.o arrays.o johnslib.o
sum.o : sum.c

sum1 : sum1.o arrays.o johnslib.o
sum1.o : sum1.c

matrx : matrx.o matrices.o johnslib.o
matrx.o : matrx.c

cat : cat.o
cat.o : cat.c

nlc : nlc.o
nlc.o : nlc.c

chr : chr.o
chr.o : chr.c

rocks1 : rocks1.c
rocks2 : rocks2.c
rocks3 : rocks3.c

fgets1 : fgets1.c
fgets2 : fgets2.c

strings1: strings1.c

strings2: strings2.o johnslib.o
strings2.o : strings2.c

johnslib.o : johnslib.c
arrays.o : arrays.c
matrices.o : matrices.c

clean :
	rm -f $(BINS) *.o
