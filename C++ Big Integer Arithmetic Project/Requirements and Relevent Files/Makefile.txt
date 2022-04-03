CXX = g++
CXXFLAGS = -g -std=c++11 -Wall -Werror=return-type  -Werror=uninitialized

SRCS = $(wildcard *.hpp)
OBJECTS = $(SRCS:%.hpp=%.o)
TESTS = test-1-node test-2-stack test-3-operand test-4-arithmetic-expression test-5a-big-integer-arithmetic test-5b-big-integer-arithmetic test-6-expression-reader
CATCH = test/catch/catch.o

main: $(OBJECTS) main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf main.dSYM
	$(RM) *.o *.gc* test/*.o test/*.gc* *.dSYM $(addprefix test/,$(TESTS)) core main ${CATCH}

test-all: $(TESTS)

test-1-node: stack.o test/test-1-node.cpp
test-2-stack: stack.o test/test-2-stack.cpp
test-3-operand: stack.o operand.o test/test-3-operand.cpp
test-4-arithmetic-expression: stack.o operand.o arithmetic-expression.o test/test-4-arithmetic-expression.cpp
test-5a-big-integer-arithmetic: stack.o operand.o arithmetic-expression.o big-integer-arithmetic.o test/test-5a-big-integer-arithmetic.cpp
test-5b-big-integer-arithmetic: stack.o operand.o arithmetic-expression.o big-integer-arithmetic.o test/test-5b-big-integer-arithmetic.cpp
test-6-expression-reader: stack.o operand.o arithmetic-expression.o big-integer-arithmetic.o expression-reader.o test/test-6-expression-reader.cpp

$(TESTS): $(CATCH)
	$(CXX) $(CXXFLAGS) -o test/$@ $^
	test/$@ --success
