#include "stack.h"
#include <stdlib.h>

struct stack *stack_create()
{
	struct stack *stack = malloc(sizeof(struct stack));
	stack->top = NULL;
	return stack;
}
void stack_push(struct stack *stack, int value)
{
	struct stack_node *node = stack_node_create(value);
	
	node->link = stack->top;
	stack->top = node;
}

int stack_pop(struct stack *stack)
{
	int return_value = stack->top->value;
	struct stack_node *tmp = stack->top;

	stack->top = stack->top->link;
	free(tmp);
	return return_value;
}

static void stack_node_destroy_tree(struct stack_node *node) {
	if (node != NULL) {
		stack_node_destroy_tree(node->link);
		free(node);
	}
}

void stack_destroy(struct stack *stack)
{
	stack_node_destroy_tree(stack->top);
	free(stack);
}

struct stack_node *stack_node_create(int value)
{
	struct stack_node *node = malloc(sizeof(struct stack_node));

	node->value = value;

	return node;
}

