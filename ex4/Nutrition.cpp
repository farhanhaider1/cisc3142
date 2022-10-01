#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    double const lethalAmount = 5.0 / 35.0;
    double const sweetenerContent = 0.001;

    double const gramsInDietSoda = 350.0 * sweetenerContent;
    int weight, weightInGrams, sodaLimit;

    cout << "Enter your target weight: ";
    cin >> weight;
    weightInGrams = weight * 454;
    while (weight > 0)
    {
        double sweetenerLimit = (double)weightInGrams * lethalAmount;
        sodaLimit = sweetenerLimit / gramsInDietSoda;
        cout << "It would take " << sodaLimit << " cans of diet soda to kill you" << endl;
        cout << "Enter a new weight or '0' to quit: ";
        cin >> weight;
        if(weight == 0){
            cout << "Program quit!" << endl;
        }
        weightInGrams = weight * 454;
    }
    return 0;
}