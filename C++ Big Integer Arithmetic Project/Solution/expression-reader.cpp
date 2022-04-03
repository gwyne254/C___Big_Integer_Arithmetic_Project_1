#include "expression-reader.hpp"
#include <string>
#include <sstream>

/**
 * Implementation of expression reader class
 */

ExpressionReader::ExpressionReader(std::string fileName)
{
    // Open the input file stream
    inputFileStream.open(fileName);
}

ExpressionReader::~ExpressionReader()
{
    // Close the input file stream if it is open
    if (inputFileStream.is_open())
        inputFileStream.close();
}

std::string ExpressionReader::getResult()
{
    // Create a big integer arithmetic object for calculating the expression
    BigIntegerArithmetic calculator(expression);
    // Return the calculation result returned by big integer arithmetic object
    return calculator.getResults();
}

bool ExpressionReader::readNextExpression()
{
    std::string line; // To store the line that is read next from file

    // If input file is open and hasn't ended, read the next line, else return false
    if (inputFileStream.is_open() && !inputFileStream.eof())
        std::getline(inputFileStream, line);
    else
        return false;
    // If the inputted line is empty, also return false
    if (line.empty())
        return false;

    // Create a string builder object from the inputted line
    std::stringstream stringStream(line);
    // Variables to store the operands and operation
    std::string value1, value2;
    char operation;
    // Read the operands and operation into respected variables
    stringStream >> value1;
    stringStream >> operation;
    stringStream >> value2;
    // Update the object's expression with the new arithmetic expression and return true
    expression = ArithmeticExpression(value1, value2, operation);
    return true;
}