#include <stdio.h>
#include <stdlib.h>

#include "quick-sort-iterative.h"

/* quick implementation of a queue */
typedef struct q_node {
  int *val;
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

int *remove_head(q_t *q) {
  q_node *head = NULL;
  int *val = NULL;

  val = (int *) malloc(sizeof(int) * 2);

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

  for (int i = 0; i < 2; i++)
    *(val + i) = *(head->val + i);

  free(head);

  return val;
}

void add_tail(q_t *q, int *val) {
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

static void swap(int *arr, int i, int j) {
  int temp = *(arr + i);
  *(arr + i) = *(arr + j);
  *(arr + j) = temp;
}

/* quick_sort sorts a list of items, iteratively */
void quick_sort_iter(int *arr, int n) {
  int low, high, last, el;
  int *init = NULL;
  q_t *q = init_q();

  if (n <= 1)
    return;

  low = 0;
  el = n;

  init = (int *) malloc(sizeof(int) * 2);

  if (!init) {
    free(init);
    fprintf(stderr, "Allocation memory failed.\n");
    exit(-1);
  }

  *init = low;
  *(init + 1) = el;

  add_tail(q, init);

  while (!is_empty(q)) {
    int *left, *right;
    int *val = remove_head(q);

    if (!val)
      continue;

    low = *val;
    el = *(val + 1);
    high = el - 1 + low;
    last = low;

    if (low >= high)
      continue;

    swap(arr, low, (rand() % el) + low);

    for (int i = 0; i < el; i++) {
      if (arr[low + i] < arr[low]) {
        swap(arr, low + i, ++last);
      }
    }
    swap(arr, low, last);

    left = NULL;
    left = (int *) malloc(sizeof(int) * 2);

    if (!left) {
      free(left);
      fprintf(stderr, "Allocation memory failed.\n");
      exit(-1);
    }

    *left = low;
    *(left + 1) = last - low;

    add_tail(q, left);

    right = NULL;
    right = (int *) malloc(sizeof(int) * 2);

    if (!right) {
      free(right);
      fprintf(stderr, "Allocation memory failed.\n");
      exit(-1);
    }

    *right = last - low + 1 + low;
    *(right + 1) = high - last;

    add_tail(q, right);

    free(val);
  }

  free(q);
}
