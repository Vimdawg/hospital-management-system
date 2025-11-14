#include "MedicalSupplyManager.hpp"
#include <iostream>
#include <limits>
#include <string>

MedicalSupplyManager::MedicalSupplyManager() {}

MedicalSupplyManager::~MedicalSupplyManager() {}

void MedicalSupplyManager::run() {
    int choice;
    do {
        std::cout << "\n========================================" << std::endl;
        std::cout << "      MEDICAL SUPPLY MANAGER MODULE" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "1. Add Supply" << std::endl;
        std::cout << "2. Use Supply" << std::endl;
        std::cout << "3. View All Supplies" << std::endl;
        std::cout << "4. View Top Supply" << std::endl;
        std::cout << "5. Back to Main Menu" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "Enter your choice (1-5): ";
        
        // Input validation
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n[ERROR] Invalid input. Please enter a number." << std::endl;
            continue;
        }
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch(choice) {
            case 1:
                addSupply();
                break;
            case 2:
                useSupply();
                break;
            case 3:
                viewSupplies();
                break;
            case 4:
                viewTopSupply();
                break;
            case 5:
                std::cout << "\n[INFO] Returning to main menu..." << std::endl;
                break;
            default:
                std::cout << "\n[ERROR] Invalid choice. Please select 1-5." << std::endl;
        }
    } while(choice != 5);
}

void MedicalSupplyManager::addSupply() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "           ADD NEW SUPPLY" << std::endl;
    std::cout << "========================================" << std::endl;
    
    std::string supplyType;
    int quantity;
    std::string batchID;
    
    // Get Supply Type
    std::cout << "Enter Supply Type (e.g., Mask, Glove, Medicine, Syringe): ";
    std::getline(std::cin, supplyType);
    
    // Get Quantity
    std::cout << "Enter Quantity: ";
    while (!(std::cin >> quantity) || quantity <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "[ERROR] Invalid input. Please enter a positive number: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    // Get Batch ID
    std::cout << "Enter Batch ID: ";
    std::getline(std::cin, batchID);
    
    // Create MedicalSupply object and push to stack
    MedicalSupply newSupply(supplyType, quantity, batchID);
    supplyStack.push(newSupply);
    
    std::cout << "\nCurrent stack size: " << supplyStack.getSize() << " supplies in inventory." << std::endl;
}

void MedicalSupplyManager::useSupply() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "            USE SUPPLY (POP)" << std::endl;
    std::cout << "========================================" << std::endl;
    
    if (supplyStack.isEmpty()) {
        std::cout << "\n[INFO] No supplies in inventory to use." << std::endl;
        return;
    }
    
    // Pop supply from stack
    MedicalSupply usedSupply = supplyStack.pop();
    
    // Display used supply info
    if (usedSupply.getQuantity() != 0) {  // Valid supply
        std::cout << "\n[SUCCESS] Supply used successfully!" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "Supply Type: " << usedSupply.getSupplyType() << std::endl;
        std::cout << "Quantity: " << usedSupply.getQuantity() << std::endl;
        std::cout << "Batch ID: " << usedSupply.getBatchID() << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "Remaining supplies in stack: " << supplyStack.getSize() << std::endl;
    }
}

void MedicalSupplyManager::viewSupplies() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "       VIEW ALL SUPPLIES IN STACK" << std::endl;
    std::cout << "========================================" << std::endl;
    
    supplyStack.display();
}

void MedicalSupplyManager::viewTopSupply() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "           TOP SUPPLY (PEEK)" << std::endl;
    std::cout << "========================================" << std::endl;
    
    if (supplyStack.isEmpty()) {
        std::cout << "\n[INFO] No supplies in stack." << std::endl;
        return;
    }
    
    MedicalSupply topSupply = supplyStack.peek();
    std::cout << "\nTop supply (will be used next):" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Supply Type: " << topSupply.getSupplyType() << std::endl;
    std::cout << "Quantity: " << topSupply.getQuantity() << std::endl;
    std::cout << "Batch ID: " << topSupply.getBatchID() << std::endl;
    std::cout << "========================================" << std::endl;
}

