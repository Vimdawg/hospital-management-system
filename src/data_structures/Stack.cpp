#include "Stack.hpp"
#include <iostream>
#include <iomanip>

// Default constructor - creates stack with MAX_SIZE capacity
Stack::Stack() {
    capacity = MAX_SIZE;
    supplies = new MedicalSupply[capacity];
    top = -1;  // Empty stack indicated by top = -1
}

// Parameterized constructor - creates stack with custom capacity
Stack::Stack(int cap) {
    capacity = cap;
    supplies = new MedicalSupply[capacity];
    top = -1;
}

// Destructor - frees dynamically allocated memory
Stack::~Stack() {
    delete[] supplies;
}

// Push supply onto the top of the stack (LIFO)
void Stack::push(const MedicalSupply& supply) {
    if (isFull()) {
        std::cout << "\n[ERROR] Stack is full! Cannot add more supplies." << std::endl;
        return;
    }
    
    // Increment top and add supply
    top++;
    supplies[top] = supply;
}

// Pop (remove and return) supply from the top of the stack (LIFO)
MedicalSupply Stack::pop() {
    if (isEmpty()) {
        std::cout << "\n[ERROR] Stack is empty! No supplies to use." << std::endl;
        return MedicalSupply();  // Return empty supply
    }
    
    // Get supply at top
    MedicalSupply usedSupply = supplies[top];
    
    // Decrement top
    top--;
    
    return usedSupply;
}

// Check if stack is empty
bool Stack::isEmpty() const {
    return (top == -1);
}

// Check if stack is full
bool Stack::isFull() const {
    return (top == capacity - 1);
}

// Get current size of stack
int Stack::getSize() const {
    return (top + 1);
}

// Display all supplies in the stack (top to bottom)
void Stack::display() const {
    if (isEmpty()) {
        std::cout << "\n[INFO] Stack is empty. No supplies in inventory." << std::endl;
        return;
    }
    
    std::cout << "\n==========================================================" << std::endl;
    std::cout << "           MEDICAL SUPPLY INVENTORY (STACK)" << std::endl;
    std::cout << "==========================================================" << std::endl;
    std::cout << "Total Supplies in Stack: " << getSize() << "/" << capacity << std::endl;
    std::cout << "==========================================================" << std::endl;
    std::cout << std::left << std::setw(10) << "Position" 
              << std::setw(10) << "Item ID" 
              << std::setw(18) << "Supply Type" 
              << std::setw(10) << "Quantity" 
              << std::setw(10) << "Batch" << std::endl;
    std::cout << "==========================================================" << std::endl;
    
    // Display supplies from top to bottom
    for (int i = top; i >= 0; i--) {
        std::cout << std::left << std::setw(10) << (top - i + 1)
                  << std::setw(10) << supplies[i].getItemID()
                  << std::setw(18) << supplies[i].getSupplyType()
                  << std::setw(10) << supplies[i].getQuantity()
                  << std::setw(10) << supplies[i].getBatchNumber() << std::endl;
    }
    std::cout << "==========================================================" << std::endl;
}

