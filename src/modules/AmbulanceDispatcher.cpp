#include "AmbulanceDispatcher.hpp"
#include <iostream>

AmbulanceDispatcher::AmbulanceDispatcher() {}

AmbulanceDispatcher::~AmbulanceDispatcher() {}

void AmbulanceDispatcher::run() {
    int choice;
    do {
        std::cout << "\n===== Ambulance Dispatcher =====" << std::endl;
        std::cout << "1. Register Ambulance" << std::endl;
        std::cout << "2. Rotate Shift" << std::endl;
        std::cout << "3. View Ambulance Schedule" << std::endl;
        std::cout << "4. Back to Main Menu" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        switch(choice) {
            case 1:
                registerAmbulance();
                break;
            case 2:
                rotateShift();
                break;
            case 3:
                viewAmbulanceSchedule();
                break;
            case 4:
                std::cout << "Returning to main menu..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while(choice != 4);
}

void AmbulanceDispatcher::registerAmbulance() {
    // TODO: Implement registering ambulance
    std::cout << "Registering ambulance..." << std::endl;
}

void AmbulanceDispatcher::rotateShift() {
    // TODO: Implement rotating shift
    std::cout << "Rotating shift..." << std::endl;
}

void AmbulanceDispatcher::viewAmbulanceSchedule() {
    // TODO: Display ambulance schedule
    ambulanceQueue.display();
}

