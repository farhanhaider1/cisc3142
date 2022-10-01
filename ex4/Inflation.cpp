// It is difficult to make a budget that spans several years because
// prices are not stable. If your company needs 200 pencils per year, you cannot simply use this year’s price as the cost of pencils 2 years from
// now. Because of inflation the cost is likely to be higher than it is today. Write a program to gauge the expected cost of an item in a specified number of years. The program asks for the cost of the item, the
// number of years from now that the item will be purchased, and the rate of inflation. The program then outputs the estimated cost of the item after the specified period. Have the user enter the inflation rate as a percentage, like 5.6 (percent). Your program should then convert the percent to a fraction, like 0.056, and should use a loop to estimate the price adjusted for inflation.

#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

int main()
{
    double cost;
    int years;
    double rate;

    cout << "Enter cost in dollars: ";
    cin >> cost;
    cout << "Please enter number of years from now that the item will be purchased: ";
    cin >> years;
    cout << "enter inflation rate: ";
    cin >> rate;

    double fractionRate = rate / 100;

    for (int i = 0; i < years; i++)
    {
        cost += cost * fractionRate;
    }

    // print the inflated price to two decimal places
    cout << "Estimated price after " << years << " years is: $"
		<< fixed << setprecision(2) << cost << endl;
    return 0;
}