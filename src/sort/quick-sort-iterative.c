#include <stdio.h>
#include <stdlib.h>

#include "../data-structures/queue.h"

#include "../utils/array.h"
#include "quick-sort-iterative.h"

static Position build_position(int low, int n) {
  Position pos = NULL;

  pos = (Position) malloc(sizeof(struct position));

  if (!pos) {
    free(pos);
    fprintf(stderr, "Allocation memory failed.\n");
    exit(-1);
  }

  pos->low = low;
  pos->high = n - 1 + low;

  return pos;
}

static Queue initialize_q(int start, int n) {
  Queue q = init_q();
  Position first = build_position(start, n);

  q->add(q, first);

  return q;
}

void quick_sort_iter(int *arr, int n) {
  int low, high, pivot, nel;
  Queue q;

  if (n <= 1)
    return;

  q = initialize_q(0, n);

  while (!q->is_empty(q)) {
    Position pos, left, right;

    pos = q->remove(q);

    if (!pos)
      continue;

    low = pos->low;
    high = pos->high;
    pivot = low;
    nel = high - low + 1;

    if (low >= high)
      continue;

    swap_int(arr, low, (rand() % nel) + low);

    for (int i = 0; i < nel; i++) {
      if (arr[low + i] < arr[low]) {
        swap_int(arr, low + i, ++pivot);
      }
    }
    swap_int(arr, low, pivot);

    left = build_position(low, pivot - low);
    q->add(q, left);

    right = build_position(pivot + 1, high - pivot);
    q->add(q, right);

    free(pos);
  }

  free(q);
}
