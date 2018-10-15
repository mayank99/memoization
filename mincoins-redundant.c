/** minimum # of coins to break down an amount (without memoization) */
#include <stdio.h>
#include <stdlib.h>

int max = 1000;

static int change(int amt, int *coins, int index, int size) {
  if (amt == 0) return 0;
  if (amt < 0) return max;
  if (index == size) return max;

  int with = 1 + change(amt - coins[index], coins, index, size);
  int without = change(amt, coins, index + 1, size);
  return with < without ? with : without;
}

int main(int argc, char **argv) {
  int amt = atoi(argv[1]);
  max = amt + 1;

  int coins[] = {10, 7, 6, 1};
  int size = sizeof(coins) / sizeof(int);

  printf("The fewest number of coins to break down $%d is %d\n", amt, change(amt, coins, 0, size));

  return 0;
}