// queue.h ... interface to Queue ADT

typedef struct queue *queue_t;

// create a new queue
queue_t queue_create(void);
// free a queue
void queue_free(queue_t queue);
// add new item to queue
void queue_enqueue(queue_t queue, int item);
// remove next item from queue and return it
int queue_dequeue(queue_t queue);
// return true if queue is empty
int queue_is_empty(queue_t queue);
// return next item from queue but don't remove it
int queue_front(queue_t queue);
// return number elements in queue
int queue_size(queue_t queue);
// display contents of queue
void queue_show(queue_t queue);
