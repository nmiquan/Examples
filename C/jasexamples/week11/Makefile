# Makefile for week 09 examples

CC=dcc
CFLAGS=-g
BINS=q1 q2

all : $(BINS)

q1 : que.o queue_array.o
	$(CC) -o q1 que.o queue_array.o
q2 : que.o queue_list.o
	$(CC) -o q2 que.o queue_list.o

que.o : que.c queue.h
queue_array.o : queue_array.c queue.h
queue_list.o : queue_list.c queue.h

clean :
	rm -f $(BINS) *.o
