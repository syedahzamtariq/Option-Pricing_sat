#pragma once
#include "Option05.h"

#include "BinomialTreeModel02.h"

namespace fre {
    class BearSpread : public EurOption{
        private:
        
            double K1; 
            double K2; 
        public:
        
            BearSpread(int N_, double K1_, double K2_) : EurOption(N_), K1(K1_), K2(K2_) {};
            ~BearSpread() {};
            double Payoff(double z) const;
    };
}