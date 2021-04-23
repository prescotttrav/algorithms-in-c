#include <assert.h>

#include "../../src/search/binary.h"

void test_binary_search(void) {
  // Should work as expected on int[]
  int arr[] = {1, 2, 3, 4, 5};
  assert(binary_search(arr, 5, 5) == 2);

  assert(binary_search(arr, -1, 5) == -1);

  // Should work as expected on char[]
  char list[] = "hello";
  assert(binary_search(list, 'h', 5) == 2);

  assert(binary_search(list, 'z', 5) == -1);
}
