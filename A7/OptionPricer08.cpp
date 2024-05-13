#include <iostream>
#include <iomanip>
#include <fstream>
#include "BinomialTreeModel02.h"
#include "Option08.h"
#include "BinLattice02.h"
#include "BSModel.h"

using namespace std;
using namespace fre;

int main() {
    double S0 = 106.0;
    double r = 0.058;
    double sigma = 0.46;
    double T = (double)(9) / 12;
    double K = 100.0;
    int N = 8;

    cout << setiosflags(ios::fixed) << setprecision(5);

    BSModel bsmodel = BSModel(sigma, T / N, r);
    double U = bsmodel.GetU();
    double D = bsmodel.GetD();
    double R = bsmodel.GetR();

    BinomialTreeModel Model(S0, U, D, R);

    Call call(N, K);
    OptionCalculation callCalculation(&call);

    cout<<"S0 = " << S0 <<endl;
    cout<<"r = " << r <<endl;
    cout<<"sigma = " << sigma <<endl;
    cout<<"T = " << T<<endl;
    cout<<"K = " << K <<endl;
    cout<<"N = " << N << endl;
    cout<<""<<endl;
    
    cout<<"U = " << U <<endl;
    cout<<"D = " << D <<endl;
    cout<<"R = " << R << endl;
        cout<<""<<endl;

    cout<< "American call option price = " << fixed << setprecision(3) << callCalculation.PriceBySnell(Model) << endl;

    return 0;
}
/*

Output

S0 = 106.00000
r = 0.05800
sigma = 0.46000
T = 0.75000
K = 100.00000
N = 8

U = 1.15125
D = 0.86862
R = 1.00545

American call option price = 21.682

*/