// llist.c ... manipulate linked lists
// Written by jas@cse, April 2017

#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

void printHelp();

// main program reads/executes list commands

int main(void)
{
    struct node *list; // linked list
    char line[BUFSIZ]; // input line buffer
    char cmd;          // current command
    int  val;          // value for current command
    int  nargs;        // # args for command
    int  changed;      // did last cmd change list?

    // create empty list
    list = NULL;

    // read/execute commands
    printf("> ");
    while (fgets(line, BUFSIZ, stdin) != NULL) {
        changed = 0;
        nargs = sscanf(line, "%c %d", &cmd, &val);
        if (cmd == 'a' && nargs == 2) {
            list = append(val, list);
            changed = 1;
        }
        else if (cmd == 'i' && nargs == 2) {
            list = insert(val, list);
            changed = 1;
        }
        else if (cmd == 'd' && nargs == 2) {
            list = delete(val, list);
            changed = 1;
        }
        else if (cmd == '?' && nargs == 2) {
            if (search(val, list)) {
                printf("Found\n");
            } else {
                printf("Not found\n");
            }
        }
        else if (cmd == 's') {
            if (is_sorted(list)) {
                printf("Sorted\n");
            } else {
                printf("Not sorted\n");
            }
        }
        else if (cmd == '#') {
            printf("Length = %d\n", length(list));
        }
        else if (cmd == 'f') {
            free_list(list);
            list = NULL;
            changed = 1;
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
            printf("List");
            show_list(list);
        }
        printf("> ");
    }
    free_list(list);
    printf("\n");
    return EXIT_SUCCESS;
}

void printHelp()
{
     printf("Possible commands:\n");
     printf("i N ... insert N at start of list\n");
     printf("a N ... append N at end of list\n");
     printf("d N ... delete N from list\n");
     printf("? N ... check whether N in list\n");
     printf("#   ... show length of list\n");
     printf("s   ... check whether list is sorted\n");
     printf("p   ... show current list\n");
     printf("f   ... free current list\n");
     printf("q   ... quit the program\n");
}
