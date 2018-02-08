// linked list functions
// Written by andrewt@cse
// Modified by jas@cse

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//typedef struct node struct node;

struct node {
    int          data;  // value in this node
    struct node *next;  // link to next node
};

/*
 * return 1 iff list contains no elements, 0 otherwise
 */
int is_empty(struct node *list)
{
    if (list == NULL)
        return 1;
    else
        return 0;
        
    // return (list == NULL);
}

/*
 * create a struct node and place the specified values in the fields
 */
struct node *create_node(int val, struct node *ptr)
{

    // input:
    //     value of the node being created
    //     a pointer to type node

    // output:
    //     pointer to the new node being created

    struct node *new; // define a pointer to node typ
    
    new = malloc(sizeof(struct node)); // allocate memory for the newly created pointer
    if (new == NULL) {
        fprintf(stderr, "out of memory\n");
        exit(EXIT_FAILURE);
    }
    new->data = val;
    new->next = ptr; // next node of new node is the input pointer
    return new;
}

/*
 * insert integer at front of list
 */
struct node *insert(int value, struct node *list)
{

// input:
//     pointer to the beginning of the list
//     the value being added

// output:
//     pointer to the new node

    struct node *new = create_node(value, list);
    return new;
}

/*
 * return pointer to first node in list
 * NULL is returned if list is empty
 */

struct node *first(struct node *list)
{

    // This function only points to the element at the give pointer
    return list;
}

/*
 * return pointer to last node in list
 * NULL is returned if list is empty
 */
struct node *last(struct node *list)
{
    if (list == NULL) {
        return NULL;
    }
    struct node *curr = list;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    return curr;
}

/*
 * append integer to end of list
 */
struct node *append(int value, struct node *list)
{
    if (list == NULL) return insert(value, list);
    
    struct node *curr;
    curr = list;
    // scan to last node
    while (curr->next != NULL) {
        curr = curr->next;
    }
    struct node *new = create_node(value, NULL);
    curr->next = new;
    return list;
/*
    if (curr == NULL)
        // curr == NULL
        // list was originally empty
        return insert(value, list);
    else {
        // curr != NULL && curr->next == NULL
        // list had at least one struct node
        struct node *new = create_node(value, NULL);
        curr->next = new;
        return list;
    }
**/   
}

/*
 * print contents of list Python syntax
 * e.g: [11, 12, 13, 42, 24]
 */
void print_list(struct node *list)
{
    struct node *curr;
    curr = list;
    printf("[");
    while (curr != NULL) {
        printf("%d", curr->data);
        if (curr->next != NULL) printf(", ");
        curr = curr->next;
    }
    printf("]");
}

/*
 * return number of nodes in list
 */
int length(struct node *list)
{
    struct node *curr;
    int counter = 0;
    
    for (curr = list; curr != NULL; curr = curr->next)
         counter++;
         
    /*
    curr = list;
    while (curr != NULL) {
        counter++;
        curr = curr->next;
    }
    */
         
    return counter;
}

/*
 * return cumulative sum of data in nodes in list
 */
int sum(struct node *list)
{
    return 42; // REPLACE ME
}

/*
 * return pointer to nth node in list, counting from 0
 */
struct node *nth(int index, struct node *list)
{
    if (list == NULL) return list;
    struct node *curr = list;
    for (int i = 0; i < index; i++) {
         if (curr == NULL) return NULL;
         curr = curr->next;
    }
    return curr;
}

/*
 * return pointer to middle node in list
 */
struct node *middle(struct node *list)
{
    if (list == NULL) return list;
    int mid = length(list)/2;
    return nth(mid, list);
}

/*
 * return 1 iff the list is in non-descending order, 0 otherwise
 */
int is_ascending(struct node *list)
{
    struct node *curr;
    
    // if (length(list) < 2)
    if (list == NULL || list->next == NULL)
        return 1;
    curr = list;
    while (curr->next != NULL) {
        if (curr->next->data < curr->data)
            return 0;
        curr = curr->next;
    }
    return 1;
}

/*
 * test the above functions
 */
int main(int argc, char *argv[])
{
    struct node *list = NULL;
    struct node *node = NULL;
    int number;

    printf("Enter a number: ");
    while (scanf("%d", &number) == 1) {
        list =  append(number, list);
        printf("Enter a number: ");
    }
    if (is_empty(list)) {
        printf("List is empty.\n");
        return 0;
    }

    printf("\nList entered was: ");
    print_list(list);

    node = first(list);
    printf("\nFirst element in list is: %d.\n", 
           node->data);

    node = last(list);
    printf("Last element in list is: %d.\n", 
           node->data);

    printf("Middle element in list is: %d.\n", 
           middle(list)->data);

    printf("Length of list is: %d.\n", length(list));

    printf("Sum of the list is: %d.\n", sum(list));

    if (is_ascending(list)) {
        printf("List is in ascending order.\n");
    } else {
        printf("List is not in ascending order.\n");
    }
    return 0;
}

