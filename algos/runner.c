#include "CUnit/CUnit.h"
#include "CUnit/CUnitCI.h"

#include "quicksort.h"
#include "linked_list.h"
#include "array_util.h"

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

CUNIT_CI_RUN("algos", CUNIT_CI_TEST(test_quicksort),
	     CUNIT_CI_TEST(test_linked_list));
