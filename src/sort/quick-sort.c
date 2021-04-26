#include <stdlib.h>

#include "../utils/array.h"
#include "quick-sort.h"

/* quick_sort sorts a list of items. */
void quick_sort(int *list, int n) {
  int i, last;

  if (n <= 1)
    return;

  swap_int(list, 0, rand() % n);
  last = 0;

  for (i = 1; i < n; i++) {
    if (*(list + i) < *(list + 0))
      swap_int(list, i, ++last);
  }

  swap_int(list, 0, last);

  quick_sort(list, last);
  quick_sort(list + last + 1, n - last - 1);
}
