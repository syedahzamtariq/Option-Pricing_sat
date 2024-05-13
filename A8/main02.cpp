#include <iostream>
#include <iomanip>

#include "Function02.h"
#include "NonlinearSolver02.h"

using namespace std;
using namespace fre;

int main() {
    double F = 100.0;
    double T = 3.0;
    double C = 1.2;
    double P = 98.56;
    
    double Acc = 0.0001;
    double LEnd = 0.0;
    double REnd = 1.0;
    double Guess = 0.2;

    CouponFunc MyF3(F, T, C);
    
    NonlinearSolver solver_(P, LEnd, REnd, Acc, Guess);
    //Output
    cout << "Yield by bisection method: " << fixed << setprecision(4)
         << solver_.SolveByBisect(&MyF3);
    cout << "\nYield by Newton-Raphson method: " << fixed << setprecision(4)
         << solver_.SolveByNR(&MyF3) << endl;

    return 0;
}

/*
Output Obtained

Yield by bisection method: 0.0168
Yield by Newton-Raphson method: 0.0168

*/