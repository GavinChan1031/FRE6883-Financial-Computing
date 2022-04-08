# American Option Pricing Framework

This folder includes the American Option Pricing Framework. The pricing framework is slightly different from European Option Pricing and we use the Snell method to price American Option.

## Class and Function Explanation

### BinLattice
BinLattice is a class template and only have a header file. A class template can only be compiled after an object has been declared using the template with a specific data type. We store the value of every node by using vector of vector. In the meantime we define some useful function: set the size of vector of vector _SetN(N)_, set or change node value _SetNode(n,i,x)_, get node value _GetNode(n,i)_, display the pricing tree and stopping tree _Display()_. 

### Option
Option contains several classes used to calculate option payoff. ___Option___ is a parent class with child class ___Call___ and ___Put___. OptionCalculation is a class used to calculate option price for both European and American Option. For European options, _PriceByCRR()_ is used and for American options, _PriceBySnell()_ is used. _PriceBySnell_ uses vector of vector and stores every value on the Binomial Tree, however _PriceByCRR_ uses vector and overwrites the previous value of the Binomial Tree.

### BinomialTreeModel
BinomialTreeModel class is used to calculate asset prices and validate input data. In this class, private data members are S0(stock price at time 0), U(up factor), D(down factor) and R(1+risk free rate). Private data are useful for information hiding compared with public data. In this class, we use: RiskNeutProb() to calculate the risk-neutral probability; CalculateAssetPrice() to calculate Asset price at each node; ValidateInputData() to check whether there exist arbitrage opportunites for input data; UpdateBinomialTreeModel() to Update the private data members; and also define functions to get the private data members since they are private outside the class.

### Option Pricer
Main function uses all the classes and functions mentioned above. Results are stored in 'Results.txt' file.
