#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../src/search/binary.h"
#include "../utils.h"

void test_binary_search() {
  int size = 5;
  int *arr = NULL;

  arr = (int *) malloc(sizeof(int) * size);

  if (!arr) {
    free(arr);
    fprintf(stderr, "Allocation memory failed.\n");
    exit(-1);
  }

  // Should work on int type
  arrcpy(arr, (int[]){1, 2, 3, 4, 5}, size);

  assert(binary_search(arr, 5, size) == 4);
  assert(binary_search(arr, -1, size) == -1);

  // Should work on char type
  arrcpy(arr, (int[]){'e', 'h', 'l', 'l', 'o'}, size);

  assert(binary_search(arr, 'e', 5) == 0);
  assert(binary_search(arr, 'z', 5) == -1);

  free(arr);
}
