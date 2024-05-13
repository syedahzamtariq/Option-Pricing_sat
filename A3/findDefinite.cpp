#include "defInteg.h"
#include <iostream>
#include <cmath>
using namespace std;

namespace fre{
    DefInt::DefInt(double aa, double bb, double (*functionInput)(double x)){
        a = aa;
        b = bb;
        Function = functionInput;
    }
    
    double DefInt::FTrapezoid(int N){
        double h = FH(N);
        double f_of_x [N+1];
        int size = sizeof(f_of_x)/sizeof(double);
        
        for(int i=0; i<size; i++){
            f_of_x[i]=Function(a+h*i);
        }
        
        double apx = 0.0;
        
        for(int i=1; i<size; i++){
            apx+=(h/2)*(f_of_x[i]+f_of_x[i-1]);
        }
        
        return apx;
    }

    double DefInt::FSimpson(int N){
        double h = FH(N);
        double f_of_x [N+1];
        int size = sizeof(f_of_x)/sizeof(double);
        
        for(int i=0; i<size; i++){
            f_of_x[i]=Function(a+h*i);
        }
        
        double apx = (h/3)*(f_of_x[0]+f_of_x[N]);
        
        for(int i=1; i<size-1; i++){
            if(i%2!=0){
                apx+=(h/3)*(4*f_of_x[i]);   
            }else{
                apx+=(h/3)*(2*f_of_x[i]);
            }
        }
        
        return apx;
    }
    
    double DefInt::FH(int N){
        double h = double((b-a))/double(N);
        return h;
    }
}