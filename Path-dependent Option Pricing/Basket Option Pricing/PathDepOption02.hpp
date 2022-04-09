//
//  PathDepOption02.hpp
//  HW12
//
//  Created by Gavin Chen on 4/9/22.
//

#ifndef PathDepOption02_hpp
#define PathDepOption02_hpp

#include <stdio.h>
#include "MCModel02.hpp"
namespace fre {
class PathDepOption{
protected:
    double T;
    double K;
    double Price;
    int m;
    Vector delta;
public:
    PathDepOption(double T_, double K_, int m_) : Price(0.0), T(T_), K(K_), m(m_) {}
    double PriceByMC(MCModel& Model, long N, double epsilon);
    virtual ~PathDepOption() {}
    virtual double Payoff(const SamplePath& S) const = 0;
    Vector GetDelta(){return delta;}
};

class ArthmAsianCall : public PathDepOption{
public:
    ArthmAsianCall(double T_, double K_, int m_) : PathDepOption(T_, K_, m_) {}
    double Payoff(const SamplePath& S) const;
};
}

#endif /* PathDepOption02_hpp */
