#ifndef BIG_INTEGER_ARITHMETIC_HPP
#define BIG_INTEGER_ARITHMETIC_HPP

#include "arithmetic-expression.hpp"
#include "stack.hpp"

// A class to perform arithmetic operations on big integer arithmetic expressions
class BigIntegerArithmetic
{
private:
    // Arithmetic expression to solve
    ArithmeticExpression expression;
    // Private method to remove sign and any leading zeroes from a string (value)
    std::string removeSignAndLeadingZeros(std::string string);

public:
    // Constructor to initialize the class attributes
    BigIntegerArithmetic(ArithmeticExpression expression);
    // Method to compare the operand1 and operand2
    // Returns 0 if operand1 == operand2, -1 if operand1 < operand2, 1 if operand1 > operand2
    int operandComp(std::string operand1, std::string operand2);
    // Solves the arithmetic expression and returns the result in formatted string
    std::string getResults();
};

#endif