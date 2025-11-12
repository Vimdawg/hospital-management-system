#include "EmergencyDeptOfficer.hpp"
#include <iostream>

EmergencyDeptOfficer::EmergencyDeptOfficer() {}

EmergencyDeptOfficer::~EmergencyDeptOfficer() {}

void EmergencyDeptOfficer::run() {
    int choice;
    do {
        std::cout << "\n===== Emergency Department Officer =====" << std::endl;
        std::cout << "1. Log Emergency Case" << std::endl;
        std::cout << "2. Process Emergency Case" << std::endl;
        std::cout << "3. View Emergency Cases" << std::endl;
        std::cout << "4. Back to Main Menu" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        switch(choice) {
            case 1:
                logEmergencyCase();
                break;
            case 2:
                processEmergencyCase();
                break;
            case 3:
                viewEmergencyCases();
                break;
            case 4:
                std::cout << "Returning to main menu..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while(choice != 4);
}

void EmergencyDeptOfficer::logEmergencyCase() {
    // TODO: Implement logging emergency case
    std::cout << "Logging emergency case..." << std::endl;
}

void EmergencyDeptOfficer::processEmergencyCase() {
    // TODO: Implement processing emergency case
    std::cout << "Processing emergency case..." << std::endl;
}

void EmergencyDeptOfficer::viewEmergencyCases() {
    // TODO: Display emergency cases
    emergencyQueue.display();
}

