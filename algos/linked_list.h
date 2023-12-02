#ifndef __ALGOS_LL_H__
#define __ALGOS_LL_H__
struct ll_node {
	int value;
	struct ll_node *next;
	struct ll_node *prev;
};

struct ll_node *ll_node_create(int value);
struct ll_node *ll_node_get(struct ll_node *root, int index);
void ll_node_insert_after(struct ll_node *p, int value);
void ll_node_push(struct ll_node *root, int value);
void ll_node_print(struct ll_node *n);
void ll_node_remove(struct ll_node *node, int index);
void ll_node_destroy(struct ll_node *n);
#endif // !__ALGOS_LL_H__
