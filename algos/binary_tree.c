#include "binary_tree.h"
#include <stdlib.h>
#include <stdio.h>

struct bt_node *create_bt_node(int value) {
	struct bt_node *node = malloc(sizeof(struct bt_node));
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

struct bt_node *bt_insert(struct bt_node *node, int value) {
	if (node == NULL) {
		return create_bt_node(value);
	}
	if (value > node->value) { // target right
		node->right = bt_insert(node->right, value);
	} else if (value < node->value) { // target left
		node->left = bt_insert(node->left, value);
	}

	return node;
}

void bt_destroy(struct bt_node *node) {
	if (node == NULL) {
		return;
	}

	if (node->left != NULL) {
		bt_destroy(node->left);
	}
	if (node->right != NULL) {
		bt_destroy(node->right);
	}

	free(node);
}

void bt_inorder_to_array(struct bt_node *node, struct vector *v_result) {
	if (node == NULL) {
		return;
	}
	bt_inorder_to_array(node->left, v_result);
	vector_push(v_result, node->value);
	bt_inorder_to_array(node->right, v_result);
}

void bt_preorder_to_array(struct bt_node *node, struct vector *v_result) {
	if (node == NULL) {
		return;
	}
	vector_push(v_result, node->value);
	bt_preorder_to_array(node->left, v_result);
	bt_preorder_to_array(node->right, v_result);
}

void bt_postorder_to_array(struct bt_node *node, struct vector *v_result) {
	if (node == NULL) {
		return;
	}
	bt_postorder_to_array(node->left, v_result);
	bt_postorder_to_array(node->right, v_result);
	vector_push(v_result, node->value);
}
