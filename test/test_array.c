#include "array.h"
#include "unity.h"

void setUp(void) {}

void tearDown(void) {
  // clean stuff up here
}

void test_array_insert(void) {
  int array[5] = {0};

  int arrayactual[5] = {3, 2, 9, 4, 2};
  insert(array, 5, 2, 0);
  insert(array, 5, 3, 0);
  insert(array, 5, 9, 2);
  insert(array, 5, 2, 3);
  insert(array, 5, 4, 3);
  TEST_ASSERT_EQUAL_INT_ARRAY(array, arrayactual, 5);
}

void test_array_delete(void){
  int array[5] = {3, 2, 9, 4, 2};

  delete(array, 5, 0);
  int arrayactual1[5] = {2, 9, 4, 2, 2};

  TEST_ASSERT_EQUAL_INT_ARRAY(array, arrayactual1, 5);

  delete(array, 5, 0);
  int arrayactual2[5] = {9, 4, 2, 2, 2};

  TEST_ASSERT_EQUAL_INT_ARRAY(array, arrayactual2, 5);
  
  delete(array, 5, 0);
  int arrayactual3[5] = {4, 2, 2, 2, 2};

  TEST_ASSERT_EQUAL_INT_ARRAY(array, arrayactual3, 5);
  
  delete(array, 5, 0);
  int arrayactual4[5] = {2, 2, 2, 2, 2};

  TEST_ASSERT_EQUAL_INT_ARRAY(array, arrayactual4, 5);

  delete(array, 5, 0);

  int arrayactual5[5] = {2, 2, 2, 2, 2};
  TEST_ASSERT_EQUAL_INT_ARRAY(array, arrayactual5, 5);
}

void test_array_sum(void){
    int array[5] = {1,2,3,4,5};
    TEST_ASSERT_EQUAL_INT(sum(array, 5), 15);
}

void test_array_find(void){
    int array[5] = {3,6,5,9,21};

    TEST_ASSERT_EQUAL_INT(find(array,5,9), 3);
}

void test_array_extend(void){
    int array[5] = {3,6,5,9,21};
    int array_ex[10] = {3,6,5,9,21,0,0,0,0,0};
    TEST_ASSERT_EQUAL_INT_ARRAY(extend(array,5,5), array_ex, 10);
}

int main(int argc, char *argv[]) {
  UNITY_BEGIN();
  RUN_TEST(test_array_insert);
  RUN_TEST(test_array_delete);
  RUN_TEST(test_array_sum);
  RUN_TEST(test_array_find);
  RUN_TEST(test_array_extend);
  return UNITY_END();
}
