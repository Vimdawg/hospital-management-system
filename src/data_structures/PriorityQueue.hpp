#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include "../models/EmergencyCase.hpp"

class PriorityQueue {
private:
    static const int MAX_SIZE = 50;   // Maximum priority queue capacity
    EmergencyCase* cases;             // Dynamic array to store emergency cases
    int size;                         // Current number of cases in queue
    int capacity;                     // Maximum capacity of queue
    
    // Helper function to maintain priority order after insertion
    void insertSorted(const EmergencyCase& emergencyCase);

public:
    PriorityQueue();
    PriorityQueue(int cap);
    ~PriorityQueue();
    
    void insert(const EmergencyCase& emergencyCase);
    EmergencyCase extractHighestPriority();
    bool isEmpty() const;
    bool isFull() const;
    int getSize() const;
    void display() const;
};

#endif // PRIORITYQUEUE_HPP

