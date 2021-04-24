#include "linear.h"

/* linear_search looks a value within a list.
 * if the value is found, the corresponding index is returned,
 * otherwise -1 is returned
 */
int linear_search(const int *list, int val, int n) {
  for (int i = 0; i < n; i++) {
    if (*(list + i) == val)
      return i;
  }
  return -1;
}
