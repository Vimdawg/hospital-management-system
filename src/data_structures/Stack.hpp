#ifndef STACK_HPP
#define STACK_HPP

#include "../models/MedicalSupply.hpp"

class Stack {
private:
    static const int MAX_SIZE = 10000;  // Maximum stack capacity
    MedicalSupply* supplies;          // Dynamic array to store supplies
    int top;                          // Index of top element
    int capacity;                     // Maximum capacity of stack

public:
    Stack();
    Stack(int cap);
    ~Stack();
    
    void push(const MedicalSupply& supply);
    MedicalSupply pop();
    bool isEmpty() const;
    bool isFull() const;
    int getSize() const;
    void display() const;
};

#endif // STACK_HPP

