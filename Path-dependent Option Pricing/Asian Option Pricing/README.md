# Asian Option Pricing Framework: Monte Carlo Simulation and Control Variate Technique
In this folder we use Monte Carlo Simulation the simulate the payoff of Asian Option, and control variate technique to reduce variance of simulation.

## Main class and function

### MCModel
MCModel is a class used to generate Sample Path. By using the _GenerateSamplePath_ function we can generate one sample path. Since C++ function _rand()_ can generates uniformly distributed random numbers in range \[0, RAND_MAX\], we need to use Box-Muller Method and define _Gauss()_ to generate random number (z) for normal distribution.

### PathDepOption
`PathDepOption`
