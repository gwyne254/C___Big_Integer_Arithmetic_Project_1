#include "stack.hpp"

/**
 * Implementation of node class
 */

Node::Node(int value)
{
    // Intialize the attributes of the node using setters
    setValue(value);
    setNext(nullptr);
}

int Node::getValue() { return value; }

Node *Node::getNext() { return next; }

void Node::setValue(int value) { this->value = value; }

void Node::setNext(Node *next) { this->next = next; }

/**
 * Implementation of stack class
 */

Stack::Stack()
{
    // As the stack is empty so top should be null yet
    top = nullptr;
}

Stack::~Stack()
{
    // Keep popping untill the stack is empty, pop will automatically deallocate memory
    while (!empty())
        pop();
}

bool Stack::empty()
{
    // If top is null, stack is empty
    return top == nullptr;
}

int Stack::peek()
{
    // Return -1 if stack is empty, else the value of top node
    return (empty() ? -1 : top->getValue());
}

int Stack::pop()
{
    // Get the item at top of stack
    int toReturn = peek();
    // If stack is not empty (top item not -1)
    if (toReturn != -1)
    {
        // Move the top node reference to the next node and delete the old top
        Node *previous = top;
        top = top->getNext();
        delete previous;
    }
    // Return the value of deleted top
    return toReturn;
}

void Stack::push(int value)
{
    // Create a new node
    Node *newNode = new Node(value);
    // Add it before top and set it as new top
    newNode->setNext(top);
    top = newNode;
}