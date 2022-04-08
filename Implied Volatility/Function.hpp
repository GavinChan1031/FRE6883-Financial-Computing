//
//  Function.hpp
//  ImpliedVol
//
//  Created by Gavin Chen on 4/8/22.
//

#ifndef Function_hpp
#define Function_hpp

#include <stdio.h>
namespace fre{
class Function{
public:
    virtual double Value(double x) = 0;
    virtual double Deriv(double x) = 0;
    virtual ~Function(){}
};
}
#endif /* Function_hpp */
