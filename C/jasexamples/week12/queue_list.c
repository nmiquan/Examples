// queue_list.c ... implementation of Queue ADT
// - uses a linked list representation
// Written by jas@cse

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// Data structure representation of Queue

typedef struct node node_t;

struct node {
    int    data;    // value in Node
    node_t *next;   // link to next Node
};

struct queue {
    node_t *first;  // pointer to first node
    node_t *last;   // pointer to last node
    int size;       // number of nodes
};

// Implementation of operations on Queue

// print a message and give up
static
void fatal(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(EXIT_FAILURE);
}

// create a new node
node_t *node_create(int value, node_t *next)
{
    node_t *new;
    new = malloc(sizeof (node_t));
    if (new == NULL) fatal("Out of memory");
    new->data = value;
    new->next = next;
    return new;
}

// create a new queue
queue_t queue_create(void)
{
    struct queue *new;
    new = malloc(sizeof (struct queue));
    if (new == NULL) fatal("Out of memory");
    new->size = 0;
    new->first = new->last = NULL;
    return new;
}

// free a queue
void queue_free(queue_t queue)
{
	// TODO
}

// add new item to queue
void queue_enqueue(queue_t queue, int item)
{
	node_t *new, *curr;
	new = node_create(item, NULL);
	if (queue->size == 0) {
	    queue->first = queue->last = new;
	} else {
	    curr = queue->first;
	    while (curr->next != NULL)
	        curr = curr->next;
	    curr->next = new;
	    queue->last = new;
	}
	queue->size++;
}

// remove next item from queue and return it
int queue_dequeue(queue_t queue)
{
	node_t *old;
	old = queue->first;
	queue->first = old->next;
	queue->size--;
	if (queue->size == 0) queue->last = NULL;
	int val = old->data;
	free(old);
	return val;
}

// return true if queue is empty
int queue_is_empty(queue_t queue)
{
	return (queue->size == 0);
}

// return next item from queue but don't remove it
int queue_front(queue_t queue)
{
	if (queue->size == 0) 
	    fatal("No front in empty queue");
	return queue->first->data;
}

// return number elements in queue
int queue_size(queue_t queue)
{
	return queue->size;
}

// display contents of queue
void queue_show(queue_t queue)
{
    node_t *curr;
    
    printf("FIRST{");
    curr = queue->first;
    while (curr != NULL) {
        printf(" %d", curr->data);
        curr = curr->next;
    }
    printf(" }TAIL");
}

