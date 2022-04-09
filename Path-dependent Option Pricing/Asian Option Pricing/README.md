# Asian Option Pricing Framework: Monte Carlo Simulation and Control Variate Technique
In this folder we use Monte Carlo Simulation the simulate the payoff of Asian Option, and control variate technique to reduce variance of simulation.

## Main class and function

### MCModel
`MCModel.hpp` is a class used to generate Sample Path and store the parameters S0, r, sigma. By using the **GenerateSamplePath** function we can generate one sample path. Since C++ function _**rand()**_ can generates uniformly distributed random numbers in range \[0, RAND_MAX\], we need to use Box-Muller Method and define _**Gauss()**_ to generate random number (z) for normal distribution.

### PathDepOption
`PathDepOption.hpp` consists of three class.
1. **Parent Class**: PathDepOption.
  - Main Pricing Function **PriceByMC()**: Monte Carlo pricing function can be shared by different types of path-dependent options.
  - Control Variate Func **PriceByVarRedMC()**: Control Variate pricing function by using child class DifferenceOfOptions and PriceByBSFormula (Geometric Asian Call can be computed analytically).
  - Pure Virtual function **Payoff()**: PriceByMC() uses different implementation of Payoff() depending on the derived classes.
  - Virtual **PriceByBSFormula()**: function to calculate Geometric Asian Call Price from Black-Scholes formula.

2. **Child Class**:
  a) DifferenceOfOptions. **Payoff()** of difference between Arithmetic Asian Call and Geometric Asian Call. This class combines two options and uses pointers \*Ptr1 and \*Ptr2 to access the payoff function.
  b) ArthmAsianCall. **Payoff()** of arithmetic Asian calls.

Polymorphism is used here for **Payoff()** function and **PriceByBSFormula()**.

### GmtrAsianCall
`GmtrAsianCall.hpp` is a class to calculate the analytical solution for European Asian call. We only calculate option price and delta here. And we can extend the code to calculate other greeks as well. Note that we need to adjust parameters for European Asian Call when applying BS Formula.

### EurCall
`EurCall.hpp` consists of Black-Scholes formula for option price and delta.
