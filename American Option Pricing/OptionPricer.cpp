//
//  OptionPricer.cpp
//  AmOption
//
//  Created by Gavin Chen on 4/7/22.
//

#include <stdio.h>
#include "BinomialTreeModel.hpp"
#include "Option.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
using namespace fre;
int main(){
    int N = 8;
    double U = 1.15125, D = 0.86862, R = 1.00545;
    double S0 = 106.00, K = 100.00;
    BinomialTreeModel Model(S0, U, D, R);
    Call call(N,K);
    OptionCalculation callCalculation(&call);
    Put put(N,K);
    OptionCalculation putCalculation(&put);
    BinLattice<double> PriceTree;
    BinLattice<bool> StoppingTree;
    
    ofstream fout;
    fout.open("/Users/gc/Desktop/Master/S2 Financial Computing/Course Code/Results.txt");
    
    fout << "European call price by CRR: " << fixed << setprecision(3) << callCalculation.PriceByCRR(Model) << endl << endl;
    fout << "American call price by Snell: " << fixed << setprecision(3) << callCalculation.PriceBySnell(Model, PriceTree, StoppingTree) << endl << endl;
    fout << "American call price tree: " << endl << endl;
    PriceTree.Display(fout);
    fout << "American call stopping tree: " << endl << endl;
    StoppingTree.Display(fout);

    
    fout << "European put price by CRR: " << fixed << setprecision(3) << putCalculation.PriceByCRR(Model) << endl << endl;
    fout << "American put price by Snell: " << fixed << setprecision(3) << putCalculation.PriceBySnell(Model, PriceTree, StoppingTree) << endl << endl;
    fout << "American put price tree: " << endl << endl;
    PriceTree.Display(fout);
    fout << "American put stopping tree: " << endl << endl;
    StoppingTree.Display(fout);
    
    return 0;
}
