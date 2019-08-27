#include <iostream>
#include <string>

int main()
{
  std::string x = "100";

  std::cout << "Please enter a number: ";

  std::cin >> x;
  
  std::cout << "The value of x = " << x << "\n";

  return 0;
}
