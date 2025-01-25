#include "unity.h"
#include <link_list_stack.h>

void setUp(void) {}

void tearDown(void) {}

void test_new_LLstack(void){
    LL_Stack* stack = new_LLStack();
    TEST_ASSERT_EQUAL_PTR(stack->top, NULL);
    TEST_ASSERT_EQUAL_INT(stack->size, 0);
}
void test_LLstack_is_empty(void){
    LL_Stack* stack = new_LLStack();
    TEST_ASSERT_EQUAL_INT(is_empty(stack), 1);
}

void test_push_stack(void){
    LL_Stack* stack = new_LLStack();
    push_stack(stack, 3);
    push_stack(stack, 2);
    push_stack(stack, 1);
    TEST_ASSERT_EQUAL_INT(stack->top->value, 1);
    TEST_ASSERT_EQUAL_INT(stack->top->next->value, 2);
    TEST_ASSERT_EQUAL_INT(stack->top->next->next->value, 3);
    TEST_ASSERT_EQUAL_INT(stack->size, 3);
}

void test_peek_stack(void){
    LL_Stack* stack = new_LLStack();
    push_stack(stack, 3);
    TEST_ASSERT_EQUAL_INT(peek_stack(stack), 3);
    TEST_ASSERT_EQUAL_INT(stack->size, 1);
}

void test_pop_stack(void){
    LL_Stack* stack = new_LLStack();
    push_stack(stack, 3);
    TEST_ASSERT_EQUAL_INT(pop_stack(stack), 3);
    TEST_ASSERT_EQUAL_INT(stack->size, 0);
    TEST_ASSERT_EQUAL_PTR(stack->top, NULL);
}

void test_empty_stack(void){
    LL_Stack* stack = new_LLStack();
    push_stack(stack, 3);
    push_stack(stack, 2);
    push_stack(stack, 1);
    del_Stack(&stack);
    TEST_ASSERT_EQUAL_PTR(stack, NULL);

}


int main(int argc, char *argv[]) {
  UNITY_BEGIN();
  RUN_TEST(test_new_LLstack);
  RUN_TEST(test_LLstack_is_empty);
  RUN_TEST(test_push_stack);
  RUN_TEST(test_peek_stack);
  RUN_TEST(test_pop_stack);
  RUN_TEST(test_empty_stack);
  return UNITY_END();
}
