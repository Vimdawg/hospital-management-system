#include "Queue.hpp"
#include <iostream>

Queue::Queue() {
    // TODO: Initialize queue
}

Queue::~Queue() {
    // TODO: Clean up resources
}

void Queue::enqueue(const Patient& patient) {
    // TODO: Add patient to rear of queue
}

Patient Queue::dequeue() {
    // TODO: Remove and return patient from front of queue
    return Patient();
}

bool Queue::isEmpty() const {
    // TODO: Check if queue is empty
    return true;
}

bool Queue::isFull() const {
    // TODO: Check if queue is full (for array-based implementation)
    return false;
}

void Queue::display() const {
    // TODO: Display all patients in queue
    std::cout << "Patient Queue:" << std::endl;
}

