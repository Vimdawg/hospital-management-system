#include "CircularQueue.hpp"
#include <iostream>
#include <iomanip>

// Default constructor - creates circular queue with MAX_SIZE capacity
CircularQueue::CircularQueue() {
    capacity = MAX_SIZE;
    ambulances = new Ambulance[capacity];
    front = -1;
    rear = -1;
    size = 0;
}

// Parameterized constructor - creates circular queue with custom capacity
CircularQueue::CircularQueue(int cap) {
    capacity = cap;
    ambulances = new Ambulance[capacity];
    front = -1;
    rear = -1;
    size = 0;
}

// Destructor - frees dynamically allocated memory
CircularQueue::~CircularQueue() {
    delete[] ambulances;
}

// Add ambulance to the rear of the circular queue
void CircularQueue::enqueue(const Ambulance& ambulance) {
    if (isFull()) {
        std::cout << "\n[ERROR] Circular Queue is full! Cannot register more ambulances." << std::endl;
        return;
    }
    
    // If queue is empty, set front to 0
    if (isEmpty()) {
        front = 0;
        rear = 0;
    } else {
        // Move rear forward circularly using modulo
        rear = (rear + 1) % capacity;
    }
    
    ambulances[rear] = ambulance;
    size++;
}

// Remove and return ambulance from the front of the circular queue
Ambulance CircularQueue::dequeue() {
    if (isEmpty()) {
        std::cout << "\n[ERROR] Circular Queue is empty! No ambulances to remove." << std::endl;
        return Ambulance();
    }
    
    Ambulance removedAmbulance = ambulances[front];
    
    // If only one element, reset queue
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        // Move front forward circularly using modulo
        front = (front + 1) % capacity;
    }
    
    size--;
    
    return removedAmbulance;
}

// Rotate: Move front ambulance to rear (shift rotation for round-robin)
void CircularQueue::rotate() {
    if (isEmpty()) {
        std::cout << "\n[ERROR] Circular Queue is empty! Cannot rotate." << std::endl;
        return;
    }
    
    if (size == 1) {
        std::cout << "\n[INFO] Only one ambulance in queue. No rotation needed." << std::endl;
        return;
    }
    
    // Get front ambulance
    Ambulance frontAmbulance = ambulances[front];
    
    // Remove from front
    front = (front + 1) % capacity;
    
    // Add to rear
    rear = (rear + 1) % capacity;
    ambulances[rear] = frontAmbulance;
    
    std::cout << "\n[SUCCESS] Shift rotated!" << std::endl;
    std::cout << "Ambulance " << frontAmbulance.getLicensePlate() 
              << " moved to end of schedule." << std::endl;
    std::cout << "Next on duty: " << ambulances[front].getLicensePlate() << std::endl;
}

// Peek at the front ambulance without removing
Ambulance CircularQueue::getFront() const {
    if (isEmpty()) {
        std::cout << "\n[ERROR] Circular Queue is empty!" << std::endl;
        return Ambulance();
    }
    return ambulances[front];
}

// Check if circular queue is empty
bool CircularQueue::isEmpty() const {
    return (size == 0);
}

// Check if circular queue is full
bool CircularQueue::isFull() const {
    return (size == capacity);
}

// Get current size of circular queue
int CircularQueue::getSize() const {
    return size;
}

// Display all ambulances in circular order
void CircularQueue::display() const {
    if (isEmpty()) {
        std::cout << "\n[INFO] Circular Queue is empty. No ambulances registered." << std::endl;
        return;
    }
    
    std::cout << "\n==========================================================" << std::endl;
    std::cout << "        AMBULANCE SHIFT SCHEDULE (CIRCULAR QUEUE)" << std::endl;
    std::cout << "==========================================================" << std::endl;
    std::cout << "Total Ambulances: " << size << std::endl;
    std::cout << "==========================================================" << std::endl;
    std::cout << std::left << std::setw(10) << "Position" 
              << std::setw(20) << "License Plate" << std::endl;
    std::cout << "==========================================================" << std::endl;
    
    // Display ambulances from front to rear circularly
    int index = front;
    
    for (int i = 0; i < size; i++) {
        std::cout << std::left << std::setw(10) << (i + 1)
                  << std::setw(20) << ambulances[index].getLicensePlate() << std::endl;
        
        index = (index + 1) % capacity;  // Move circularly
    }
    std::cout << "==========================================================" << std::endl;
}

