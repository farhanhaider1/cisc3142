#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void weightedMovingAverage(vector<string> &vecMonth, vector<int> &vecTemp, ofstream &myfile)
{
    myfile << endl
           << endl;
    for (int i = 0; i < vecTemp.size() - 2; i++)
    {
        // formula from the exercise
        double temp = vecTemp[i] + (2 * vecTemp[i + 1]) + (3 * vecTemp[i + 2]);
        temp /= 6;

        myfile << "Weighted moving average for " << vecMonth[i] << " is:  " << temp << endl;
    }
}

double average(vector<int> vecTemp)
{
    double sum = 0;

    for (auto x : vecTemp)
    {
        sum += x;
    }

    return sum / vecTemp.size();
}

int main()
{
    ifstream input("ex9/weather.txt");

    vector<int> vecTemp;
    vector<string> vecMonth;

    string month;
    string temperature;

    getline(input, month);

    while (input.good())
    {
        getline(input, month, ',');
        getline(input, temperature, '\n');

        vecMonth.push_back(month);
        vecTemp.push_back(stoi(temperature));
    }

    ofstream myfile;
    myfile.open("ex9/output.txt");

    myfile << "Farhan Haider" << endl;
    myfile << endl
           << "avg: " << average(vecTemp) << endl
           << endl;

    double movavg;
    for (int i = 2; i < vecTemp.size(); i++)
    {
        movavg = (vecTemp[i - 2] + vecTemp[i - 1] + vecTemp[i]) / 3;
        myfile << "avg for " << vecMonth[i] << ":  " << movavg << endl;
    }

    weightedMovingAverage(vecMonth, vecTemp, myfile);
    myfile.close();
}
