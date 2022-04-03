#ifndef STACK_HPP
#define STACK_HPP

// A class to represent a node of any singly linked data structure
class Node
{
private:
    // Reference to next node
    Node *next;
    // Value of current node
    int value;

public:
    // Constructs a node object with the specified value
    Node(int value);
    // Returns the value of node
    int getValue();
    // Returns the next node's reference
    Node *getNext();
    // Sets the value of node
    void setValue(int value);
    // Sets the next node's reference
    void setNext(Node *next);
};

// A class to represent a stack created by linked nodes that holds integer values
class Stack
{
private:
    // Reference to top of stack
    Node *top;

public:
    // Constructor to initialize the stack
    Stack();
    // Destructor to properly deallocate the stack
    ~Stack();
    // Method to add an item on top of stack
    void push(int value);
    // Method to check whether the stack is empty or not
    bool empty();
    // Method to return the item at the top of stack, -1 if stack is empty
    int peek();
    // Method to remove and return the item at the top of stack, -1 if stack is empty
    int pop();
};

#endif