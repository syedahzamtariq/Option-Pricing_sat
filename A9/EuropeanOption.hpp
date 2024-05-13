// EuropeanOption2.hpp
//
// Class that represents solutions to European options. This is
// an implementation using basic C++ syntax only. It has been
// written for pedagogical reasons
//
// (C) Datasim Component Technology BV 2003-2006
//

#ifndef EuropeanOption_hpp
#define EuropeanOption_hpp

#include <string.h>
#include <stdio.h>
using namespace std;

class EuropeanOption
{
private:
    double r;        // Interest rate
    double sig;      // Volatility
    double K;        // Strike price
    double T;        // Expiry date
    double U;        // Current underlying price (e.g. stock, forward)
    double b;        // Cost of carry
    char *optType;   // Option name (call, put)
    double dividend;
    double div_T;

    // Gaussian functions
    double n(double x) const;
    double N(double x) const;


public: // For TEST purposes only

    EuropeanOption();
    EuropeanOption(const EuropeanOption &o2);
    EuropeanOption(double r_, double sig_, double K_, double T_, double U_, char *const type);
    EuropeanOption(double r_, double sig_, double K_, double T_, double U_, double dividend_, double div_T_, char *const type);

    // 'Kernel' functions for option calculations
    double CallPrice() const;
    double PutPrice() const;
    double CallDelta() const;
    double PutDelta() const;
    double CallGamma() const;
    double PutGamma() const;
    double CallVega() const;
    double PutVega() const;

    EuropeanOption &operator=(const EuropeanOption &option2);

    // Functions that calculate option price and sensitivities
    double Price() const;
    double Delta() const;

    // Modifier functions
    void toggle();
    // Change option type (C/P, P/C)
    char GetOptType()
    {
        return *optType;
    }


    ~EuropeanOption()
    {
        if (optType != NULL)
        {
            delete[] optType;
        }
    }
};

#endif
