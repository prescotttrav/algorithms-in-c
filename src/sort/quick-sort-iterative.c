#include <stdio.h>
#include <stdlib.h>

#include "../utils/array.h"
#include "quick-sort-iterative.h"

typedef struct position {
  int low, high;
} position_t;

/* quick implementation of a queue */
typedef struct q_node {
  position_t *val;
  struct q_node *next;
} q_node;

typedef struct q_t {
  int size;
  q_node *head, *tail;
} q_t;

q_t *init_q(void) {
  q_t *q = NULL;

  q = (q_t *) malloc(sizeof(q_t));

  if (!q) {
    free(q);
    fprintf(stderr, "Allocation memory failed.\n");
    exit(-1);
  }

  q->size = 0;
  q->head = NULL;
  q->tail = NULL;

  return q;
}

_Bool is_empty(q_t *q) {
  return q->size == 0;
}

position_t *remove_head(q_t *q) {
  q_node *head = NULL;
  position_t *val = NULL;

  val = (position_t *) malloc(sizeof(position_t));

  if (!val) {
    free(val);
    fprintf(stderr, "Allocation memory failed.\n");
    exit(-1);
  }

  if (is_empty(q))
    return val;

  if (q->tail == q->head) {
    q->tail = NULL;
  }
  head = q->head;
  q->head = q->head->next;
  q->size -= 1;

  val = head->val;

  free(head);

  return val;
}

void add_tail(q_t *q, position_t *val) {
  q_node *tail = NULL;

  tail = (q_node *) malloc(sizeof(q_node));

  if (!tail) {
    free(tail);
    fprintf(stderr, "Allocation of memory failed.\n");
    exit(-1);
  }

  tail->val = val;
  tail->next = NULL;

  if (is_empty(q)) {
    q->tail = tail;
    q->head = tail;
  } else {
    q->tail->next = tail;
    q->tail = tail;
  }
  q->size += 1;
}

/* end of queue implementation */

position_t *build_position(int low, int n) {
  position_t *pos = NULL;

  pos = (position_t *) malloc(sizeof(position_t));

  if (!pos) {
    free(pos);
    fprintf(stderr, "Allocation memory failed.\n");
    exit(-1);
  }

  pos->low = low;
  pos->high = n - 1 + low;

  return pos;
}

q_t *initialize_q(int start, int n) {
  q_t *q = init_q();
  position_t *first = build_position(start, n);

  add_tail(q, first);

  return q;
}

/* quick_sort sorts a list of items, iteratively */
void quick_sort_iter(int *arr, int n) {
  int low, high, pivot, nel;
  q_t *q;

  if (n <= 1)
    return;

  q = initialize_q(0, n);

  while (!is_empty(q)) {
    position_t *pos, *left, *right;

    pos = remove_head(q);

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
    add_tail(q, left);

    right = build_position(pivot + 1, high - pivot);
    add_tail(q, right);

    free(pos);
  }

  free(q);
}
