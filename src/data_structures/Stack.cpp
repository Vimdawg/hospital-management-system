#include "Stack.hpp"
#include <iostream>

Stack::Stack() {
    // TODO: Initialize stack
}

Stack::~Stack() {
    // TODO: Clean up resources
}

void Stack::push(const MedicalSupply& supply) {
    // TODO: Push supply onto stack
}

MedicalSupply Stack::pop() {
    // TODO: Remove and return top supply
    return MedicalSupply();
}

MedicalSupply Stack::peek() const {
    // TODO: Return top supply without removing
    return MedicalSupply();
}

bool Stack::isEmpty() const {
    // TODO: Check if stack is empty
    return true;
}

bool Stack::isFull() const {
    // TODO: Check if stack is full (for array-based implementation)
    return false;
}

void Stack::display() const {
    // TODO: Display all supplies in stack
    std::cout << "Medical Supply Stack:" << std::endl;
}

