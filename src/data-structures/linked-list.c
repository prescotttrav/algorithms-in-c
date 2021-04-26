#include <stdio.h>
#include <stdlib.h>

#include "linked-list.h"

static Node new_node(Position p) {
  Node node = NULL;

  node = (Node) malloc(sizeof(struct q_node));

  if (!node) {
    free(node);
    fprintf(stderr, "Allocation memory failed.\n");
    exit(-1);
  }

  node->val = p;
  node->next = NULL;

  return node;
}

static void add(Queue q, Position val) {
  Node node = new_node(val);

  if (q->is_empty(q)) {
    q->head = node;
    q->tail = node;
  } else {
    q->tail->next = node;
    q->tail = node;
  }
  q->size += 1;
}

static Position remove_head(Queue q) {
  Position p = NULL;
  Node node;

  if (q->is_empty(q))
    return p;

  node = q->head;

  if (node == q->tail)
    q->tail = NULL;

  q->head = node->next;
  q->size -= 1;

  p = node->val;
  free(node);

  return p;
}

static _Bool is_empty(Queue q) {
  return q->size < 1;
}

Queue init_q(void) {
  Queue q = NULL;

  q = (Queue) malloc(sizeof(struct queue));

  if (!q) {
    free(q);
    fprintf(stderr, "Allocation memory failed.\n");
    exit(-1);
  }

  q->size = 0;
  q->head = NULL;
  q->tail = NULL;
  q->add = add;
  q->remove = remove_head;
  q->is_empty = is_empty;

  return q;
}
