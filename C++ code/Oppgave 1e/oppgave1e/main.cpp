#include <iostream>
#include "armadillo"

using namespace std;
using namespace arma;

mat A;
vec b;
int i;

int main()
{
    for(i=0; i<=3; i++){
        b[i] = 2;
    }

    A = diagmat(b);
    cout << A << endl;
    return 0;
}
