#ifndef __ALGOS_STACK_H__
#define __ALGOS_STACK_H__

struct stack_node {
	struct stack_node *link;
	int value;
};

struct stack {
	struct stack_node *top;
};

// stack related functions
struct stack *stack_create();
void stack_push(struct stack *stack, int value);
int stack_pop(struct stack *stack);
void stack_destroy(struct stack *stack);
// stack node related functions
struct stack_node *stack_node_create(int value);

#endif // !__ALGOS_STACK_H__
