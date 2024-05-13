#include "BearSpread.h"

namespace fre {
    double BearSpread::Payoff(double z) const{
        if (z<=K1){
            return K2-K1;
        }
        else if (K1<z && z<K2){
            return K2-z;
        }
        else{
            return 0;
        }
    }
}