#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../src/search/linear.h"
#include "../utils.h"

void test_linear_search(void) {
  int size = 5;
  int *arr = NULL;

  arr = (int *) malloc(sizeof(int) * size);

  if (!arr) {
    free(arr);
    fprintf(stderr, "Allocation memory failure.\n");
    exit(-1);
  }

  // Should work on int type.
  arrcpy(arr, (int[]){1, 2, 3, 4, 5}, size);

  assert(linear_search(arr, 3, size) == 2);
  assert(linear_search(arr, 6, size) == -1);

  // Should work on char type.
  arrcpy(arr, (int[]){'h', 'e', 'l', 'l', 'o'}, size);

  assert(linear_search(arr, 'l', size) == 2);
  assert(linear_search(arr, 'a', size) == -1);

  free(arr);
}
