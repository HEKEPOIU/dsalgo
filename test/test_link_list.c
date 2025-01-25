#include "unity.h"
#include "link_list.h"
#include <stdlib.h>


void setUp(void) {}

void tearDown(void) {}

void test_new_node(void){
    ListNode* node = new_node(3);

    TEST_ASSERT_EQUAL_INT(node->value, 3);
    TEST_ASSERT_EQUAL_PTR(node->next, NULL);
    ListNode* node1 = new_node(4);
    node->next = node1;

    TEST_ASSERT_EQUAL_PTR(node->next, node1);
}

void test_insert_node(void){
    ListNode *node1 = new_node(3);
    ListNode *node2 = new_node(2);
    ListNode *node3 = new_node(1);

    node1->next = node2;
    insert_node(node1, node3);
    TEST_ASSERT_EQUAL_PTR(node1->next, node3);
}


void test_remove_node(void){
    ListNode *node1 = new_node(3);
    ListNode *node2 = new_node(2);
    ListNode *node3 = new_node(1);
    node1->next = node2;
    node2->next = node3;
    remove_node(node1);
    TEST_ASSERT_EQUAL_PTR(node1->next, node3);
}

void test_get_node(){
    ListNode *node1 = new_node(3);
    ListNode *node2 = new_node(2);
    ListNode *node3 = new_node(1);
    node1->next = node2;
    node2->next = node3;
    TEST_ASSERT_EQUAL_PTR(get(node1, 2), node3);
}

void test_find_node(){
    ListNode *node1 = new_node(3);
    ListNode *node2 = new_node(2);
    ListNode *node3 = new_node(1);
    node1->next = node2;
    node2->next = node3;
    TEST_ASSERT_EQUAL_INT(find_link_list(node1, 1), 2);
}

int main(int argc, char *argv[])
{
  UNITY_BEGIN();
  RUN_TEST(test_new_node);
  RUN_TEST(test_insert_node);
  RUN_TEST(test_remove_node);
  RUN_TEST(test_get_node);
  RUN_TEST(test_find_node);
  return UNITY_END();
}
