#include "operand.hpp"

/**
 * Implementation of Operand class
 */

Operand::Operand(std::string operand)
{
    negative = false; // Initially set negative flag as false
    // Set the operand value using setter, flag will be updated if required
    setValue(operand);
}

Operand::Operand() : Operand("")
{
    // No body required due to constructor chaining
    // The parameterized constructor has been called with default arguments
}

void Operand::setValue(std::string value)
{
    // If the value string is not empty
    if (!value.empty())
    {
        // If the first character or string is a sign
        if (value[0] == '-' || value[0] == '+')
        {
            // If the first character is a negative sign, this operand is negative
            if (value[0] == '-')
                negative = true;
            // Remove the sign from the magnitude of value
            value = value.substr(1);
        }
        // Set this magnitude as the object's attribute value
        this->value = value;
    }
}

std::string Operand::getValue()
{
    // Return the value string of the operand
    // If the operand is negative, prepend the "-" sign, else nothing
    return (negative ? "-" : "") + value;
}

void Operand::flipSign()
{
    // Negate the value of negative flag
    negative = !negative;
}

bool Operand::isNegative()
{
    // Return the value of negative flag
    return negative;
}