#include <stdio.h>
#include <stdlib.h>

int main(void) {
    queue_t q;
    q = queue_create();
    queue_enqueue(q, 10);
    queue_enqueue(q, 11);
    queue_enqueue(q, 12);
    printf("%d\n", queue_size(q)); // prints 3
    printf("%d\n", queue_front(q)); // prints 10
    printf("%d\n", queue_dequeue(q)); // prints 10
    printf("%d\n", queue_dequeue(q)); // prints 11
    printf("%d\n", queue_dequeue(q)); // prints 12
    return 0;
}
