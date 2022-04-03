#include "arithmetic-expression.hpp"

/**
 * Implementation of Arithmetic Expression class
 */

ArithmeticExpression::ArithmeticExpression(std::string value1, std::string value2, char operation)
{
    // Initialize the attributes
    this->operation = operation;
    operand1 = Operand(value1);
    operand2 = Operand(value2);
    // If the right operand is negative
    if (operand2.isNegative())
    {
        // Make operand 2 positive
        operand2.flipSign();
        // Flip the sign of operation, if operation is '-', make '+' and vice versa
        this->operation = (operation == '-' ? '+' : '-');
    }
}

ArithmeticExpression::ArithmeticExpression() : ArithmeticExpression("", "", ' ')
{
    // No body required due to constructor chaining
    // The parameterized constructor has been called with default arguments
}

std::string ArithmeticExpression::getOp1()
{
    // Return the string representation of operand 1
    return operand1.getValue();
}

std::string ArithmeticExpression::getOp2()
{
    // Return the string representation of operand 2
    return operand2.getValue();
}

char ArithmeticExpression::getOperator()
{
    // Return the operator of operation
    return operation;
}