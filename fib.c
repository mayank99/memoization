#include <stdlib.h>
#include <stdio.h>

int *table;

static int fib(int n) {
  if (n < 2) {
    return 1;
  } else {
    if (table[n] != 0) return table[n];
    return table[n] = fib(n - 1) + fib(n - 2);
  }
}

int main(int argc, char** argv) {
  int n = atoi(argv[1]);
  table = calloc(n,sizeof(int));
  printf("fib(%d) = %d\n", n, fib(n));
  return 0;
}