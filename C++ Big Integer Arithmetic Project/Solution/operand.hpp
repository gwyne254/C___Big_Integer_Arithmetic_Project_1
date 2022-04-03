#ifndef OPERAND_HPP
#define OPERAND_HPP

#include <iostream>

// A class to represent an operand in an arithmetic expression
class Operand
{
private:
    // Value of operand
    std::string value;
    // To determine whether the operand is negative or not
    bool negative;

public:
    // Constructs the operand object with empty value
    Operand();
    // Constructs the operand object with the specified value
    Operand(std::string operand);
    // Determines whether the operand is negative or not
    bool isNegative();
    // Sets the value of the operand
    void setValue(std::string value);
    // Returns the value of the operand
    std::string getValue();
    // Flips the operand's sign
    void flipSign();
};

#endif