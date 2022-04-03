#include "expression-reader.hpp"

#define INPUT_FILENAME "expressions.txt" // Filename to input from

/**
 * Contains the main function of execution
 */

int main()
{
    // Create an expression reader object with the filename to input from
    ExpressionReader expressionReader(INPUT_FILENAME);
    // While the expression reader is able to read next expression
    while (expressionReader.readNextExpression())
    {
        // Display the reuslt of expression along with a seperator on screen
        std::cout << expressionReader.getResult() << std::endl
                  << "----------" << std::endl;
    }
    // Return control to OS
    return 0;
}