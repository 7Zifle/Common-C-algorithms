#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

struct ll_node *ll_node_create(int value)
{
	struct ll_node *n = (struct ll_node *)malloc(sizeof(struct ll_node));
	n->value = value;
	n->next = NULL;
	n->prev = NULL;
	return n;
}

struct ll_node *ll_node_get(struct ll_node *node, int index)
{
	for (int count = 0; node && count < index; node = node->next, count++) {
	}
	return node;
}

void ll_node_insert_after(struct ll_node *p, int value)
{
	struct ll_node *c = ll_node_create(value);
	c->prev = p;
	if (p->next) {
		p->next->prev = c;
		c->next = p->next;
	}
	p->next = c;
}

void ll_node_push(struct ll_node *root, int value)
{
	struct ll_node *head = root;
	while (head->next) {
		head = head->next;
	}
	ll_node_insert_after(head, value);
}

void ll_node_print(struct ll_node *n)
{
	printf("list: [");
	while (n) {
		printf("%d, ", n->value);
		n = n->next;
	}
	printf("]");
}

void ll_node_remove(struct ll_node *node, int index)
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

void ll_node_destroy(struct ll_node *n)
{
	if (n->next != NULL) {
		ll_node_destroy(n->next);
	}

	free(n);
}
