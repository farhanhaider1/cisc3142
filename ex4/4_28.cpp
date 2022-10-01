//Write a program to print the size of each of the built-in types.
#include <iostream>
using std::cout;
using std::endl;

int main()
{
    
    cout << "Integer: " << sizeof(int) << " bytes" << endl;

	cout << "Long: " << sizeof(long) << " bytes" << endl;
    cout << "Long Long: " << sizeof(long long) << " bytes" << endl;

	cout << "Short: " << sizeof(short) << " bytes" << endl;

	cout << "Double: " << sizeof(double) << " bytes" << endl;
    cout << "Long Double: " << sizeof(long double) << " bytes" << endl;

	cout << "Float: " << sizeof(float) << " bytes" << endl;

	cout << "Char: " << sizeof(char) << " bytes" << endl;
    cout << "Wide char: " << sizeof(wchar_t) << " bytes" << endl;
    cout << "Unsigned char: " << sizeof(unsigned char) << " bytes" << endl;
    cout << "Signed char: " << sizeof(signed char) << " bytes" << endl;

	cout << "Bool: " << sizeof(bool) << " bytes" << endl;

    	
    return 0;
}