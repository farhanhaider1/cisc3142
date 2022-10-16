// Write a program that finds and prints
// all
// the prime numbers between 3 and 100. A prime number is a
// number such that 1 and itself are the only numbers that evenly divide it (for example, 3, 5, 7, 11, 13, 17,
// ...)

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    /* Creating a vector of integers called prime. */
    vector<int> prime;
    /* Setting the variable isprime to true. */
    bool isprime = true;
    
    /* Checking if the number is prime in the loop from 3 to 100 */
    for (int i = 3; i <= 100; i++)
    {
        // should be true at start
        isprime = true;
       
        for (auto j : prime)
        {
            
            /* if not prime */
            if (i % j == 0)
            {
                isprime = false;
            }
        }
        /* Checking if the number is prime and if it is, it prints it and adds it to the vector prime. */
        if (isprime)
        {
            cout << i << endl;
            // cout << "here" << endl;
            prime.push_back(i);
        }
         
    }
    return 0;
}