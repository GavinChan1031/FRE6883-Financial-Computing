//
//  EurCall.hpp
//  ImpliedVol
//
//  Created by Gavin Chen on 4/8/22.
//

#ifndef EurCall_hpp
#define EurCall_hpp

#include <stdio.h>
#include "NonlinearSolver.hpp"

namespace fre{
class EurCall{
private:
    double T,K;
public:
    EurCall(double T_ ,double K_):T(T_),K(K_){}
    double d_plus(double S0, double sigma, double r);
    double d_minus(double S0, double sigma, double r);
    double PriceByBSFormula(double S0, double sigma, double r);
    double VegaByBSFormula(double S0, double sigma, double r);
};

class Intermediary:public EurCall, public Function{
private:
    double S0,r;
public:
    Intermediary(double S0_, double r_, double T_, double K_):EurCall(T_, K_), S0(S0_), r(r_){}
    double Value(double sigma);
    double Deriv(double sigma);
};
}


#endif /* EurCall_hpp */
