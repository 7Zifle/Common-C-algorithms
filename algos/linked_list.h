#ifndef __ALGOS_LL_H__
#define __ALGOS_LL_H__
struct node {
	int value;
	struct node *next;
	struct node *prev;
};

struct node *node_create(int value);
struct node *node_get(struct node *root, int index);
void node_insert_after(struct node *p, int value);
void node_push(struct node *root, int value);
void node_print(struct node *n);
void node_remove(struct node *node, int index);
void node_destroy(struct node *n);
#endif // !__ALGOS_LL_H__
