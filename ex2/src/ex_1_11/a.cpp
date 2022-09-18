#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
  int small = 0, big = 0;
  cout << "Please input 2 integers: ";
  cin >> small >> big;

  if (small > big)
  {
    int temp = small;
    small = big;
    big = temp;
  }

  // Print integers in the range [num1, num2]:
  cout << "while statement: \n";
  while (small <= big)
  {
    cout << small << endl;
    ++small;
  }

  return 0;
}