#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  short *arr;
  size_t len;
  size_t cap;
} Slice;

void SliceInit(Slice *vec) {
  vec->arr = NULL;
  vec->len = 0;
  vec->cap = 0;
}

Slice append(Slice slice, short element) {
  if (slice.cap <= slice.len) {
    slice.cap = (slice.cap == 0) ? 2 : slice.cap * 2;

    short *new = malloc(slice.cap * sizeof(short));
    if (!new) {
      fprintf(stderr, "malloc failed\n");
      exit(1);
    }

    for (size_t i = 0; i < slice.len; i++) {
      new[i] = slice.arr[i];
    }

    free(slice.arr);
    slice.arr = new;
  }

  slice.arr[slice.len++] = element;
  return slice;
}

int main(void) {
  Slice s;
  SliceInit(&s);

  for (int i = 0; i <= 20; i++) {
    s = append(s, i);
  }

  for (int i = 0; i <= 20; i++) {
    printf("%i \n", s.arr[i]);
  }

  return 0;
}
