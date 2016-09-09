#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include "time.h"
using namespace std;

int main(){
  ofstream outputFile;
  outputFile.open("oppgave_1d.txt");
  int n = 1e5;
  double h, L;
  double *a, *u, *v, *f, *ft, *error;
  a = new double[n+2];
  f = new double[n+2];   u = new double[n+2];
  ft = new double[n+2];  error = new double[n+2];
  v = new double[n+2];
  L = 1.0;
  h = L/(n+1.0);
  //a[0] = 2.0;

  u[0] = 0;

 for (int i = 0; i < n+2; i++)
 {
      f[i] = 100*exp (-10*i*h)*h*h;
      v[i] = 1 - (1 - exp (-10))*i*h - exp (-10*i*h);
      a[i] = 2.0;
 }
 clock_t start, finish;
 start = clock();
 ft[1] = f[1];
 for (int i = 2; i < n+1; i++)
    {
      a[i] = 2.0 - 1./(a[i-1]);
      ft[i] = f[i] + ft[i-1]/a[i-1];
      cout << a[i] << endl;
    }
    u[n] = ft[n]/a[n];
    cout << u[n] << endl;
  for (int i = (n-1); i >= 1; i = i-1)
    {
      u[i] = (ft[i] + u[i+1])/a[i];
      error[i] = (abs((u[i] - v[i])/v[i]));
    }
  for (int i = 0; i < n+2; i++)
     {
      outputFile << setiosflags(ios::showpoint | ios::uppercase);
      outputFile << setprecision(10) << setw(20) << error[i] << endl;
  }
  delete [] a;   delete [] f;
  delete [] u;
  return 0;
}