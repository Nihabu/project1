#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include "time.h"
using namespace std;

int main(){
  //ofstream outputFile;
  //outputFile.open("oppgave_1b.txt");
  int n = 1e6;
  double h, L;
  double *a, *x, *u, *f, *ft;
  a = new double[n];   x = new double[n];
  f = new double[n];   u = new double[n];
  ft = new double[n];
  L = 1.0;
  h = L/(n+1.0);
  a[0] = 2.0;
  ft[0] = 100;
  x[0] = 0.0;
 for (int i = 1; i < n; i++)
 {
      x[i] = x[i-1] + h;
      f[i] = 100*exp (-10*x[i])*h*h;
 }
 clock_t start, finish;
 start = clock();

 for (int i = 1; i < n; i++)
    {
      a[i] = 2 - 1./a[i-1];
      ft[i] = f[i] + ft[i-1]/a[i-1];
    }
    u[n-1] = f[n-1]*h*h/a[n-1];

  for (int i = (n-2); i >= 0; i = i-1)
    {
      u[i] = (f[i] + u[i+1])/a[i];
      //outputFile << setiosflags(ios::showpoint | ios::uppercase);
      //outputFile << setprecision(10) << setw(20) << u[i] << endl;
    }
  //outputFile.close();
  finish = clock();
  double t, sec;
  t = ((finish-start));
  sec = t/CLOCKS_PER_SEC;
  cout << sec << endl;
  delete [] a;   delete [] f;
  delete [] u;   delete [] x;
  return 0;
}
