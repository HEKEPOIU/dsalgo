#include "array.h"
#include <assert.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {
  srand((unsigned int)time(NULL));
  int array[5] = {0};
  int num[5] = {1, 3, 2, 5, 4};

  printf("%d", random_assess(num, 5));
  

  insert(array,5,2,0);
  assert(array[0] == 2);
  return 0;
}
