#include "MedicalSupply.hpp"
#include <iostream>

MedicalSupply::MedicalSupply() : supplyType(""), quantity(0), batchID("") {}

MedicalSupply::MedicalSupply(const std::string& type, int qty, const std::string& batch)
    : supplyType(type), quantity(qty), batchID(batch) {}

std::string MedicalSupply::getSupplyType() const {
    return supplyType;
}

int MedicalSupply::getQuantity() const {
    return quantity;
}

std::string MedicalSupply::getBatchID() const {
    return batchID;
}

void MedicalSupply::setSupplyType(const std::string& type) {
    supplyType = type;
}

void MedicalSupply::setQuantity(int qty) {
    quantity = qty;
}

void MedicalSupply::setBatchID(const std::string& batch) {
    batchID = batch;
}

void MedicalSupply::display() const {
    std::cout << "Supply Type: " << supplyType 
              << " | Quantity: " << quantity 
              << " | Batch ID: " << batchID << std::endl;
}

