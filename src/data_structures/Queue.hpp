#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "../models/Patient.hpp"

class Queue {
private:
    static const int MAX_SIZE = 50;  // Maximum queue capacity
    Patient* patients;                // Dynamic array to store patients
    int front;                        // Index of front element
    int rear;                         // Index of rear element
    int size;                         // Current number of patients in queue
    int capacity;                     // Maximum capacity of queue

public:
    Queue();
    Queue(int cap);
    ~Queue();
    
    void enqueue(const Patient& patient);
    Patient dequeue();
    Patient getFront() const;
    bool isEmpty() const;
    bool isFull() const;
    int getSize() const;
    void display() const;
    void clear();
};

#endif // QUEUE_HPP

