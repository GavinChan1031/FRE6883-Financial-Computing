# European Option Pricing Framework

This folder includes the European Option Pricing Framework. 

## Three important concepts for C++ 

C++ is an Objected-Oriented programming language, therefore we need to grasp some important features and concepts for C++. An object has its own state and operations and performs as an instance of a class.

### Encapsulation (hasA)
Encapsulation enables the computer to combine data with operations. Data represent the properties, state or characteristics of objects. Operations are permissible behaviors that are controlled through the member functions. An object is an encapsulation of both functions and data.

### Inheritance (IsA)
Inheritance denotes the ability to derive new objects from old ones. Here we use parent class and child class to show this relationship. Inheritance permits objects of a more specific class to inherit the properties (data) and behaviors (functions) from a more general (base) class. It also defines the hierarchical relationship between objects.

### Polymorophism
Polymorphism allows different objects to interpret functions differently. There are three conditions must be satisfied to use Polymorphism:
- Member function **overriding**
- The overridden function must be **virtual**
- Invoke overridden function via **base class reference or pointer**

## Main classes and functions explanation

### BinomialTreeModel02
**BinomialTreeModel** consists of only one class and it is used to calculate asset price and validate input data. In this class, private data members are S0(stock price at time 0), U(up factor), D(down factor) and R(1+risk free rate). Private data are useful for information hiding compared with public data. We define several functions and explain some important functions below.

- RiskNeutProb(): Calculate the risk neutral probability
- CalculateAssetPrice(): Calculate Asset price at each nodes.
- ValidateInputData(): Check whehter there exists arbitrage opportunites for input data.
- UpdateBinomialTreeModel(): Update the private data members.

We also define functions to get the private data members since they are private outside the class.

### Option05
**Parent class: EurOption**: Parent class for all kinds of European Options. This class includes a pure virtual _payoff()_ function which allows different types of European options to calculate their payoff. 

**Child class**: Child class includes class Call, Put, BullSpread, BearSpread, Strangle, Butterfly, Digit etc (inheritance). Different child class can have their own _payoff()_ function (polymorphism) which override the pure virtual function in parent class(abstract class) and become a concrete class. 

**OptionCalculation**: This class is designed for calculating option price using the parameters from the BinomialTreeModel. OptionCalculation has a pointer pointing to the base class EurOption. The pointer will be associated with either the address of different European Options when an object of OptionCalculation is created and the corresponding _payoff()_ function will be used.

### OptionPricer
OptionPricer is the main() function defining private data members and using class in BinimialTreeModel02 and Option05.


