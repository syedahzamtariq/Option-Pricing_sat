#include "defInteg.h"
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
using namespace fre;



double myfunction(double x);




int main(){
    int N;
    double a=1.0,b=2.0;
    
    cout << "Enter an even number of steps for computing the approximation > ";
    cin >> N;
    
    DefInt MyInt(a,b,&myfunction);
    
    double trap = MyInt.FTrapezoid(N);
    double simpson = MyInt.FSimpson(N);
    
    cout << "The answer as per to Trapezoidal Approximation is: " << trap << endl;
    cout << "The answer as per Simpson's 1/3rd Approximation is: " << simpson << endl;
    /*
    Enter an even number of steps for computing the approximation > 1000
    The answer as per to Trapezoidal Approximation is: 2.41667
    The answer as per Simpson's 1/3rd Approximation is: 2.41667
    */

    return 0;
}



double myfunction(double x){
    return pow(x,3) - pow(x,2) + 1;
    
    
}