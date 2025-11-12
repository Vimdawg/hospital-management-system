#include "CircularQueue.hpp"
#include <iostream>

CircularQueue::CircularQueue() {
    // TODO: Initialize circular queue
}

CircularQueue::~CircularQueue() {
    // TODO: Clean up resources
}

void CircularQueue::enqueue(const Ambulance& ambulance) {
    // TODO: Add ambulance to circular queue
}

Ambulance CircularQueue::dequeue() {
    // TODO: Remove and return ambulance from front
    return Ambulance();
}

void CircularQueue::rotate() {
    // TODO: Move front ambulance to rear (shift rotation)
}

bool CircularQueue::isEmpty() const {
    // TODO: Check if circular queue is empty
    return true;
}

bool CircularQueue::isFull() const {
    // TODO: Check if circular queue is full
    return false;
}

void CircularQueue::display() const {
    // TODO: Display all ambulances in circular order
    std::cout << "Ambulance Circular Schedule:" << std::endl;
}

