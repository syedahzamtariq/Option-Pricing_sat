// EurpeanOption.cpp
//
//	Author: Daniel Duffy
//
// (C) Datasim Component Technology BV 2003
//



#ifndef EuropeanOption_cpp
#define EuropeanOption_cpp

#include "EuropeanOption.hpp"
#include <cmath>
#include <iostream>

//////////// Gaussian functions /////////////////////////////////

using namespace std;

double EuropeanOption::n(double x) const
{ 
    double A = 1.0 / sqrt(2.0 * 3.1415);
    return A * exp(-x * x * 0.5);
}

double EuropeanOption::N(double x) const
{ // The approximation to the cumulative normal distribution
    double a1 = 0.4361836;
    double a2 = -0.1201676;
    double a3 = 0.9372980;
    double k = 1.0 / (1.0 + (0.33267 * x));

    if (x >= 0.0)
    {
        return 1.0 - n(x) * (a1 * k + (a2 * k * k) + (a3 * k * k * k));
    }
    else
    {
        return 1.0 - N(-x);
    }
}

// Kernel Functions (Haug)

double EuropeanOption::CallPrice() const
{
    double tmp = sig * sqrt(T);
    double d1 = (log(U / K) + (b + (sig * sig) * 0.5) * T) / tmp;
    double d2 = d1 - tmp;

    return (U * exp((b - r) * T) * N(d1)) - (K * exp(-r * T) * N(d2));
}

double EuropeanOption::PutPrice() const
{
    double tmp = sig * sqrt(T);
    double d1 = (log(U / K) + (b + (sig * sig) * 0.5) * T) / tmp;
    double d2 = d1 - tmp;

    return (K * exp(-r * T) * N(-d2)) - (U * exp((b - r) * T) * N(-d1));
}

double EuropeanOption::CallDelta() const
{
    double tmp = sig * sqrt(T);
    double d1 = (log(U / K) + (b + (sig * sig) * 0.5) * T) / tmp;

    return exp((b - r) * T) * N(d1);
}

double EuropeanOption::PutDelta() const
{
    double tmp = sig * sqrt(T);
    double d1 = (log(U / K) + (b + (sig * sig) * 0.5) * T) / tmp;

    return exp((b - r) * T) * (N(d1) - 1.0);
}

/////////////////////////////////////////////////////////////////////////////////////

EuropeanOption::EuropeanOption()

{ // Initialise all default values
    // Default values
    r = 0.08;
    sig = 0.30;
    K = 65.0;
    T = 0.25;
    U = 60.0; // U == stock in this case
    b = r;
    // Black and Scholes stock option model (1973)
    dividend = 0;
    div_T = 0;

    // European Call Option (this is the default type)
    char type[] = "C";
    optType = new char[strlen(type) + 1];
    strcpy(optType, type);
    U = U - dividend * exp(-r * div_T);
}

EuropeanOption::EuropeanOption(const EuropeanOption &o2)
{
    r = o2.r;
    sig = o2.sig;
    K = o2.K;
    T = o2.T;
    U = o2.U;
    b = o2.b;
    dividend = o2.dividend;
    div_T = o2.div_T;

    U = U - dividend * exp(-r * div_T);
    optType = new char[strlen(o2.optType) + 1];
    strcpy(optType, o2.optType);
}

EuropeanOption::EuropeanOption(double r_, double sig_, double K_, double T_, double U_, char *const type)
{ // Create option type
    r = r_;
    sig = sig_;
    K = K_;
    T = T_;
    U = U_; // U == stock in this case
    b = r;  // Black and Scholes stock option model (1973)
    dividend = 0;
    div_T = 0;
    U = U - dividend * exp(-r * div_T);

    // European Call Option (this is the default type)
    optType = new char[strlen(type) + 1];
    strcpy(optType, type);
}

EuropeanOption::EuropeanOption(double r_, double sig_, double K_, double T_, double U_, double dividend_, double div_T_, char *const type)
{
    r = r_;
    sig = sig_;
    K = K_;
    T = T_;
    U = U_; // U == stock in this case
    b = r;  // Black and Scholes stock option model (1973)
    dividend = 0;
    div_T = 0;
    U = U - dividend * exp(-r * div_T);

    // European Call Option (this is the default type)
    optType = new char[strlen(type) + 1];
    strcpy(optType, type);

    dividend = dividend_;
    div_T = div_T_;
    U = U - dividend * exp(-r * div_T);
}

EuropeanOption &EuropeanOption::operator=(const EuropeanOption &option2)
{
    if (this == &option2)
        return *this;

    *this = EuropeanOption(option2);

    return *this;
}

// Functions that calculate option price and sensitivities
double EuropeanOption::Price() const
{
    if (*optType == 'C')
    {
        return CallPrice();
    }
    else
        return PutPrice();
}

double EuropeanOption::Delta() const
{
    if (optType == "C")
        return CallDelta();
    else
        return PutDelta();
}

// Modifier functions
void EuropeanOption::toggle()
{ // Change option type (C/P, P/C)
    if (*optType == 'C')
        *optType = 'P';
    else
        *optType = 'C';
}

#endif
