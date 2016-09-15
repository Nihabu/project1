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


  for (int n = 10; n <= 1000; n= n*10)
  {
  cout << n << endl;
  double h, L, max_error;
  double *a, *u, *v, *f, *ft, *error;
  a = new double[n+2];
  f = new double[n+2];   u = new double[n+2];
  ft = new double[n+2];  error = new double[n+2];
  v = new double[n+2];
  L = 1.0;
  h = L/(n+1.0);
  max_error = 0.0;
  u[0] = 0;

 for (int i = 0; i < n+2; i++)
 {
      f[i] = 100*exp (-10*i*h)*h*h;
      v[i] = 1 - (1 - exp (-10))*i*h - exp (-10*i*h);
      a[i] = 2.0;
      a[i] = 2.0 - 1./(a[i-1]);
 }
 ft[1] = f[1];
 clock_t start, finish;
 start = clock();
 for (int i = 2; i < n+1; i++)
    {
      ft[i] = f[i] + ft[i-1]/a[i-1];
    }
  u[n] = ft[n]/a[n];
  for (int i = (n-1); i >= 1; i = i-1)
    {
      u[i] = (ft[i] + u[i+1])/a[i];
      error[i] =(abs((u[i] - v[i])/v[i]));
      if (error[i] > max_error)
      {
      max_error = error[i];
      }

    }
  finish = clock();
  double sec;
  sec = (finish - start);
  cout << sec/CLOCKS_PER_SEC << endl;
  //cout << max_error << endl;
 // for (int i = 0; i < n+2; i++)
 //    {
 //     outputFile << setiosflags(ios::showpoint | ios::uppercase);
 //outputFile << setprecision(10) << setw(20) << max_error << endl;
  //}
 delete [] a;   delete [] f;
 delete [] u;

 }
  outputFile.close();
  return 0;
}
