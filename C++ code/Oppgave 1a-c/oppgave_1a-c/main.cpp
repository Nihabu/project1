#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include "time.h"
using namespace std;

int main(){
  ofstream outputFile;
  outputFile.open("oppgave_1a_c.txt");   //create new file
  //declare pointers and define variables
  int n;
  n = 100;
  double h, L;
  double *a, *u, *v, *f, *ft;
  a = new double[n+2];
  f = new double[n+2];   u = new double[n+2];
  ft = new double[n+2];  v = new double[n+2];
  L = 1.0;          //length of x-array
  h = L/(n+1.0);    //steplength
  u[0] = 0;         //discretized approx. to exact solution v
  
 //for-loop runs from 0 to n+2 with steplengths 1
 for (int i = 0; i < n+2; i++)
 {
      f[i] = 100*exp (-10*i*h)*h*h; //source term
      a[i] = 2.0;
      a[i] = 2.0 - 1./(a[i-1]);     //the elements on the diagonal in our matrix
 }
 ft[1] = f[1];     //define first element of f-tilde
 
 for (int i = 2; i < n+1; i++)  //loop runs from 2 -> n+1
    {
      ft[i] = f[i] + ft[i-1]/a[i-1]; //calculate f-tilde values
    }
  u[n] = ft[n]/a[n];    //set last element in discretized approx.
  //loop for backward substitution, i decreases with every iteration
  for (int i = (n-1); i >= 1; i = i-1)
    {
      u[i] = (ft[i] + u[i+1])/a[i]; //calculate discretized values
    }
  //loop from 0 -> n+2, write u-values to file
  for (int i = 0; i < n+2; i++)
  {
      outputFile << setiosflags(ios::showpoint | ios::uppercase);
      outputFile << setprecision(10) << setw(20) << u[i] << endl;
  }
 delete [] a;   delete [] f;
 delete [] u;
return 0;
}
