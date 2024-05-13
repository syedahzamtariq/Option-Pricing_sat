#include <iostream>
#include <iomanip>
#include "BinomialTreeModel02.h"
#include "Option05.h"
#include "BullSpread.h"
#include "BearSpread.h"
using namespace std;
using namespace fre;



int main(){ 
    int N = 8;
    double U = 1.15125, D = 0.86862, R = 1.00545;
    double S0 = 106.00, K = 100.00;
    BinomialTreeModel Model(S0, U, D, R);
    
    Call call(N, K);
    OptionCalculation callCalc(&call);
    cout << "European call option price = " << fixed << setprecision(2) << callCalc.PriceByCRR(Model) << endl;
    
    Put put(N, K);
    OptionCalculation putCalc(&put);
    cout << "European put option price = "<< fixed << setprecision(2) << putCalc.PriceByCRR(Model) << endl;
    
    
    double K1 = 100;
    double K2 = 110;
 
    //Bull spread
    BullSpread bullSpread(N, K1, K2);
    OptionCalculation bullSpreadCalc(&bullSpread);
    cout << "European bull spread option price = "<< fixed << setprecision(2) << bullSpreadCalc.PriceByCRR(Model) << endl;
    
    //Bear spread
    BearSpread bearSpread(N, K1, K2);
    OptionCalculation bearSpreadCalc(&bearSpread);
    cout << "European bear spread option price = "<< fixed << setprecision(2) << bearSpreadCalc.PriceByCRR(Model) << endl;
    
    /*
    Output
    European call option price = 21.68
    European put option price = 11.43
    European bull spread option price = 4.72
    European bear spread option price = 4.86
    */
    
    return 0;
}