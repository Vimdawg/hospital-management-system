#ifndef STACK_HPP
#define STACK_HPP

#include "../models/MedicalSupply.hpp"

class Stack {
private:
    // TODO: Implement stack data structure

public:
    Stack();
    ~Stack();
    
    void push(const MedicalSupply& supply);
    MedicalSupply pop();
    MedicalSupply peek() const;
    bool isEmpty() const;
    bool isFull() const;
    void display() const;
};

#endif // STACK_HPP

