#ifndef CIRCULARQUEUE_HPP
#define CIRCULARQUEUE_HPP

#include "../models/Ambulance.hpp"

class CircularQueue {
private:
    static const int MAX_SIZE = 20;   // Maximum circular queue capacity
    Ambulance* ambulances;            // Dynamic array to store ambulances
    int front;                        // Index of front element
    int rear;                         // Index of rear element
    int size;                         // Current number of ambulances in queue
    int capacity;                     // Maximum capacity of queue

public:
    CircularQueue();
    CircularQueue(int cap);
    ~CircularQueue();
    
    void enqueue(const Ambulance& ambulance);
    Ambulance dequeue();
    void rotate();
    Ambulance getFront() const;
    bool isEmpty() const;
    bool isFull() const;
    int getSize() const;
    void display() const;
};

#endif // CIRCULARQUEUE_HPP

