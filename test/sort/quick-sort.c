#include <assert.h>

#include "../../src/sort/quick-sort.h"

static void assertarr(const int *actual, const int *expected, int n) {
  for (int i = 0; i < n; i++) {
    assert(*(actual + i) == *(expected + i));
  }
}

void test_quick_sort(void) {
  int arr[] = {5, 4, 5, 3, 1, 2};
  quick_sort(arr, 6);

  assertarr(arr, (int[]){1, 2, 3, 4, 5, 5}, 6);
}
