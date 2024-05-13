#pragma once
#include <cmath>

namespace fre {
    
    class Function {
    public:
    
        virtual double Value(double x) = 0;
        virtual double Deriv(double x) = 0;
        virtual ~Function() {}
    };

    class F1 : public Function {
    public:
    
        double Value(double x);
        double Deriv(double x);
    };

    class F2 : public Function {
    private:
    
        double a;

    public:
    
        F2(double a_) { a = a_; }
        double Value(double x);
        double Deriv(double x);
    };

    class CouponFunc : public Function {
    private:
    
        double FV;       // face value
        double T;        // maturity
        double coupon;

    public:
    
        CouponFunc(double FV_, double T_, double coupon_) : FV(FV_), T(T_), coupon(coupon_) {}

        double Value(double yield) {
            double price = FV * exp((-1) * yield * T);
            for (double t = 1.0; t <= T; t += 1.0) {
                price += coupon * exp((-1) * yield * t);
            }
            return price;
            
        }

        double Deriv(double yield) {
            double price = FV * exp((-1) * yield * T) * (-T);
            for (double t = 1.0; t <= T; t += 1.0) {
                price += coupon * exp((-1) * yield * t) * (-t);
            }
            return price;
        }
    };
}
