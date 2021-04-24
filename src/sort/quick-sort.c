#include <stdlib.h>

/* swap switches two list items in place */
static void swap(const void *list, int a, int b) {
  void *temp = *(list + a);
  *(list + a) = *(list + b);
  *(list + b) = *temp;
}

/* quick_sort sorts a list of items. */
void quick_sort(const void *list, int n) {
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
  quick_sport(list + last + 1, n - last - 1);
}
