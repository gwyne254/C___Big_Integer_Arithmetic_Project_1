# Big Integer Arithmetic Algorithms
[![Points badge](../../blob/badges/.github/badges/points.svg)](../../actions)

## Project Outcomes:
Develop a C++ program that uses:
- Multiple stacks
- File I/O

## Preparatory Readings:
- ZyBook primer chapters
- ZyBook chapter 2, 3, 7, 8

## Project overview:
Physical machines have fixed maximum sizes for the representation of numbers.
For instance, integers are often 32 bits and signed, meaning the largest integer
value that can be held is + or - approximately 2 billion. The goal of this
project is to use multiple stack data structures to enable addition and
subtraction of arbitrarily large integers.

![Integer overflow when counting sheep](https://imgs.xkcd.com/comics/cant_sleep.png)

## Project Requirements:
Your application must function as described below:
1. Your program shall adhere to the test suites provided [here](test/). Read the
    tests and create the required files, classes, and methods. This means that
    all tests must pass in their current configuration.
1. The Makefile was provided and can be directly used.
1. Implement a int Stack ADT to support the algorithm
1. Perform large integer operation using stacks
    1. prepare the operands and operators so the sign of the second operand will
       be combined with the operator
    1. if a large number is subtracted from a smaller number, reverse the order
       of the subtraction and mark the result as negative
    1. create three stacks
    1. for both operands, push every digit into the the corresponding stack
       starting from right to left
    1. pop one digit from each operand every time, pad with 0 if the stack
       operand is empty
    1. for each decimal place, apply the operation to both digits, include the
       carry and borrow bit from the last round as need, set the new carry and
       borrow for next round
    1. clean up the leading zero in subtraction
1. Display in the desired format
    1. the operator should be displayed in the first column of the second row
    1. the first column should only hold the operator or sign of the result row
    1. all numbers should be right aligned

## Code organization
+ The Stack class and Node class

    Implement an int Stack. Include the node class used in the stack in the same
    set of files (stack.hpp, stack.cpp).

+ The Operand class

    - models an int operand
    - keeps the int value as a string

+ The ArithmeticExpression class

    - models an binary expression with two operands and one operator
    - keeps two operands as strings
    - keeps an operator as a char
    - the operator will be adjusted when the second operand is negative

+ The BigIntegerArithmetic class

    - this class owns a reference to a ArithmeticExpression object and performs
      big integer arithmetic on the expression
    - to keep it simple, operands used with this class are **all positive**
    - when handling subtraction, the order of the subtrahend and minuend needs
      to be reversed when the subtrahend is greater; the sign of the result will
      be negative and needs to be kept separately in the object; when displaying
      the result, the operands should be displayed in the original order
    - the `operandComp` method to compare two string of operands; it should
      return a positive value if the first is greater, return zero if two are
      the same, return a negative value if the first is less; you can compare
      the string length first and then use the string::compare method to compare
      two strings with the same lengths
    - the `getResults` method to return a string with the output in the format
      described in the project requirement as demonstrated in the following
      example

        ```
         12
        + 5
         17
        ```
+ The ExpressionReader class

    - the `readNextExpression` method to read the next expression from the
      input data file as shown below; the operands will be **all positive**.
    - each line represent an expression with operand 1, operator and operand 2
      separated by spaces

## Sample data
```
12 + 5
5 + 12
12 - 5
5 - 12
364287462834623846283426384 + 923742938742934723947239847
364287462834623846283426384 - 923742938742934723947239847
```

## Sample run
```
 12
+ 5
 17
----------
  5
+12
 17
----------
 12
- 5
  7
----------
  5
-12
 -7
----------
  364287463834623846283426384
+ 923742938742934723947239847
 1288030402577558570230666231
----------
 364287463834623846283426384
-923742938742934723947239847
-559455474908310877663813463
----------
```

## Implementation Notes:
1. Create a project that is object oriented, therefore there should be several
   classes.
1. The input file will match the exact format given above.
1. Your program must compile and pass a tests listed above.
    - This application must be compiled by running `make main` and shall create
        an executable file called `main`.
    - All tests must pass by running together with `make test-all`. You can run
        individual test during development.
1. You classes must be memory leak free. Memory leakage will be checked and
   graded in autograding.

## Submission Requirements:
1. All code must be added and committed to your local git repository.
2. All code must be pushed to the GitHub repository created when you "accepted"
   the assignment.
    1. After pushing, with `git push origin master`, visit the web URL of your
       repository to verify that your code is there. If you don't see the code
       there, then we can't see it either.
3. Your code must compile and run. The auto-grading tests will indicate your
   score for your submission.
    1. The auto-grading build should begin automatically when you push your code
       to GitHub.
    2. If your program will not compile, the graders will not be responsible for
       trying to test it.
    3. You should get an email regarding the status of your build, if it does
       not pass, keep trying.

## Important Notes:
- Projects will be graded on whether they correctly solve the problem, and
  whether they adhere to good programming practices.
- Projects must be received by the time specified on the due date.
- Please review the academic honesty policy.
    - Note that viewing another student's solution, whether in whole or in part,
      is considered academic dishonesty.
    - Also note that submitting code obtained through the Internet or other
      sources, whether in whole or in part, is considered academic dishonesty.
    - All programs submitted will be reviewed for evidence of academic
      dishonesty, and all violations will be handled accordingly.

## Grading Information:
- Breakdown
    + 80% GitHub Auto-grading
    + 10% Coding style (naming convention, neatness of code, etc)
    + 10% Code organization (modular design, separate files, headers, etc.)
- Auto-grading results can be checked at the top of this document like as a
  badge ***40/80***.
- View details:
    1. On your GitHub repo page, Click the :arrow_forward: **Actions** tab to
       see your graded results.
    1. If it isn't a green check mark (:heavy_check_mark:) then at least part of
       the testing failed.
    1. Click the commit message for the failing version then click "Autograding"
       on the left side of the page.
    1. Follow the :x: path and expand things to see what errors exist.
    1. It is usually **education/autograding@v1** and you can expend this path to
       view the detail.
