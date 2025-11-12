#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include "../models/EmergencyCase.hpp"

class PriorityQueue {
private:
    // TODO: Implement priority queue data structure

public:
    PriorityQueue();
    ~PriorityQueue();
    
    void insert(const EmergencyCase& emergencyCase);
    EmergencyCase extractHighestPriority();
    EmergencyCase peek() const;
    bool isEmpty() const;
    void display() const;
};

#endif // PRIORITYQUEUE_HPP

