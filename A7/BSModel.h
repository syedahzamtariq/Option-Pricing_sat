#pragma once
#include <cmath>

using namespace std;

namespace fre {
    class BSModel {
    private:
    
        double sigma;
        double h;
        double r;

    public:
    
        BSModel() : sigma(0), h(0), r(0) {}
        BSModel(double vol, double h_, double r_) : sigma(vol), h(h_), r(r_) {}
        BSModel(const BSModel& model) : sigma(model.sigma), h(model.h), r(model.r) {}

        double GetU() {
            return exp(sigma * sqrt(h));
        }

        double GetD() {
            return 1 / (exp(sigma * sqrt(h)));
        }

        double GetR() {
            return exp(r * h);
        }
    };
}
