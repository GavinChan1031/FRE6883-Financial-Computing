//
//  OptionPricer.cpp
//  HW4
//
//  Created by Gavin Chen on 2/28/22.
//

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "BinomialTreeModel02.hpp"
#include "Option05.hpp"

using namespace std;
using namespace fre;

int main()
{
    int N=8;
    double U=1.15125, D=0.86862, R=1.00545;
    double S0=106.00, K=100.00;
    double K1=100.00, K2=110.00;
    BinomialTreeModel Model(S0,U,D,R);
    Call call(N,K);
    OptionCalculation callCalculation(&call);
    cout << "European Call Price = " << fixed << setprecision(2) << callCalculation.PriceByCRR(Model) << endl;
    
    Put put(N,K);
    OptionCalculation putCalculation(&put);
    cout << "European Put Price = " << fixed << setprecision(2) << putCalculation.PriceByCRR(Model) << endl;
    
    BullSpread bullspread(N,K1,K2);
    OptionCalculation bullspreadCalculation(&bullspread);
    cout << "European Bull Spread option price = " << fixed << setprecision(2) << bullspreadCalculation.PriceByCRR(Model) << endl;
    
    BearSpread bearspread(N,K1,K2);
    OptionCalculation bearspreadCalculation(&bearspread);
    cout << "European Bear Spread Option price = " << fixed << setprecision(2) << bearspreadCalculation.PriceByCRR(Model) << endl;
    return 0;
    
}

// Results are as follows:

//European Call Price = 21.68
//European Put Price = 11.43
//European Bull Spread option price = 4.72
//European Bear Spread Option price = 4.86
//Program ended with exit code: 0
