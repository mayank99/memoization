/** # of ways an amount can be broken down (without memoization) */
#include <stdio.h>
#include <stdlib.h>

static int change(int amt, int *coins, int index, int size) {
  if (amt == 0) return 1;
  if (amt < 0) return 0;
  if (index == size) return 0;

  int with = change(amt - coins[index], coins, index, size);
  int without = change(amt, coins, index + 1, size);
  return with + without;
}

int main(int argc, char **argv) {
  int amt = atoi(argv[1]);
  int coins[] = {100, 50, 25, 10, 5, 1};
  int size = sizeof(coins) / sizeof(int);

  printf("$%d can be broken down in %d ways\n", amt, change(amt, coins, 0, size));

  return 0;
}