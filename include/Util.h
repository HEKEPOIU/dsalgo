#ifndef DSAL_UTIL
#define DSAL_UTIL

#include <stdio.h>
#include <string.h>


void print_int_array(const int *const arr, int len);

void print_int_array(const int *const arr, int len) {
  if (arr == NULL || len == 0) {
    printf("[]");
    return;
  }
  printf("[");
  for (size_t i = 0; i < len -1; i++) {
    printf("%d, ", arr[i]);
  }

  printf("%d]\n", arr[len-1]);
}

#endif // !DSAL_UTIL
