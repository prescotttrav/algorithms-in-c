#include "array.h"

/* swap_int switches two int array items in place */
void swap_int(int *a, int i, int j) {
  int temp = *(a + i);
  *(a + i) = *(a + j);
  *(a + j) = temp;
}
