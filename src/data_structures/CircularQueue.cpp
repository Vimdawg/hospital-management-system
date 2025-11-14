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
    
    std::cout << "\n[SUCCESS] Ambulance registered successfully!" << std::endl;
    std::cout << "Ambulance " << ambulance.getAmbulanceID() 
              << " (Driver: " << ambulance.getDriverName() 
              << ", Region: " << ambulance.getRegion() << ") added to schedule." << std::endl;
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
    std::cout << "Ambulance " << frontAmbulance.getAmbulanceID() 
              << " moved to end of schedule." << std::endl;
    std::cout << "Next on duty: " << ambulances[front].getAmbulanceID() << std::endl;
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
    std::cout << "Total Ambulances: " << size << "/" << capacity << std::endl;
    std::cout << "==========================================================" << std::endl;
    std::cout << std::left << std::setw(10) << "Position" 
              << std::setw(15) << "Ambulance ID" 
              << std::setw(20) << "Driver Name" 
              << std::setw(13) << "Region" << std::endl;
    std::cout << "==========================================================" << std::endl;
    
    // Display ambulances from front to rear circularly
    std::cout << std::left << std::setw(10) << "CURRENT ↓" << std::endl;
    int position = 1;
    int index = front;
    
    for (int i = 0; i < size; i++) {
        std::string posLabel = (i == 0) ? "ON DUTY" : std::to_string(position);
        
        std::cout << std::left << std::setw(10) << posLabel
                  << std::setw(15) << ambulances[index].getAmbulanceID()
                  << std::setw(20) << ambulances[index].getDriverName()
                  << std::setw(13) << ambulances[index].getRegion() << std::endl;
        
        index = (index + 1) % capacity;  // Move circularly
        position++;
    }
    std::cout << "==========================================================" << std::endl;
    std::cout << "[NOTE] Use 'Rotate Shift' to move current ambulance to end" << std::endl;
}

// Clear the entire circular queue
void CircularQueue::clear() {
    front = -1;
    rear = -1;
    size = 0;
    std::cout << "\n[INFO] Circular Queue cleared successfully." << std::endl;
}

