#include "EmergencyCase.hpp"
#include <iostream>

EmergencyCase::EmergencyCase() : caseID(""), patientName(""), caseType(""), priorityLevel(0) {}

EmergencyCase::EmergencyCase(const std::string& id, const std::string& name, const std::string& type, int priority)
    : caseID(id), patientName(name), caseType(type), priorityLevel(priority) {}

std::string EmergencyCase::getCaseID() const {
    return caseID;
}

std::string EmergencyCase::getPatientName() const {
    return patientName;
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

void EmergencyCase::setPatientName(const std::string& name) {
    patientName = name;
}

void EmergencyCase::setCaseType(const std::string& type) {
    caseType = type;
}

void EmergencyCase::setPriorityLevel(int priority) {
    priorityLevel = priority;
}

void EmergencyCase::display() const {
    std::cout << "Case ID: " << caseID 
              << " | Patient: " << patientName
              << " | Type: " << caseType 
              << " | Priority: " << priorityLevel << std::endl;
}

