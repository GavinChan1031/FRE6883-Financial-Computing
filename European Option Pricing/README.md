# European Option Pricing Framework

This folder includes the European Option Pricing Framework. 

## Main files

### BinomialTreeModel02
A class for European Option pricing using Binomial Tree Model. In this class, private data members are S0(stock price at time 0), U(up factor), D(down factor) and R(1+risk free rate). We define several functions and explain for some important functions below.

- RiskNeutProb(): Calculate the risk neutral probability
- CalculateAssetPrice(): Calculate Asset price at each nodes.

We also define functions to get the private data members since they are private outside the class.

## 
