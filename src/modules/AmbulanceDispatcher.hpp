#ifndef AMBULANCEDISPATCHER_HPP
#define AMBULANCEDISPATCHER_HPP

#include "../data_structures/CircularQueue.hpp"

class AmbulanceDispatcher {
private:
    CircularQueue ambulanceQueue;

public:
    AmbulanceDispatcher();
    ~AmbulanceDispatcher();
    
    void run();
    void registerAmbulance();
    void rotateShift();
    void viewAmbulanceSchedule();
    void viewCurrentOnDuty();
};

#endif // AMBULANCEDISPATCHER_HPP

