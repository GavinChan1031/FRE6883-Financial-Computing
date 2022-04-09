# Basket Option Pricing - Enhancing Monte Carlo Framework
For Basket Option pricing, we need multi-dimensional Black-Scholes model. Vector and Matrix calculation will be used in this section.

## Main class and functions
### Matrix
`Matrix.hpp` and `Matrix.cpp` defines Vector and Matrix. **Vector** is a STL vector of double and **Matrix** is a STL vector of vector. We also overload Arithmetic operater to vector and matrix calculation (+, -, *, /, ^, exp). Operator overloading customizes the C++ operators for operands of user-defined types. Matrix and Vector are passed to overloaded operator functions by reference.

### MCModel02
`MCModel02.hpp` and `MCModel02.cpp` define a class used to generate Sample Path and store the parameters Vector S0 & sigma, Matrix C and double r. By using the GenerateSamplePath function we can generate one sample path. Since C++ function rand() can generates uniformly distributed random numbers in range \[0, RAND_MAX\], we need to use Box-Muller Method and define Gauss() to generate random vector for normal distribution.

### PathDepOption02
`PathDepOption02.hpp` and `PathDepOption02.cpp` define the main pricing function _PriceByMC()_ and Pure Virtual function _Payoff()_. Class ArthmAsianCall is a derived class of PathDepOption and overrides the _Payoff()_ function.
