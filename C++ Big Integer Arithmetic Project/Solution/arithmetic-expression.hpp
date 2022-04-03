#ifndef ARITHMETIC_EXPRESSION_HPP
#define ARITHMETIC_EXPRESSION_HPP

#include "operand.hpp"

// A class to represent an arithmetic expression having 2 operands and an operator
class ArithmeticExpression
{
private:
    // Operator of the operation ('+' or '-')
    char operation;
    // Left operand
    Operand operand1;
    // Right operand
    Operand operand2;

public:
    // Constructs the arithmetic expression object according to the parameterized operands and operator
    ArithmeticExpression(std::string value1, std::string value2, char operation);
    // Constructs a arithmetic expression with default values
    ArithmeticExpression();
    // Returns the string representation of left operand
    std::string getOp1();
    // Returns the string representation of right operand
    std::string getOp2();
    // Returns the operator of the operation to perform
    char getOperator();
};

#endif