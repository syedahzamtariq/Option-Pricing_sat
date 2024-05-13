#include "BullSpread.h"
namespace fre {
    double BullSpread::Payoff(double z) const{
        if (z<=K1){
            return 0.0;
        }
        else if (K1<z && z<K2){
            return z-K1;
        }
        else{
            return K2-K1;
        }
    }
}