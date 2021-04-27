#include <stdlib.h>

#include "../utils/generic.h"
#include "quick-sort.h"

/* quick_sort sorts a list of items. */
void quick_sort(int *list, int n) {
  int i, last;

  if (n <= 1)
    return;

  swap(list, list + (rand() % n), sizeof(int));
  last = 0;

  for (i = 1; i < n; i++) {
    if (*(list + i) < *(list + 0)) {
      ++last;
      swap(list + i, list + last, sizeof(int));
    }
  }

  swap(list, list + last, sizeof(int));

  quick_sort(list, last);
  quick_sort(list + last + 1, n - last - 1);
}
