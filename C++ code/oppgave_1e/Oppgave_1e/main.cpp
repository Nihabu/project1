#include <iostream>
#include <armadillo>
#include <fstream>
#include "time.h"
#include <iomanip>

using namespace std;
using namespace arma;
int main()
{
    ofstream outputFile;    //create new file
    outputFile.open("oppgave_1e.txt");

    //declaring variables and armadillo matrices and vectors
    int n, Length;
    n = 1000;
    Length = 1;
    mat L, U;
    mat A = zeros<mat>(n, n);
    vec b = zeros<mat>(n);
    vec y = zeros<mat>(n);
    vec x = zeros<mat>(n);

    double h, max_error;
    vec u = zeros(n);
    h = Length/(n+1.0); //steplength
    //setting boundary values
    A(0, 0) = 2;
    A(0, 1) = -1;
    A(n-1, n-1) = 2;
    A(n-1, n-2) = -1;
    b(0) = 100*exp (-10*(1)*h)*h*h;
    //loop creating matrix
    for (int i = 1; i < n-1; i++)
    {
        b(i) = 100*exp (-10*(i+1)*h)*h*h;
        A(i, i) = 2;
        A(i, i+1) = -1;
        A(i, i-1) = -1;
    }
    //calculating nalytical solution
    for (int i = 0; i < n; i++)
    {
        u(i) = 1 - (1 - exp(-10))*(i+1)*h - exp(-10*(i+1)*h);
    }
    lu(L, U, A); //setting up lu-function from arma-library

    y(0) = b(0);
    clock_t start, finish; //rewind clock
    start = clock(); //start clock
    /*
    Forward substitution with a total of 2N FLOPS for this spesific problem
    */

    for (int i = 1; i < n; i++)
    {
        y(i) = b(i) - L(i, i-1)*y(i-1);
    }

    x(n-1) = y(n-1)/U(n-1, n-1);

    /*
    Backward substitution with a total of 2N FLOPS for this spesific problem
    */
    for (int i = n-2; i>=0; i--)
    {
        x(i) = (y(i) + x(i+1))/U(i, i);
        double error =(abs((x(i) - u(i))/u(i))); //relative error
        if (error > max_error)
        {
        max_error = error; //set error to always be maximum error
        }
    }
    finish = clock(); //press stop
    double sec;
    sec = (finish - start); //no. of clocks_per_sec
    //cout << sec/CLOCKS_PER_SEC << endl; //print seconds used
    cout << max_error << endl;
    //write to file
    for (int i = 0; i < n; i++)
    {
        outputFile << setiosflags(ios::showpoint | ios::uppercase);
        outputFile << setprecision(10) << setw(20) << x[i] << endl;
    }

    return 0;
}
