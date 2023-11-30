#include "CUnit/CUnit.h"
#include "CUnit/CUnitCI.h"

#include "quicksort.h"
#include "array_util.h"

static void test_quicksort() {
    int array[] = {9, 3, 7, 4, 69, 420, 42};
    quicksort(array, 0, 7 - 1);
    int correct_array[] = {3, 4, 7, 9, 42, 69, 420};

    CU_ASSERT_EQUAL(arrcmp(array, correct_array, 7), 0);
}

CUNIT_CI_RUN("algos", CUNIT_CI_TEST(test_quicksort));
