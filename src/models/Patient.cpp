#include "Patient.hpp"
#include <iostream>

Patient::Patient() : patientID(0), patientName(""), nationalIC(""), conditionType("") {}

Patient::Patient(int id, const std::string& name, const std::string& ic, const std::string& condition)
    : patientID(id), patientName(name), nationalIC(ic), conditionType(condition) {}

int Patient::getPatientID() const {
    return patientID;
}

std::string Patient::getPatientName() const {
    return patientName;
}

std::string Patient::getNationalIC() const {
    return nationalIC;
}

std::string Patient::getConditionType() const {
    return conditionType;
}

void Patient::setPatientID(int id) {
    patientID = id;
}

void Patient::setPatientName(const std::string& name) {
    patientName = name;
}

void Patient::setNationalIC(const std::string& ic) {
    nationalIC = ic;
}

void Patient::setConditionType(const std::string& condition) {
    conditionType = condition;
}

void Patient::display() const {
    std::cout << "Patient ID: " << patientID 
              << " | Name: " << patientName 
              << " | IC: " << nationalIC
              << " | Condition: " << conditionType << std::endl;
}

