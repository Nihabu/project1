#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;
int main()
{
    int n, L;
    n = 5;
    L = 1;

    double h;
    h = L/(n+1.0);

    mat A = zeros<mat>(n, n);
    A(0, 0) = 2;
    A(0, 1) = -1;
    A(n-1, n-1) = 2;
    A(n-1, n-2) = -1;

    vec b = zeros<vec>(n);
    b(0) = 100;

    for (int i = 1; i < n-1; i++)
    {
        b(i) = 100*exp (-10*i*h)*h*h;
        A(i, i) = 2;
        A(i, i+1) = -1;
        A(i, i-1) = -1;
    }
    // solve Ax = b
    vec x = solve(A,b);
    //mat L, U;
    cout << x << endl;
    return 0;
}
