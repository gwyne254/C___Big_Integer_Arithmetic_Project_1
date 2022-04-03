#ifndef EXPRESSION_READER_HPP
#define EXPRESSION_READER_HPP

#include "big-integer-arithmetic.hpp"
#include <fstream>

// A class to represent an expression reader that reads arithmetic expressions
// from a file and returns the result after calculation
class ExpressionReader
{
private:
    // The arithmetic expression that will be solved when getResult() will be called
    ArithmeticExpression expression;
    // Input file stream to read expressions from a file
    std::ifstream inputFileStream;

public:
    // Constructor to initialize path of inputFileStream
    ExpressionReader(std::string fileName);
    // Destructor to close the file after when object is being destroyed
    ~ExpressionReader();
    // Method that returns true if next expression is read from file, else false
    bool readNextExpression();
    // Returns the string form of expression solution
    std::string getResult();
};

#endif