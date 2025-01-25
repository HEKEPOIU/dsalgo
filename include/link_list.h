#ifndef DSAL_LINKLIST
#define DSAL_LINKLIST

#include <stddef.h>
#include <stdlib.h>
typedef struct ListNode {
  int value;
  struct ListNode *next;
} ListNode;

ListNode *new_node(int val);
void insert_node(ListNode *const n0, ListNode *const p);
void remove_node(ListNode *node);
ListNode *get(ListNode * head, size_t index);
int find_link_list(ListNode *node, int value);
void remove_all(ListNode *head);

void remove_all(ListNode* head){
    if (head->next != NULL) {
        remove_all(head->next);
    }
    free(head);
}

ListNode *new_node(int val) {
  ListNode *node = (ListNode *)malloc(sizeof(ListNode));

  node->value = val;
  node->next = NULL;

  return node;
}

void insert_node(ListNode *const n0, ListNode *const p) {
  if (n0 == NULL || p == NULL) {
    return;
  }
  p->next = n0->next;
  n0->next = p;
}

// Remove Next
void remove_node(ListNode * const node) {
  if (node == NULL || node->next == NULL) {
    return;
  }

  ListNode *next = node->next;
  node->next = next->next;
  free(next);
}

ListNode* get(ListNode* node, size_t index){
    for (size_t i = 0; i < index; i++) {
        if (node == NULL) {
            return NULL; 
        }        
        node = node->next;
    }

    return node;
}

int find_link_list(ListNode* node, int value){
    ListNode* temp = node;
    int i =0;
    while (temp != NULL) {
        if (temp->value == value) {
            return i; 
        } 
        i++;
        temp = temp->next;
    }
    return -1; 
}

#endif
