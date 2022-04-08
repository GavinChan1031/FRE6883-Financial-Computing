//
//  GmtrAsianCall.hpp
//  AsianOption
//
//  Created by Gavin Chen on 4/8/22.
//

#ifndef GmtrAsianCall_hpp
#define GmtrAsianCall_hpp

#include <stdio.h>
#include "PathDepOption.hpp"
#include "EurCall.hpp"
namespace fre{
class GmtrAsianCall:public PathDepOption{
public:
    GmtrAsianCall(double T_,double K_,int m_):PathDepOption(T_,K_,m_){}
    double Payoff(const SamplePath& S) const;
    double PriceByBSFormula(const MCModel& Model);
    double DeltaByBSFormula(const MCModel& Model);
};
}

#endif /* GmtrAsianCall_hpp */
