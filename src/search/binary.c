#include "binary.h"

/* binary_search looks for a value within the provided list.
 * if the value is found, the corresponding index is returned,
 * otherwise -1 is returned.
 *
 * Constraint: the list must be sorted.
 */
int binary_search(const int *list, int val, int n) {
  int low, mid, high;

  low = 0;
  high = n - 1;

  while (low <= high) {
    mid = (low + high) / 2;

    if (*(list + mid) == val) {
      return mid;
    } else if (*(list + mid) < val) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return -1;
}
