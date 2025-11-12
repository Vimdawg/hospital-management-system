#include "PriorityQueue.hpp"
#include <iostream>

PriorityQueue::PriorityQueue() {
    // TODO: Initialize priority queue
}

PriorityQueue::~PriorityQueue() {
    // TODO: Clean up resources
}

void PriorityQueue::insert(const EmergencyCase& emergencyCase) {
    // TODO: Insert emergency case based on priority
}

EmergencyCase PriorityQueue::extractHighestPriority() {
    // TODO: Remove and return highest priority case
    return EmergencyCase();
}

EmergencyCase PriorityQueue::peek() const {
    // TODO: Return highest priority case without removing
    return EmergencyCase();
}

bool PriorityQueue::isEmpty() const {
    // TODO: Check if priority queue is empty
    return true;
}

void PriorityQueue::display() const {
    // TODO: Display all emergency cases in priority order
    std::cout << "Emergency Cases (Priority Order):" << std::endl;
}

