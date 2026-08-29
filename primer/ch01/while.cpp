#include <iostream>

#define MAX 64

int
main (void)
{
  int val, step;
  val = 0;
  step = 1;

  while (val < MAX)
    val += step;

  std::cout << val << " is now " << MAX << " by steping up by " << step
            << " steps." << std::endl;

  return 0;
}
