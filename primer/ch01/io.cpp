#include <iostream>

int
main (void)
{
  std::cout << "Enter two numbers: ";
  int v1, v2;
  v1 = v2 = 0;
  std::cin >> v1 >> v2;
  std::cout << "The sum of "
               << v1 << " and " << v2
               << " is " << v1 + v2 << "." << std::endl;
  return 0;
}
