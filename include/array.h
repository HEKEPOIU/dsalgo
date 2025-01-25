#ifndef DSAL_ARRAY
#define DSAL_ARRAY

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int random_assess(const int *const arr, size_t len);
void insert(int *const arr, size_t len, int num, size_t index);
void delete(int *const arr, size_t len, size_t index);
int sum(const int *const arr, size_t len);
int find(const int *const arr, size_t len, int target);
int* extend(const int *const arr, size_t len, size_t enlarge_size);

int random_assess(const int *const arr, size_t len) {
  size_t random_index = (size_t)rand() % len;
  return arr[random_index];
}

void insert(int *const arr, size_t len, int num, size_t index) {
  if (arr == NULL) {
    return;
  }

  for (size_t i = len - 1; i > index; i--) {
    arr[i] = arr[i - 1];
  }
  arr[index] = num;
}

// NOTE: That this Array Delete Implement don't actually delete target element.
//  it just move item front of it.
void delete(int *const arr, size_t len, size_t index) {
  if (arr == NULL || index > len - 1) {
    return;
  }
  for (size_t i = index; i < len - 1; i++) {
    arr[i] = arr[i + 1];
  }
}

int sum(const int *const arr, size_t len) {
  if (arr == NULL) {
    return 0;
  }
  int count = 0;
  for (size_t i = 0; i < len; i++) {
    count += arr[i];
  }
  return count;
}

int find(const int *const arr, size_t len, int target) {
  if (arr == NULL) {
    return -1;
  }

  for (size_t i = 0; i < len; i++) {
    if (arr[i] == target) {
      return (int)i;
    }
  }
  return -1;
}

int *extend(const int *const arr, size_t len, size_t enlarge_size) {
  size_t new_array_size = (size_t)(len+enlarge_size);
  int *new_array = (int *)malloc(sizeof(int) * new_array_size);
  for (size_t i = 0; i < len; i++) {
    new_array[i] = arr[i];
  }
  // Init value
  for (size_t i = len; i < new_array_size; i++) {
    new_array[i]  = 0;
  }
  return new_array;
}

#endif // !DSAL_ARRAY
