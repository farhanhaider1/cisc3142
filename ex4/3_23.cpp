// Write a program to create a vector with ten int elements. Using an iterator, assign each element a value that is twice its current value. Test your program by printing the vector.

#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int main()
{
  vector<int> num;
  int i;
  int b = 0;
  cout << "Input ten integers into the vector: \n";
  while(b < 10)
    {
    cin >> i;
    num.push_back(i);
    ++b;
    }
   
  for (auto it = num.begin(); it != num.end(); ++it)
  {
      *it *=2;
      //print the new value
      cout << *it << " ";
  }
   
    
  return 0;
}