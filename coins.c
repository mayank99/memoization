/**
 * Calculating the number of ways an amount can be broken down into coins (US).
 * Uses a table to eliminate redundant calculations.
 */
#include <stdio.h>
#include <stdlib.h>

#define EMPTY -1

int **table;

static int change(int amt, int *coins, int index, int size) {
  if (amt == 0) return 1;
  if (amt < 0) return 0;
  if (index == size) return 0;

  if (table[amt][index] != EMPTY) {
    return table[amt][index];
  } else {
    int with = change(amt - coins[index], coins, index, size);
    int without = change(amt, coins, index + 1, size);
    return table[amt][index] = with + without;
  }
}

static void makeTable(int rows, int cols) {
  table = malloc(sizeof(int *) * rows);
  for (int i = 0; i < rows; i++) {
    table[i] = malloc(sizeof(int) * cols);
    for (int j = 0; j < cols; j++) {
      table[i][j] = EMPTY;
    }
  }
}

int main(int argc, char **argv) {
  int amt = atoi(argv[1]);
  int coins[] = {100, 50, 25, 10, 5, 1};
  int size = sizeof(coins) / sizeof(int);

  makeTable(amt + 1, size);

  printf("$%d can be broken down in %d ways\n", amt, change(amt, coins, 0, size));
  return 0;
}