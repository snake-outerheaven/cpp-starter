#include <iostream>

int
main (void)
{
  int v1, v2;
  v1 = v2 = 0;

  std::cout << "Enter 2 integers: ";
  std::cin >> v1 >> v2;
  std::cout << "The product between " << v1 << " and " << v2 << " is "
            << v1 * v2 << "." << std::endl;
  return 0;
}
