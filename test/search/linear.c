#include <assert.h>

#include "../../src/search/linear.h"

void test_linear_search(void) {
  // Should work as expected on int[]
  int arr[] = {1, 2, 3, 4, 5};
  assert(linear_search(arr, 3, 5) == 2);

  assert(linear_search(arr, 6, 5) == -1);

  // Should work as expected on char[]
  char list[] = "hello";
  assert(linear_search(list, 'l', 5) == 2);

  assert(linear_search(list, 'a', 5) == -1);
}
