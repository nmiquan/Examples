typedef struct stack *stack_t;

stack_t stack_create(void);
void stack_free(stack_t stack);
void stack_push(stack_t stack, int item);
int stack_pop(stack_t stack);
int stack_is_empty(stack_t stack);
int stack_top(stack_t stack);
int stack_size(stack_t stack);
