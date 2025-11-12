#include "EmergencyCase.hpp"
#include <iostream>

EmergencyCase::EmergencyCase() : caseID(""), caseType(""), priorityLevel(0) {}

EmergencyCase::EmergencyCase(const std::string& id, const std::string& type, int priority)
    : caseID(id), caseType(type), priorityLevel(priority) {}

std::string EmergencyCase::getCaseID() const {
    return caseID;
}

std::string EmergencyCase::getCaseType() const {
    return caseType;
}

int EmergencyCase::getPriorityLevel() const {
    return priorityLevel;
}

void EmergencyCase::setCaseID(const std::string& id) {
    caseID = id;
}

void EmergencyCase::setCaseType(const std::string& type) {
    caseType = type;
}

void EmergencyCase::setPriorityLevel(int priority) {
    priorityLevel = priority;
}

void EmergencyCase::display() const {
    std::cout << "Case ID: " << caseID 
              << " | Type: " << caseType 
              << " | Priority: " << priorityLevel << std::endl;
}

