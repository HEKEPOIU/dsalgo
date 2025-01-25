#include "unity.h"
#include <Util.h>
#include <list.h>

void setUp(void) {}

void tearDown(void) {}

void test_new_list(void) {
  List_Int *list = new_list();

  TEST_ASSERT_EQUAL_size_t(list->capacity, 10);
  TEST_ASSERT_EQUAL_size_t(list->size, 0);
  TEST_ASSERT_EQUAL_size_t(list->extend_ratio, 2);
}

void test_push_list(void) {
  List_Int *list = new_list();
  push_list(list, 3);
  push_list(list, 2);
  push_list(list, 1);
  int actual_arr[3] = {3, 2, 1};
  TEST_ASSERT_EQUAL_INT_ARRAY(list->arr, actual_arr, 3);
  TEST_ASSERT_EQUAL_INT(list->size, 3);
}

void test_get_list(void) {
  List_Int *list = new_list();
  push_list(list, 3);
  push_list(list, 2);
  push_list(list, 1);
  TEST_ASSERT_EQUAL_INT(get_list(list, 2), 1);
  TEST_ASSERT_EQUAL_INT(get_list(list, 1), 2);
  TEST_ASSERT_EQUAL_INT(get_list(list, 0), 3);
}

void test_set_list(void) {
  List_Int *list = new_list();
  push_list(list, 3);
  push_list(list, 2);
  push_list(list, 1);
  set_list(list, 1, 5);
  int actual_arr[3] = {3, 5, 1};
  TEST_ASSERT_EQUAL_INT_ARRAY(list->arr, actual_arr, 3);
}

void test_insert_list(void) {
  List_Int *list = new_list();
  push_list(list, 3);
  push_list(list, 2);
  push_list(list, 1);
  insert_list(list, 1, 5);
  int actual_arr[4] = {3, 5, 2, 1};
  TEST_ASSERT_EQUAL_INT_ARRAY(list->arr, actual_arr, 4);
}

void test_remove_list(void) {
  List_Int *list = new_list();
  push_list(list, 3);
  push_list(list, 2);
  push_list(list, 1);
  remove_list(list, 1);
  int actual_arr[2] = {3, 1};
  TEST_ASSERT_EQUAL_INT_ARRAY(list->arr, actual_arr, 2);
}

void test_extend_list(void) {
  List_Int *list = new_list();
  push_list(list, 3);
  push_list(list, 2);
  push_list(list, 1);
  push_list(list, 1);
  push_list(list, 1);

  push_list(list, 1);
  push_list(list, 1);
  push_list(list, 1);
  push_list(list, 1);
  push_list(list, 1);

  push_list(list, 1);
  int actual_arr[11] = {3, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  TEST_ASSERT_EQUAL_INT_ARRAY(list->arr, actual_arr, 11);
  TEST_ASSERT_EQUAL_INT(list->capacity, 20);
}

int main(int argc, char *argv[]) {
  UNITY_BEGIN();
  RUN_TEST(test_new_list);
  RUN_TEST(test_push_list);
  RUN_TEST(test_get_list);
  RUN_TEST(test_set_list);
  RUN_TEST(test_remove_list);
  RUN_TEST(test_insert_list);
  RUN_TEST(test_extend_list);
  return UNITY_END();
}
