// que.c ... manipulate queues
// Written by jas@cse, May 2017

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

void printHelp();

// main program reads/executes queue commands

int main(void)
{
    queue_t queue;     // the Queue
    char line[BUFSIZ]; // input line buffer
    char cmd;          // current command
    int  val;          // value for current command
    int  nargs;        // # args for command
    int  changed;      // did last cmd change queue?

    // create empty queue
    queue = queue_create();

    // read/execute commands
    printf("Queues 1.0\n");
    printf("> ");
    while (fgets(line, BUFSIZ, stdin) != NULL) {
        changed = 0;
        nargs = sscanf(line, "%c %d", &cmd, &val);
        if (cmd == '+' && nargs == 2) {
            queue_enqueue(queue, val);
            changed = 1;
        }
        else if (cmd == '-') {
            if (queue_is_empty(queue)) {
                printf("Can't pop\n");
            } else {
                val = queue_dequeue(queue);
                printf("Popped %d\n", val);
                changed = 1;
            }
        } 
        else if (cmd == 't') {
            val = queue_front(queue);
            printf("Top is %d\n", val);
            changed = 0;
        }

        else if (cmd == '?') {
            if (queue_is_empty(queue)) {
                printf("Empty\n");
            } else {
                printf("Not empty\n");
            }
        }
        else if (cmd == '#') {
            printf("Size is %d\n", queue_size(queue));
        }
        else if (cmd == 'd') {
            queue_free(queue);
            //queue = queue_create();
        }
        else if (cmd == 'p') {
            changed = 1;
        }
        else if (cmd == 'q') {
            break;
        }
        else {
            printf("Invalid command!\n");
            printHelp();
        }
        if (changed) {
            queue_show(queue);
            printf("\n");
        }
        printf("> ");
    }
    queue_free(queue);
    printf("\n");
    return EXIT_SUCCESS;
}

void printHelp()
{
     printf("Possible commands:\n");
     printf("+ N ... push N onto queue\n");
     printf("-   ... pop top element\n");
     printf("t   ... show top element\n");
     printf("?   ... check whether queue is empty\n");
     printf("#   ... show height of queue\n");
     printf("p   ... show current queue\n");
     printf("d   ... destroy current queue\n");
     printf("q   ... quit the program\n");
}
