#include "MedicalSupplyManager.hpp"
#include <iostream>

MedicalSupplyManager::MedicalSupplyManager() {}

MedicalSupplyManager::~MedicalSupplyManager() {}

void MedicalSupplyManager::run() {
    int choice;
    do {
        std::cout << "\n===== Medical Supply Manager =====" << std::endl;
        std::cout << "1. Add Supply" << std::endl;
        std::cout << "2. Use Supply" << std::endl;
        std::cout << "3. View Supplies" << std::endl;
        std::cout << "4. Back to Main Menu" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
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
                std::cout << "Returning to main menu..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while(choice != 4);
}

void MedicalSupplyManager::addSupply() {
    // TODO: Implement adding supply
    std::cout << "Adding supply..." << std::endl;
}

void MedicalSupplyManager::useSupply() {
    // TODO: Implement using supply
    std::cout << "Using supply..." << std::endl;
}

void MedicalSupplyManager::viewSupplies() {
    // TODO: Display supply stack
    supplyStack.display();
}

