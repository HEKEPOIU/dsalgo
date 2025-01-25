#ifndef DSAL_LIST
#define DSAL_LIST

//  NOTE: In C, there is no Template
//  we can use macro or save value as void* to achieve same effect
//  But it too complex for this.
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
typedef struct List_Int {
  int *arr;
  size_t capacity;
  size_t size;
  size_t extend_ratio;
} List_Int;

List_Int *new_list(void);
void del_list(List_Int *list);
size_t size(const List_Int *const list);
int get_list(const List_Int *const list, size_t index);
void set_list(List_Int *const list, size_t index, int value);
void push_list(List_Int *list, int value);
void insert_list(List_Int *list, size_t index, int value);
int remove_list(List_Int *const list, size_t index);
void extend_capacity(List_Int *list);

List_Int *new_list(void) {
  List_Int *nlist = malloc(sizeof(List_Int));
  nlist->capacity = 10;
  nlist->arr = malloc(sizeof(int) * nlist->capacity);
  nlist->size = 0;
  nlist->extend_ratio = 2;
  return nlist;
}

void del_list(List_Int *list) {
  assert(list != NULL);
  free(list->arr);
  free(list);
}

int get_list(const List_Int *const list, size_t index) {
  assert(index >= 0 && index < list->size && list != NULL);
  return list->arr[index];
}

void set_list(List_Int *const list, size_t index, int value) {
  assert(index >= 0 && index < list->size && list != NULL);
  list->arr[index] = value;
}

void push_list(List_Int *list, int value) {
  assert(list != NULL);
  if (list->size >= list->capacity) {
    extend_capacity(list);
  }
  list->arr[list->size] = value;
  list->size++;
}

void insert_list(List_Int *list, size_t index, int value) {
  assert(index >= 0 && list->size > index && list != NULL);
  if (list->size >= list->capacity) {
    extend_capacity(list);
  }

  list->size++;
  for (size_t i = list->size - 1; i > index; i--) {
    list->arr[i] = list->arr[i - 1];
  }
  list->arr[index] = value;
}

int remove_list(List_Int *const list, size_t index) {
  assert(index >= 0 && list->size > index && list != NULL);
  int num = list->arr[index];
  for (size_t i = index; i < list->size - 1; i++) {
    list->arr[i] = list->arr[i + 1];
  }
  list->size--;
  return num;
}

void extend_capacity(List_Int *list) {
  size_t new_cap = list->capacity * list->extend_ratio;
  int *new_arr = malloc(sizeof(int) * new_cap);
  for (size_t i = 0; i < list->size; i++) {
    new_arr[i] = list->arr[i];
  }

  free(list->arr);
  list->arr = new_arr;
  list->capacity = new_cap;
}

#endif // !DSAL_LIST
