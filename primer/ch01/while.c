#include <stdio.h>

#define MAX 64

int
main (void)
{
  int val, step;

  val = 0;
  step = 1;

  while (val < MAX)
    val += step;

  printf ("%d is now %d by stepping up %d steps.\n", val, MAX, step);

  return 0;
}
