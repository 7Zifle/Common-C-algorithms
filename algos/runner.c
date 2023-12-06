#include "CUnit/CUnit.h"
#include "CUnit/CUnitCI.h"

#include "binary_tree.h"
#include "queue.h"
#include "quicksort.h"
#include "linked_list.h"
#include "array_util.h"
#include "stack.h"
#include "vector.h"

static void test_quicksort()
{
	int array[] = { 9, 3, 7, 4, 69, 420, 42 };
	quicksort(array, 0, 7 - 1);
	int correct_array[] = { 3, 4, 7, 9, 42, 69, 420 };

	CU_ASSERT_EQUAL(arrcmp(array, correct_array, 7), 0);
}

static void test_linked_list()
{
	struct ll_node *root = ll_node_create(420);
	ll_node_push(root, 69);
	ll_node_push(root, 87);
	CU_ASSERT_EQUAL(root->value, 420);
	CU_ASSERT_EQUAL(ll_node_get(root, 2)->value, 87);
	ll_node_insert_after(ll_node_get(root, 1), 1337);
	CU_ASSERT_EQUAL(ll_node_get(root, 2)->value, 1337);
	ll_node_remove(root, 2);
	CU_ASSERT_EQUAL(ll_node_get(root, 1)->value, 69);
	CU_ASSERT_EQUAL(ll_node_get(root, 2)->value, 87);
	ll_node_destroy(root);
}

static void test_vector()
{
	struct vector *v = create_vector(1);
	vector_push(v, 1);
	vector_push(v, 1);
	vector_push(v, 1);
	vector_push(v, 2);
	vector_push(v, 2);
	vector_push(v, 3);
	CU_ASSERT_EQUAL(v->data[v->lenth - 1], 3);
	CU_ASSERT_EQUAL(v->capacity, 8);
	vector_destroy(v);
}

static void test_binary_search_tree()
{
	struct bt_node *root = create_bt_node(1);
	bt_insert(root, 2);
	bt_insert(root, 3);
	bt_insert(root, 0);
	bt_insert(root, 7);
	bt_insert(root, 8);
	bt_insert(root, 12);

	int correct_in[] = { 0, 1, 2, 3, 7, 8, 12 };
	struct vector *vinorder_result = create_vector(7);
	bt_inorder_to_array(root, vinorder_result);
	CU_ASSERT_EQUAL(arrcmp(vinorder_result->data, correct_in, 7), 0);
	vector_destroy(vinorder_result);

	int correct_pre[] = { 1, 0, 2, 3, 7, 8, 12 };
	struct vector *vpreorder_result = create_vector(7);
	bt_preorder_to_array(root, vpreorder_result);
	CU_ASSERT_EQUAL(arrcmp(vpreorder_result->data, correct_pre, 7), 0);
	vector_destroy(vpreorder_result);

	int correct_post[] = { 0, 12, 8, 7, 3, 2, 1 };
	struct vector *vpostorder_result = create_vector(7);
	bt_postorder_to_array(root, vpostorder_result);
	CU_ASSERT_EQUAL(arrcmp(vpostorder_result->data, correct_post, 7), 0);
	vector_destroy(vpostorder_result);

	bt_destroy(root);
}

static void test_queue()
{
	struct queue *queue = queue_create();
	queue_push(queue, 12);
	queue_push(queue, 1);
	queue_push(queue, 19);

	CU_ASSERT_EQUAL(queue_pop(queue), 12);
	CU_ASSERT_EQUAL(queue_pop(queue), 1);
	CU_ASSERT_EQUAL(queue_pop(queue), 19);

	queue_push(queue, 17);
	CU_ASSERT_EQUAL(queue_pop(queue), 17);

	queue_destroy(queue);
}

static void test_stack()
{
	struct stack *stack = stack_create();
	stack_push(stack, 9);
	stack_push(stack, 12);
	stack_push(stack, 15);
	stack_push(stack, 3);

	CU_ASSERT_EQUAL(stack_pop(stack), 3);
	CU_ASSERT_EQUAL(stack_pop(stack), 15);
	CU_ASSERT_EQUAL(stack_pop(stack), 12);
	CU_ASSERT_EQUAL(stack_pop(stack), 9);

	stack_destroy(stack);
}

CUNIT_CI_RUN("algos", CUNIT_CI_TEST(test_quicksort),
	     CUNIT_CI_TEST(test_linked_list), CUNIT_CI_TEST(test_vector),
	     CUNIT_CI_TEST(test_stack), CUNIT_CI_TEST(test_queue),
	     CUNIT_CI_TEST(test_binary_search_tree));
