#include <assert.h>

#include "../../src/sort/quick-sort.h"

static void assertarr(const void *actual, const void *expected, int n) {
  for (int i = 0; i < n; i++) {
    assert(*(actual + i) == *(expected + i));
  }
}

void test_quick_sort(void) {
  // Should work as expected on int[]
  int arr[] = {5, 4, 5, 3, 1, 2} assertarr(quick_sort(arr, 6),
                                           {1, 2, 3, 4, 5, 5}, 6);

  // Should work as expected on char[]
  char list[] = "hello";
  assertarr(quick_sort(list, 5), "ehllo", 5)
}
