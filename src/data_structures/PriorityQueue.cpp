#include "PriorityQueue.hpp"
#include <iostream>
#include <iomanip>

// Default constructor - creates priority queue with MAX_SIZE capacity
PriorityQueue::PriorityQueue() {
    capacity = MAX_SIZE;
    cases = new EmergencyCase[capacity];
    size = 0;
}

// Parameterized constructor - creates priority queue with custom capacity
PriorityQueue::PriorityQueue(int cap) {
    capacity = cap;
    cases = new EmergencyCase[capacity];
    size = 0;
}

// Destructor - frees dynamically allocated memory
PriorityQueue::~PriorityQueue() {
    delete[] cases;
}

// Helper function to insert case in sorted order (highest priority first)
void PriorityQueue::insertSorted(const EmergencyCase& emergencyCase) {
    // Find the correct position to insert (sorted by priority, highest first)
    int insertPos = size;
    
    // Shift elements to make room for new case
    for (int i = 0; i < size; i++) {
        if (emergencyCase.getPriorityLevel() > cases[i].getPriorityLevel()) {
            insertPos = i;
            break;
        }
    }
    
    // Shift all elements from insertPos to the right
    for (int i = size; i > insertPos; i--) {
        cases[i] = cases[i - 1];
    }
    
    // Insert the new case at the correct position
    cases[insertPos] = emergencyCase;
    size++;
}

// Insert emergency case based on priority (maintains sorted order)
void PriorityQueue::insert(const EmergencyCase& emergencyCase) {
    if (isFull()) {
        std::cout << "\n[ERROR] Priority Queue is full! Cannot add more emergency cases." << std::endl;
        return;
    }
    
    insertSorted(emergencyCase);
    
    std::cout << "\n[SUCCESS] Emergency case logged successfully!" << std::endl;
    std::cout << "Case: " << emergencyCase.getCaseID() 
              << " - " << emergencyCase.getCaseType()
              << " (Priority: " << emergencyCase.getPriorityLevel() << ") added to queue." << std::endl;
}

// Extract (remove and return) the highest priority case
EmergencyCase PriorityQueue::extractHighestPriority() {
    if (isEmpty()) {
        std::cout << "\n[ERROR] Priority Queue is empty! No emergency cases to process." << std::endl;
        return EmergencyCase();  // Return empty case
    }
    
    // Highest priority is always at index 0 (due to sorted order)
    EmergencyCase highestPriorityCase = cases[0];
    
    // Shift all elements to the left
    for (int i = 0; i < size - 1; i++) {
        cases[i] = cases[i + 1];
    }
    
    size--;
    
    return highestPriorityCase;
}

// Check if priority queue is empty
bool PriorityQueue::isEmpty() const {
    return (size == 0);
}

// Check if priority queue is full
bool PriorityQueue::isFull() const {
    return (size == capacity);
}

// Get current size of priority queue
int PriorityQueue::getSize() const {
    return size;
}

// Display all emergency cases in priority order (highest to lowest)
void PriorityQueue::display() const {
    if (isEmpty()) {
        std::cout << "\n[INFO] Priority Queue is empty. No emergency cases pending." << std::endl;
        return;
    }
    
    std::cout << "\n==========================================================" << std::endl;
    std::cout << "          EMERGENCY CASES (PRIORITY ORDER)" << std::endl;
    std::cout << "==========================================================" << std::endl;
    std::cout << "Total Emergency Cases: " << size << std::endl;
    std::cout << "==========================================================" << std::endl;
    std::cout << std::left << std::setw(10) << "Priority" 
              << std::setw(15) << "Case ID" 
              << std::setw(20) << "Case Type" 
              << std::setw(13) << "Priority Lvl" << std::endl;
    std::cout << "==========================================================" << std::endl;
    
    // Display cases from highest to lowest priority
    for (int i = 0; i < size; i++) {
        std::string priorityLabel;
        int priority = cases[i].getPriorityLevel();
        
        // Label priorities for clarity
        if (priority >= 9) priorityLabel = "CRITICAL";
        else if (priority >= 7) priorityLabel = "HIGH";
        else if (priority >= 5) priorityLabel = "MEDIUM";
        else priorityLabel = "LOW";
        
        std::cout << std::left << std::setw(10) << priorityLabel
                  << std::setw(15) << cases[i].getCaseID()
                  << std::setw(20) << cases[i].getCaseType()
                  << std::setw(13) << cases[i].getPriorityLevel() << std::endl;
    }
    std::cout << "==========================================================" << std::endl;
}

