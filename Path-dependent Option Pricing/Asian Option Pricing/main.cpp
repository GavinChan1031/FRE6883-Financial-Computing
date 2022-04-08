//
//  main.cpp
//  AsianOption
//
//  Created by Gavin Chen on 4/8/22.
//

#include <iostream>
#include "PathDepOption.hpp"
#include "GmtrAsianCall.hpp"

using namespace std;
using namespace fre;

int main() {
    double S0=100.0, r=0.03, sigma=0.2;
    MCModel Model(S0,r,sigma);
    
    double T =1.0/12.0, K=100.0;
    int m=30;
    ArthmAsianCall Option(T,K,m);
    GmtrAsianCall CVOption(T,K,m);
    
    long N=30000;
    double epsilon =0.001;
    Option.PriceByVarRedMC(Model, N, CVOption, epsilon);
    cout << "Price by Control Variate = " << Option.GetPrice() << endl;
    cout << "Error = " << Option.GetPricingError() << endl;
    cout << "Delta = " << Option.GetDelta() << endl << endl;
    
    Option.PriceByMC(Model, N, epsilon);
    cout << "Price by direct MC = " << Option.GetPrice() << endl;
    cout << "Error = " << Option.GetPricingError() << endl;
    cout << "Delta = " << Option.GetDelta() << endl;
}

//Results:

//Price by Control Variate = 1.42586
//Error = 0.000136582
//Delta = 0.520031

//Price by direct MC = 1.41843
//Error = 0.0119625
//Delta = 0.525464
//Program ended with exit code: 0
