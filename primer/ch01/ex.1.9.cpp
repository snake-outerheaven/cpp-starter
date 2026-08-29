// Write a program that uses a while to sum the numbers from 50 to 100.

#include <iostream>

int
main (void)
{
  int i, val;

  val = 0;
  i = 50;

  while (i <= 100)
    val += i, i++;

  std::cout << "The sum of 50 up to 100 is " << val << "." << std::endl;

  return 0;
}
