#include <stdio.h>
#include <stdlib.h>

#include "../../src/sort/quick-sort-iterative.h"
#include "../utils.h"

void test_quick_sort_iter(void) {
  int size = 6;
  int *arr = NULL;

  arr = (int *) malloc(sizeof(int) * size);

  if (!arr) {
    free(arr);
    fprintf(stderr, "Allocation memory failed.\n");
    exit(-1);
  }

  // Should work on int type.
  arrcpy(arr, (int[]){5, 4, 5, 3, 1, 2}, size);
  quick_sort_iter(arr, size);

  assertarr(arr, (int[]){1, 2, 3, 4, 5, 5}, size);

  // Should work on char type.
  arrcpy(arr, (int[]){'z', 'y', 'g', 'o', 't', 'e'}, size);
  quick_sort_iter(arr, size);

  assertarr(arr, (int[]){'e', 'g', 'o', 't', 'y', 'z'}, size);

  free(arr);
}
