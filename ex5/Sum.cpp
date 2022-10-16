/*
Sum of Digits
Calculate
the sum of digits of a number
The program prompts the user to enter the number. For example:
Enter number: 7865 The output should be 7+ 8 + 6 + 5 = 26
Sample output of the program is shown below:
Enter a positive number: 7865
Sum of digits of the number 7865 is: 26
*/
#include <iostream>

using namespace std;

int main() {
    cout << "Enter a positive number:(7865): ";
    int number = 0;
    cin >> number;
    // make a copy of number
    int num2 = number; 
    // result to output
    int result = 0;

    //
    while (number != 0)
    {
        result = result + number % 10;
        number = number / 10;
    }
        
    cout << "Sum of digits of the number " << num2 << " is: " << result << endl;

return 0;    
}