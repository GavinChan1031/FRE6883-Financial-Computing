//
//  Matrix.hpp
//  HW12
//
//  Created by Gavin Chen on 4/9/22.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
namespace fre {
    typedef vector<double> Vector;
    typedef vector<Vector> Matrix;

    Vector operator-(const Vector& V, const double& a);
    Vector operator/(const Vector& V, const Vector& W);

    // overload operators as independent functions
    Vector operator*(const Matrix& C, const Vector& V);
    Vector operator*(const double& a, const Vector& V);
    Vector operator*(const Vector& V, const Vector& W);
    Vector operator+(const double& a, const Vector& V);
    Vector operator+(const Vector& V, const Vector& W);  // referece to const for V and W, V + W -> U, V and W do not change
    Vector exp(const Vector& V);
    double operator^(const Vector& V, const Vector& W); // scalar operator
    ostream& operator<<(ostream& out, Vector& V);    // Overload cout for Vector
    ostream& operator<<(ostream& out, Matrix& W);    // Overload cout for Matrix
}


#endif /* Matrix_hpp */
