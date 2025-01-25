#ifndef DSAL_LINK_LIST_STACK
#define DSAL_LINK_LIST_STACK

#include "link_list.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  ListNode *top;
  int size;
} LL_Stack;

LL_Stack *new_LLStack(void);
void del_Stack(LL_Stack **stack);
void push_stack(LL_Stack * const stack, int value);
_Bool is_empty(const LL_Stack* const stack);
int peek_stack(const LL_Stack* const stack);
int pop_stack(LL_Stack* const stack);

LL_Stack *new_LLStack(void) {
  LL_Stack *stack = malloc(sizeof(LL_Stack));
  stack->top = NULL;
  stack->size = 0;
  return stack;
}

void del_Stack(LL_Stack **stack) {
  remove_all((*stack)->top);
  free(*stack);
  *stack = NULL;
}

void push_stack(LL_Stack * const stack, int value) {
  ListNode *nnode = new_node(value);
  nnode->next = stack->top;
  stack->top = nnode;
  stack->size++;
}

_Bool is_empty(const LL_Stack* const stack){
    return stack->size == 0;
}

int peek_stack(const LL_Stack* const stack){
    if (is_empty(stack)) {
        printf("Stack is empty");
        return INT_MAX;
    }
    return stack->top->value;
}

int pop_stack(LL_Stack* const stack){
    
    int value = peek_stack(stack);
    ListNode* node = stack->top;
    stack->top = stack->top->next;
    free(node);
    stack->size--;
    return value; 
}

#endif // !DSAL_LINK_LIST_STACK
