#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "generic.h"

void swap(void *a, void *b, int size) {
  char *buf = NULL;

  buf = malloc(sizeof(char) * size);

  if (!buf) {
    free(buf);
    fprintf(stderr, "Allocation memory failed.\n");
    exit(-1);
  }

  memcpy(buf, a, size);
  memcpy(a, b, size);
  memcpy(b, buf, size);

  free(buf);
}
