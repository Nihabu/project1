#include <iostream>
#include <armadillo>
#include <fstream>
#include "time.h"
#include <iomanip>

using namespace std;
using namespace arma;
int main()
{
    ofstream outputFile;
    outputFile.open("oppgave_1e.txt");

    int n, Length;
    n = 10;
    Length = 1;
    mat L, U;
    mat A = zeros<mat>(n, n);
    vec b = zeros<mat>(n);
    vec y = zeros<mat>(n);
    vec x = zeros<mat>(n);

    double h, max_error;
    vec u = zeros(n);
    h = Length/(n+1.0);
    A(0, 0) = 2;
    A(0, 1) = -1;
    A(n-1, n-1) = 2;
    A(n-1, n-2) = -1;
    b(0) = 100*exp (-10*(1)*h)*h*h;
    for (int i = 1; i < n-1; i++)
    {
        b(i) = 100*exp (-10*(i+1)*h)*h*h;
        A(i, i) = 2;
        A(i, i+1) = -1;
        A(i, i-1) = -1;
    }
    for (int i = 0; i < n; i++)
    {
        u(i) = 1 - (1 - exp(-10))*(i+1)*h - exp(-10*(i+1)*h);
    }
    lu(L, U, A);

    y(0) = b(0);
    clock_t start, finish;
    start = clock();
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
      /*error =(abs((x(i) - u(i))/u(i)));
        if (error > max_error)
        {
        max_error = error;
        }*/
    }
    finish = clock();
    double sec;
    sec = (finish - start);
    cout << sec/CLOCKS_PER_SEC << endl;
    //cout << max_error << endl;
    for (int i = 0; i < n; i++)
    {
        outputFile << setiosflags(ios::showpoint | ios::uppercase);
        outputFile << setprecision(10) << setw(20) << x[i] << endl;
    }

    return 0;
}
