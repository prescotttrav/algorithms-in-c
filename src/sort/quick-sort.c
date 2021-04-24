#include <stdlib.h>

#include "quick-sort.h"

/* swap switches two list items in place */
static void swap(int *list, int a, int b) {
  int temp = *(list + a);
  *(list + a) = *(list + b);
  *(list + b) = temp;
}

/* quick_sort sorts a list of items. */
void quick_sort(int *list, int n) {
  int i, last;

  if (n <= 1)
    return;

  swap(list, 0, rand() % n);
  last = 0;

  for (i = 1; i < n; i++) {
    if (*(list + i) < *(list + 0))
      swap(list, i, ++last);
  }

  swap(list, 0, last);

  quick_sort(list, last);
  quick_sort(list + last + 1, n - last - 1);
}
