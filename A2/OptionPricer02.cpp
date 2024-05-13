#include "BinomialTreeModel.h"
#include "Option02.h"
#include <iostream>
#include <iomanip>
using namespace std;
using namespace fre;
int main()
{
 double S0 = 0.0, U = 0.0, D = 0.0, R = 0.0;
 if (GetInputData(S0, U, D, R) != 0)
 {
     return -1;
 }
 double K = 0.0; //strike price
 int N = 0; //steps to expiry
 cout << "Enter call option data:" << endl;
 GetInputData(N, K);
 double* optionPrice = NULL;
 
 optionPrice = PriceByCRR(S0, U, D, R, N, K, CallPayoff);
 cout << "European Call option price = " << fixed << setprecision(2)<< optionPrice[0] << endl;
 delete [] optionPrice;
 optionPrice = PriceByCRR(S0, U, D, R, N, K, PutPayoff);
 cout << "European Put option price = " << fixed << setprecision(2) << optionPrice[0] << endl;
 delete [] optionPrice;
 optionPrice = PriceByCRR(S0, U, D, R, N, K, DigitCallPayoff);
 cout<<"Digital Call payoff = " <<fixed<<setprecision(2)<<optionPrice[0]<<endl;
 delete [] optionPrice;
 optionPrice = PriceByCRR(S0, U, D, R, N, K, DigitPutPayoff);
 cout<<"Digital Call payoff = " <<fixed<<setprecision(2)<<optionPrice[0]<<endl;
 delete[] optionPrice;
 optionPrice=NULL;
 return 0;
}
/*
European call option price = 21.68
*/
