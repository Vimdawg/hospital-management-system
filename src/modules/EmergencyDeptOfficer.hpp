#ifndef EMERGENCYDEPTOFFICER_HPP
#define EMERGENCYDEPTOFFICER_HPP

#include "../data_structures/PriorityQueue.hpp"

class EmergencyDeptOfficer {
private:
    PriorityQueue emergencyQueue;
    int nextCaseID;

public:
    EmergencyDeptOfficer();
    ~EmergencyDeptOfficer();
    
    void run();
    void logEmergencyCase();
    void processEmergencyCase();
    void viewEmergencyCases();
};

#endif // EMERGENCYDEPTOFFICER_HPP

