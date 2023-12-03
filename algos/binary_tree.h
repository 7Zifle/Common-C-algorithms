#ifndef __ALGOS_BINARY_TREE_H__
#define __ALGOS_BINARY_TREE_H__

#include "vector.h"

struct bt_node {
	int value;
	struct bt_node *left;
	struct bt_node *right;
};
struct bt_node *create_bt_node(int value);
struct bt_node *bt_insert(struct bt_node *node, int value);
void bt_destroy(struct bt_node *node);
void bt_inorder_to_array(struct bt_node *node, struct vector *result_v);
void bt_preorder_to_array(struct bt_node *node, struct vector *result_v);
void bt_postorder_to_array(struct bt_node *node, struct vector *result_v);
#endif // !___ALGOS_BINARY_TREE_H__
