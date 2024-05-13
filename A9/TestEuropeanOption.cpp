// TestEuropeanOption.cpp
// Test program for the exact solutions of European options.
// (C) Datasim Component Technology BV 2003-2006
//

#include "EuropeanOption.hpp"
#include <iostream>

int main() {
    // Call option on a stock
    EuropeanOption call_Option;
   
    cout << "Q1: Call option on a stock: " << call_Option.Price() << endl;
    
    char type[] = "P";
    
    EuropeanOption put_Option(0.10, 0.30, 50.0, 0.25, 50.0, type);
    cout << "Q2: Put option on a stock: " << put_Option.Price() << endl;

    // Put option on a stock index
    EuropeanOption put_Option_2(0.10, 0.30, 50.0, 0.25, 50.0, 1.5, 0.1667, type);
    cout << "Q3: Put option with dividend: " << put_Option_2.Price() << endl;

    return 0;
}
/*
Output obtained:

Q1: Call option on a stock: 2.13293
Q2: Put option on a stock: 2.37561
Q3: Put option with dividend: 3.03039


*/
