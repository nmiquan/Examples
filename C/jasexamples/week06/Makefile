# Makefile for week 05 examples

CC=dcc
BINS=echo add s2i strings1 strings2 \
     fgets1 fgets2 fgets3 snap0 snap1 snap2 \
     cat copy grep wc1 wc2
     

all : $(BINS)

echo : echo.o
add : add.o johnslib.o
s2i : s2i.o

strings1: strings1.o
strings2: strings2.o johnslib.o

fgets1 : fgets1.o
fgets2 : fgets2.o
fgets3 : fgets3.o

snap1 : snap1.o
snap2 : snap2.o
snap3 : snap3.o

cat : cat.o
copy : copy.o
grep : grep.o
wc1 : wc1.o
wc2 : wc2.o

johnslib.o : johnslib.c

clean :
	rm -f $(BINS) *.o
