#include <assert.h>

#include "../../src/search/binary.h"

void test_binary_search() {
  int arr[] = {1, 2, 3, 4, 5};
  assert(binary_search(arr, 5, 5) == 4);

  assert(binary_search(arr, -1, 5) == -1);
}
