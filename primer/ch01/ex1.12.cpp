/*
Exercise 1.12: What does the following for loop do?
What is the final value of sum?
 int sum = 0;
 for (int i = -100; i <= 100; ++i)
      sum += i;
*/

#include <iostream>

int
main (void)
{
  int sum = 0;

  for (int i = -100; i <= 100; ++i)
    {
      sum += i;
      std::cout << sum << '\n';
    }

  return 0;
}
