#include "big-integer-arithmetic.hpp"
#include <sstream>
#include <iomanip>

/**
 * @brief Implementation of big integer arithmetic class
 */

std::string BigIntegerArithmetic::removeSignAndLeadingZeros(std::string string)
{
    // If the first character is negative sign, remove it
    if (string[0] == '-')
        string = string.substr(1);
    int firstNonZeroCharacterIndex = 0; // Index of first non-zero character
    // Keep incrementing index of first non-zero character until a non-zero character is found
    for (size_t i = 0; i < string.size() && string[i] == '0'; ++i)
        ++firstNonZeroCharacterIndex;
    // Ignore the string before index of first non-zero character
    return string.substr(firstNonZeroCharacterIndex);
}

BigIntegerArithmetic::BigIntegerArithmetic(ArithmeticExpression expression)
{
    // Set the arithmetic expression as the provided parameter
    this->expression = expression;
}

int BigIntegerArithmetic::operandComp(std::string operand1, std::string operand2)
{
    // Flags to determine whether the operands are negative or not
    bool operand1IsNegative = false;
    bool operand2IsNegative = false;
    // Initialize flags as true for both operands if first character is '-'
    if (!operand1.empty())
        operand1IsNegative = (operand1[0] == '-');
    if (!operand2.empty())
        operand2IsNegative = (operand2[0] == '-');
    // Now remove the sign and any leading zeroes from both operands
    operand1 = removeSignAndLeadingZeros(operand1);
    operand2 = removeSignAndLeadingZeros(operand2);

    // Result of comparison that will be returned
    int result = 0;

    // If operand 1 is negative and operand 2 is positive, operand1 > operand2
    if (operand1IsNegative && !operand2IsNegative)
        result = -1;
    // Else if no of digits in operand 1 are less than operand 2, operand1 > operand2
    else if (operand1.size() < operand2.size())
        result = -1;
    // Else if operand 1 is positive and operand 2 is negative, operand1 < operand2
    else if (!operand1IsNegative && operand2IsNegative)
        result = 1;
    // Else if no of digits in operand 1 are greater than operand 2, operand1 < operand2
    else if (operand1.size() > operand2.size())
        result = 1;
    // Else the result of comparison would be equal to the compare method of string
    else
        result = operand1.compare(operand2);

    // Return the result of comparison
    return result;
}

std::string BigIntegerArithmetic::getResults()
{
    // Stacks to store the operand digits as well as result's digits
    Stack operand1Stack, operand2Stack, resultStack;
    // Extract the string representation of operand 1 and operand 2
    std::string operand1 = expression.getOp1();
    std::string operand2 = expression.getOp2();
    // This variable will store the result
    std::string result;
    // To determine whether we should add a negative sign to result or not
    bool addNegativeSign = false;

    // If operand 1 >= operand 2
    if (operandComp(operand1, operand2) >= 0)
        // Pad operand 2 with zeroes at front so length of both operands become equal
        operand2.insert(0, operand1.size() - operand2.size(), '0');
    // Else as operand 1 < operand2
    else
    {
        // Pad operand 1 with zeroes at front so length of both operands become equal
        operand1.insert(0, operand2.size() - operand1.size(), '0');
        // If the operation is subtraction
        if (expression.getOperator() == '-')
        {
            // Reverse the order of subtraction (swap operands)
            std::string temp = operand1;
            operand1 = operand2;
            operand2 = temp;
            // Set the add negative sign after operations flag as true
            addNegativeSign = true;
        }
    }

    // Push all the operands from left to right on stack (so it can be popped in right to left manner)
    for (size_t i = 0; i < operand1.size(); ++i)
    {
        // The operandDigit - '0' returns the integer form of a character number
        // E.g. if operandDigit is '9', '9' - '0' will return 9
        operand1Stack.push(operand1[i] - '0');
        operand2Stack.push(operand2[i] - '0');
    }

    bool carry = false;  // Flag to determine whether a carry was produced in previous round
    bool borrow = false; // Flag to determine whether a borrow was taken in previous round

    // While the operand stack is not empty
    while (!operand1Stack.empty())
    {
        // Take both operand digits from respective stacks
        int operand1Digit = operand1Stack.pop();
        int operand2Digit = operand2Stack.pop();
        int resultDigit; // To store the result digit

        // If the operation is addition
        if (expression.getOperator() == '+')
        {
            // Add the 2 digits
            resultDigit = operand1Digit + operand2Digit;
            // If the carry was generated in previous round, add 1 to result
            resultDigit = (carry ? resultDigit + 1 : resultDigit);
            // If the value exceeds 9, set carry as true, else false
            carry = (resultDigit > 9);
            // Take the modulus of result by 10 to generate a single digit answer for addition
            resultDigit = resultDigit % 10;
        }
        // Else as the operation is subtraction
        else
        {
            // If a borrow was taken in previous round
            if (borrow)
            {
                // Subtract 1 from the first operand digit and set borrow as false
                operand1Digit -= 1;
                borrow = false;
            }
            // If operand 1 digit is less than operand 2 digit
            if (operand1Digit < operand2Digit)
            {
                // Add the value of borrow in this operand and set borrow as true
                operand1Digit += 10;
                borrow = true;
            }
            // Calculate the result of subtraction
            resultDigit = operand1Digit - operand2Digit;
        }
        // Push the digit generated by addition/subtraction on result stack
        resultStack.push(resultDigit);
    }

    // If a final carry was generated in case of addition
    if (carry && expression.getOperator() == '+')
        // Push this final carry value on result stack too
        resultStack.push(1);

    // While the result stack is not empty
    while (!resultStack.empty())
        // Append the result digit in result string
        // The resultDigit + '0' will create the character representation of the number
        // E.g. if resultDigit is 9, 9 + '0' will generate '9' which will be appended to result string
        result += (resultStack.pop() + '0');

    // Remove any sign and leading zeroes from the result
    result = removeSignAndLeadingZeros(result);
    // Calculate the maximum number width excluding sign for formatting
    size_t width = result.size();
    if (expression.getOp1().size() > width)
        width = expression.getOp1().size();
    if (expression.getOp2().size() > width)
        width = expression.getOp2().size();
    width = width + 1; // Add 1 into maximum width to make room for sign

    // If operands were reversed, prepend a negative sign in the result
    if (addNegativeSign)
        result = '-' + result;

    // String stream to build a properly formatted string
    std::stringstream stringStream;
    stringStream << std::setw(width) << std::right << expression.getOp1() << std::endl
                 << expression.getOperator() << std::setw(width - 1) << std::right << expression.getOp2() << std::endl
                 << std::setw(width) << std::right << result;
    // Return the string generated by string builder
    return stringStream.str();
}