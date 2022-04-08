# Implied Volatility of European Option.

In this folder we use C++ to calculate the implied volatility of European call option.

We use virtual base class and virtual inheritance. In this way we can easily expand the code to different application scenarios.

## Classes and Functions 

### Function
Function is a **pure virtual class** and we need to use specific functions to override _Function_. In this section we replace _Value()_ with _PriceByBSFormula()_ and _Deriv()_ with _VegaByBSFormula()_. With the pure virtual class we can easily extend the code to calculate other non-linear solver problems.

### NonlinearSolver
NonlinearSolver consists of one class with two important functions: _SolveByBisect()_ and _SolveByNR_. Bisect and Newton-Raphson are two commonly used methods for non-linear solver questions. 

### EurCall
EurCall consists of three components: independent _N(x)_ function used to calculate the value of cumulative normal distribution; class _EurCall_ to calculate d+, d-, Price and Vega by Black-Scholes option pricing formula; and class Intermediary to associate _Function_ with _Eurcall_.

### main
Assume the parameters and calculate the implied volatility.

