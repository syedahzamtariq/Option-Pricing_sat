#include <iostream>
#include <iomanip>
#include <fstream>

#include "BinomialTreeModel02.h"
#include "Option08.h"
#include "BinLattice02.h"

using namespace std;
using namespace fre;

int main() {
    int N = 8;
    
    double U = 1.15125;
    double D = 0.86862;
    double R = 1.00545;
    double S0 = 106.00;
    double K = 100.00;
    
    BinomialTreeModel Model(S0, U, D, R);
    ofstream fout;
    
    fout.open("Results.txt");

    Call call(N, K);
    
    OptionCalculation callCalculation(&call);
    BinLattice<double> PriceTree;
    
    BinLattice<double> XTree;
    BinLattice<double> YTree;

    fout << "European call option prices by PriceByCRR: " << fixed << setprecision(3) << callCalculation.PriceByCRR(Model) << endl;
    fout << "European call prices by HW6 PriceByCRR: " << fixed << setprecision(3) << callCalculation.PriceByCRR(Model, PriceTree, YTree, XTree) << endl << endl;

    fout << "Stock positions in replicating strategy:" << endl << endl;
    XTree.Display(fout);
    
    fout << "Money market account positions in replicating strategy:" << endl << endl;
    YTree.Display(fout);

    Put put(N, K);
    
    OptionCalculation putCalculation(&put);
    
    BinLattice<double> PricePutTree;
    
    BinLattice<double> XPutTree;
    
    BinLattice<double> YPutTree;

    fout << "European put option prices by PriceByCRR: " << fixed << setprecision(3) << putCalculation.PriceByCRR(Model) << endl;
    
    fout << "European put prices by HW6 PriceByCRR: " << fixed << setprecision(3) << putCalculation.PriceByCRR(Model, PricePutTree, YPutTree, XPutTree) << endl << endl;

    fout << "Stock positions in replicating strategy:" << endl << endl;
    XPutTree.Display(fout);
    
    fout << "Money market account positions in replicating strategy:" << endl << endl;
    YPutTree.Display(fout);

    return 0;
}
/*

Output:
European call option prices by PriceByCRR: 21.681
European call prices by HW6 PriceByCRR: 21.681

Stock positions in replicating strategy:

          0.672
          0.520          0.794
          0.341          0.664          0.898
          0.164          0.483          0.810          0.970
          0.039          0.265          0.657          0.932          1.000
          0.000          0.071          0.421          0.847          1.000          1.000
          0.000          0.000          0.128          0.657          1.000          1.000          1.000
          0.000          0.000          0.000          0.231          1.000          1.000          1.000          1.000
          0.000          0.000          0.000          0.000          0.000          0.000          0.000          0.000          0.000

Money market account positions in replicating strategy:

        -49.518
        -35.805        -64.687
        -21.679        -51.260        -79.722
         -9.548        -34.849        -69.325        -91.698
         -2.047        -17.648        -53.570        -86.893        -97.849
          0.000         -4.252        -32.120        -77.029        -98.383        -98.383
          0.000          0.000         -8.830        -57.299        -98.919        -98.919        -98.919
          0.000          0.000          0.000        -18.339        -99.458        -99.458        -99.458        -99.458
          0.000          0.000          0.000          0.000          0.000          0.000          0.000          0.000          0.000

European put option prices by PriceByCRR: 11.426
European put prices by HW6 PriceByCRR: 11.426

Stock positions in replicating strategy:

         -0.328
         -0.480         -0.206
         -0.659         -0.336         -0.102
         -0.836         -0.517         -0.190         -0.030
         -0.961         -0.735         -0.343         -0.068          0.000
         -1.000         -0.929         -0.579         -0.153          0.000          0.000
         -1.000         -1.000         -0.872         -0.343          0.000          0.000          0.000
         -1.000         -1.000         -1.000         -0.769          0.000          0.000          0.000          0.000
          0.000          0.000          0.000          0.000          0.000          0.000          0.000          0.000          0.000

Money market account positions in replicating strategy:

         46.227
         60.462         31.580
         75.113         45.531         17.070
         87.771         62.470         27.994          5.621
         95.802         80.202         44.280         10.956          0.000
         98.383         94.131         66.262         21.354          0.000          0.000
         98.919         98.919         90.089         41.620          0.000          0.000          0.000
         99.458         99.458         99.458         81.119          0.000          0.000          0.000          0.000
          0.000          0.000          0.000          0.000          0.000          0.000          0.000          0.000          0.000




*/