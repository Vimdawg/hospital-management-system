#include "Ambulance.hpp"
#include <iostream>

Ambulance::Ambulance() : ambulanceID(""), driverName(""), region("") {}

Ambulance::Ambulance(const std::string& id, const std::string& driver, const std::string& reg)
    : ambulanceID(id), driverName(driver), region(reg) {}

std::string Ambulance::getAmbulanceID() const {
    return ambulanceID;
}

std::string Ambulance::getDriverName() const {
    return driverName;
}

std::string Ambulance::getRegion() const {
    return region;
}

void Ambulance::setAmbulanceID(const std::string& id) {
    ambulanceID = id;
}

void Ambulance::setDriverName(const std::string& driver) {
    driverName = driver;
}

void Ambulance::setRegion(const std::string& reg) {
    region = reg;
}

void Ambulance::display() const {
    std::cout << "Ambulance ID: " << ambulanceID 
              << " | Driver: " << driverName 
              << " | Region: " << region << std::endl;
}

