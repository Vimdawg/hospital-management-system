#include "MedicalSupply.hpp"
#include <iostream>
#include <iomanip>

MedicalSupply::MedicalSupply() : itemID(0), supplyType(""), quantity(0), batchNumber(0) {}

MedicalSupply::MedicalSupply(int id, const std::string& type, int qty, int batch)
    : itemID(id), supplyType(type), quantity(qty), batchNumber(batch) {}

int MedicalSupply::getItemID() const {
    return itemID;
}

std::string MedicalSupply::getSupplyType() const {
    return supplyType;
}

int MedicalSupply::getQuantity() const {
    return quantity;
}

int MedicalSupply::getBatchNumber() const {
    return batchNumber;
}

void MedicalSupply::setItemID(int id) {
    itemID = id;
}

void MedicalSupply::setSupplyType(const std::string& type) {
    supplyType = type;
}

void MedicalSupply::setQuantity(int qty) {
    quantity = qty;
}

void MedicalSupply::setBatchNumber(int batch) {
    batchNumber = batch;
}

void MedicalSupply::display() const {
    std::cout << "Item ID: " << std::setw(4) << itemID 
              << " | Type: " << std::setw(15) << std::left << supplyType 
              << " | Qty: " << std::setw(4) << std::right << quantity 
              << " | Batch: " << batchNumber << std::endl;
}

