#include <stdio.h>
#include <stdlib.h>

#include "../data-structures/queue.h"

#include "../utils/generic.h"
#include "quick-sort-iterative.h"

static void swap_elem(int *arr, int i, int j) {
  swap(arr + i, arr + j, sizeof(int));
}

static Position build_pos(int low, int n) {
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

static void add_pos(Queue q, int start, int size) {
  Position pos = build_pos(start, size);

  if (pos && pos->low < pos->high)
    q->add(q, pos);
  else
    free(pos);
}

void quick_sort_iter(int *arr, int n) {
  int low, high, pivot, nel;
  Queue q;

  if (n <= 1)
    return;

  q = init_q();
  add_pos(q, 0, n);

  while (!q->is_empty(q)) {
    Position pos;

    pos = q->remove(q);

    low = pos->low;
    high = pos->high;
    pivot = low;
    nel = high - low + 1;

    swap_elem(arr, low, rand() % nel + low);

    for (int i = 0; i < nel; i++) {
      if (arr[low + i] < arr[low]) {
        swap_elem(arr, low + i, ++pivot);
      }
    }
    swap_elem(arr, low, pivot);

    // Half less than pivot
    add_pos(q, low, pivot - low);

    // Half greater than pivot
    add_pos(q, pivot + 1, high - pivot);

    free(pos);
  }

  free(q);
}
