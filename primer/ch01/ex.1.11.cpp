// Write a program that prompts the user for two integers. Print each number in
// the range specified by those two integers.

#include <iostream>

int
main (void)
{
  int v1, v2;

  v1 = v2 = 0;

  std::cout << "Enter 2 integers: ";
  std::cin >> v1 >> v2;
  std::cout << "Program read " << v1 << " and " << v2 << '\n';

  while (v1 <= v2)
    std::cout << v1 << '\n', v1++;

  return 0;
}
