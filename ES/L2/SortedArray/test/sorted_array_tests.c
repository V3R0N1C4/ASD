#include "unity.h"
#include "sorted_array.h"

static SortedArray* array;
static int val1;

static unsigned int precedes_fun(const void* p1el, const void* p2el) {
   int* p1 = (int*) p1el;
   int* p2 = (int*) p2el;
   return (*p1 < *p2) ? 1 : 0;
}

void setUp(void) {
   val1 = -12;
   array = sorted_array_init(10, precedes_fun);
}

void tearDown(void) {
   sorted_array_freemem(array);
}

static void test_sorted_array_is_empty_zero_el(void) {
   TEST_ASSERT_TRUE(sorted_array_is_empty(array));
}

static void test_sorted_array_is_empty_one_el(void) {
   sorted_array_add(array, &val1);
   TEST_ASSERT_FALSE(sorted_array_is_empty(array));
}

int main(void) {
   UNITY_BEGIN();
   RUN_TEST(test_sorted_array_is_empty_zero_el);
   RUN_TEST(test_sorted_array_is_empty_one_el);
   return UNITY_END();
}