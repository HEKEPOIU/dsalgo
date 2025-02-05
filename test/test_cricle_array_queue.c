#include <cricle_array_queue.h>

#include "unity.h"

void setUp(void) {}

void tearDown(void) {}

void test_cricle_array_queue(void) {
  CA_Queue* queue = new_ca_queue(5);
  TEST_ASSERT_EQUAL_size_t(5, queue->que_capaciay);
  TEST_ASSERT_EQUAL_size_t(0, queue->front);
  TEST_ASSERT_EQUAL_size_t(0, queue->que_size);
}

void test_ca_free(void) {
  CA_Queue* queue = new_ca_queue(5);
  del_ca_queue(&queue);
  TEST_ASSERT_EQUAL_PTR(NULL, queue);
}

void test_ca_push(void) {
  CA_Queue* queue = new_ca_queue(5);
  caq_push(queue, 1);
  caq_push(queue, 2);
  caq_push(queue, 3);
  caq_push(queue, 4);
  caq_push(queue, 5);
  TEST_ASSERT_EQUAL_size_t(1, queue->data[0]);
  TEST_ASSERT_EQUAL_size_t(2, queue->data[1]);
  TEST_ASSERT_EQUAL_size_t(3, queue->data[2]);
  TEST_ASSERT_EQUAL_size_t(4, queue->data[3]);
  TEST_ASSERT_EQUAL_size_t(5, queue->data[4]);
  TEST_ASSERT_EQUAL_size_t(5, queue->que_size);
}

void test_ca_empty(void) {
  CA_Queue* queue = new_ca_queue(5);
  TEST_ASSERT_EQUAL_INT8(1, is_caq_empty(queue));
  caq_push(queue, 1);
  TEST_ASSERT_EQUAL_INT8(0, is_caq_empty(queue));
}

void test_ca_peek(void) {
  CA_Queue* queue = new_ca_queue(5);
  caq_push(queue, 3);
  caq_push(queue, 2);
  caq_push(queue, 1);
  TEST_ASSERT_EQUAL_INT(3, caq_peek(queue));
}

void test_ca_pop(void) {
  CA_Queue* queue = new_ca_queue(5);
  caq_push(queue, 3);
  caq_push(queue, 2);
  caq_push(queue, 1);
  TEST_ASSERT_EQUAL_INT(3, caq_pop(queue));
  TEST_ASSERT_EQUAL_size_t(2, queue->que_size);
}

int main(int argc, char* argv[]) {
  UNITY_BEGIN();
  RUN_TEST(test_cricle_array_queue);
  RUN_TEST(test_ca_free);
  RUN_TEST(test_ca_push);
  RUN_TEST(test_ca_empty);
  RUN_TEST(test_ca_peek);
  RUN_TEST(test_ca_pop);
  return UNITY_END();
}
