#include <assert.h>

#include "utils.h"

/* arrcpy copys int content from one array to another */
void arrcpy(int *to, const int *from, int n) {
  for (int i = 0; i < n; i++) {
    *to = *from;
    to++;
    from++;
  }
}

/* assertarr asserts each index between two int arrays */
void assertarr(const int *actual, const int *expected, int n) {
  for (int i = 0; i < n; i++) {
    assert(*(actual + i) == *(expected + i));
  }
}
