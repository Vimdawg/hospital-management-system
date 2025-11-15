#include "Ambulance.hpp"
#include <iostream>

Ambulance::Ambulance() : licensePlate("") {}

Ambulance::Ambulance(const std::string& plate) : licensePlate(plate) {}

std::string Ambulance::getLicensePlate() const {
    return licensePlate;
}

void Ambulance::setLicensePlate(const std::string& plate) {
    licensePlate = plate;
}

void Ambulance::display() const {
    std::cout << "License Plate: " << licensePlate << std::endl;
}

