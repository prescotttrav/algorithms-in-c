#pragma once

struct position {
  int low, high;
};

typedef struct position *Position;

struct q_node {
  Position val;
  struct q_node *next;
};

typedef struct q_node *Node;

struct queue {
  int size;
  Node head;
  Node tail;
  void (*add)(struct queue *, Position);
  Position (*remove)(struct queue *);
  _Bool (*is_empty)(struct queue *);
};

typedef struct queue *Queue;

Queue init_q(void);
