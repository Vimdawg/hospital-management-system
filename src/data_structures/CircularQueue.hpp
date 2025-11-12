#ifndef CIRCULARQUEUE_HPP
#define CIRCULARQUEUE_HPP

#include "../models/Ambulance.hpp"

class CircularQueue {
private:
    // TODO: Implement circular queue data structure

public:
    CircularQueue();
    ~CircularQueue();
    
    void enqueue(const Ambulance& ambulance);
    Ambulance dequeue();
    void rotate();
    bool isEmpty() const;
    bool isFull() const;
    void display() const;
};

#endif // CIRCULARQUEUE_HPP

