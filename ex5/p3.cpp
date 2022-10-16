#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main(){
	ifstream inputFile;
	inputFile.open("p3.txt");

	/* Checking if the file is open. If it is not open, it will print out an error message and exit the
    program. */
    if (!inputFile) {
		cerr << "Unable to open file datafile.txt";
		exit(1);   // call system to stop
	}

	double x,y;
	vector<double> Xvec;
	vector<double> Yvec;
	double ySum=0, xSum=0;
	double yAvg, xAvg;
    double sumSquarredErorX=0;
    double product=0;

    /* Reading the file and pushing the values into the vectors. */
    while (inputFile>>y>>x){
		Xvec.push_back(x);
		Yvec.push_back(y);
	}

	/* A for loop that is iterating through the vector Xvec and adding the values to xSum. */
    for(double temX: Xvec){
		xSum+=temX;
	}

	/* Iterating through the vector Yvec and adding the values to ySum. */
    for(double temY: Yvec){
		ySum+=temY;
	}
	/* Dividing the sum of the y values by the size of the vector Yvec. */
    yAvg=ySum/Yvec.size();

	/* Dividing the sum of the x values by the size of the vector Xvec. */
    xAvg=xSum/Xvec.size();

	
	/* Iterating through the vector Xvec and adding the values to sumSquarredErorX. */
    for (double x: Xvec){
		sumSquarredErorX+=(x-xAvg)*(x-xAvg);
	}
	
	/* This is iterating through the vector Xvec and adding the values to product. */
    for(int i=0;i<Xvec.size();i++){
		product+=(Xvec[i]-xAvg)*(Yvec[i]-yAvg);
	}

	/* Calculating the slope of the line. */
    double b1=product/sumSquarredErorX;

	/* This is calculating the y intercept of the line. */
    double b0=yAvg-b1*xAvg;

	/* This is printing out the simple linear regression equation. */
    cout<<"Simple linear regression: "<<b0<<"+"<<b1<<*"x"<<endl;

}