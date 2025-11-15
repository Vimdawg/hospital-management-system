#include "Queue.hpp"
#include <iostream>
#include <iomanip>

// Default constructor - creates queue with MAX_SIZE capacity
Queue::Queue() {
    capacity = MAX_SIZE;
    patients = new Patient[capacity];
    front = -1;
    rear = -1;
    size = 0;
}

// Parameterized constructor - creates queue with custom capacity
Queue::Queue(int cap) {
    capacity = cap;
    patients = new Patient[capacity];
    front = -1;
    rear = -1;
    size = 0;
}

// Destructor - frees dynamically allocated memory
Queue::~Queue() {
    delete[] patients;
}

// Add patient to the rear of the queue (FIFO)
void Queue::enqueue(const Patient& patient) {
    if (isFull()) {
        std::cout << "\n[ERROR] Queue is full! Cannot admit more patients." << std::endl;
        return;
    }
    
    // If queue is empty, set front to 0
    if (isEmpty()) {
        front = 0;
    }
    
    // Move rear forward and add patient
    rear++;
    patients[rear] = patient;
    size++;
    
    std::cout << "\n[SUCCESS] Patient admitted successfully!" << std::endl;
    std::cout << "Patient " << patient.getPatientName() << " (ID: " << patient.getPatientID() 
              << ") added to queue." << std::endl;
}

// Remove and return patient from the front of the queue (FIFO)
Patient Queue::dequeue() {
    if (isEmpty()) {
        std::cout << "\n[ERROR] Queue is empty! No patients to discharge." << std::endl;
        return Patient();  // Return empty patient
    }
    
    // Get patient at front
    Patient dischargedPatient = patients[front];
    
    // Move front forward
    front++;
    size--;
    
    // Reset queue if it becomes empty
    if (isEmpty()) {
        front = -1;
        rear = -1;
    }
    
    return dischargedPatient;
}

// Peek at the front patient without removing
Patient Queue::getFront() const {
    if (isEmpty()) {
        std::cout << "\n[ERROR] Queue is empty!" << std::endl;
        return Patient();
    }
    return patients[front];
}

// Check if queue is empty
bool Queue::isEmpty() const {
    return (size == 0);
}

// Check if queue is full
bool Queue::isFull() const {
    return (size == capacity);
}

// Get current size of queue
int Queue::getSize() const {
    return size;
}

// Display all patients in the queue
void Queue::display() const {
    if (isEmpty()) {
        std::cout << "\n[INFO] Queue is empty. No patients waiting." << std::endl;
        return;
    }
    
    std::cout << "\n==========================================================" << std::endl;
    std::cout << "              PATIENT QUEUE STATUS" << std::endl;
    std::cout << "==========================================================" << std::endl;
    std::cout << "Total Patients Waiting: " << size << std::endl;
    std::cout << "==========================================================" << std::endl;
    std::cout << std::left << std::setw(10) << "Position" 
              << std::setw(12) << "Patient ID" 
              << std::setw(20) << "Name" 
              << std::setw(18) << "IC Number"
              << std::setw(16) << "Condition" << std::endl;
    std::cout << "=======================================================================" << std::endl;
    
    // Display patients from front to rear
    int position = 1;
    for (int i = front; i <= rear; i++) {
        std::cout << std::left << std::setw(10) << position
                  << std::setw(12) << patients[i].getPatientID()
                  << std::setw(20) << patients[i].getPatientName()
                  << std::setw(18) << patients[i].getNationalIC()
                  << std::setw(16) << patients[i].getConditionType() << std::endl;
        position++;
    }
    std::cout << "=======================================================================" << std::endl;
}

