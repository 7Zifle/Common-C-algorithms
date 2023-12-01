#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

struct node *node_create(int value)
{
	struct node *n = (struct node *)malloc(sizeof(struct node));
	n->value = value;
	n->next = NULL;
	n->prev = NULL;
	return n;
}

struct node *node_get(struct node *node, int index)
{
	for (int count = 0; node && count < index; node = node->next, count++) {
	}
	return node;
}

void node_insert_after(struct node *p, int value)
{
	struct node *c = node_create(value);
	c->prev = p;
	if (p->next) {
		printf("called");
		p->next->prev = c;
		c->next = p->next;
	}
	p->next = c;
}

void node_push(struct node *root, int value)
{
	struct node *head = root;
	while (head->next) {
		head = head->next;
	}
	node_insert_after(head, value);
}

void node_print(struct node *n)
{
	printf("list: [");
	while (n) {
		printf("%d, ", n->value);
		n = n->next;
	}
	printf("]");
}

void node_remove(struct node *node, int index)
{
	for (int count = 0; node && count < index; node = node->next, count++)
		;
	if (node->prev) {
		if (node->next) {
			node->prev->next = node->next;
			node->next->prev = node->prev;
		} else {
			node->prev->next = NULL;
		}
	} else {
		if (node->next) {
			node->next->prev = NULL;
		}
	}
	free(node);
}

void node_destroy(struct node *n)
{
	if (n->next != NULL) {
		node_destroy(n->next);
	}

	free(n);
}
