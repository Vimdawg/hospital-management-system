#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "../models/Patient.hpp"

class Queue {
private:
    // TODO: Implement queue data structure

public:
    Queue();
    ~Queue();
    
    void enqueue(const Patient& patient);
    Patient dequeue();
    bool isEmpty() const;
    bool isFull() const;
    void display() const;
};

#endif // QUEUE_HPP

