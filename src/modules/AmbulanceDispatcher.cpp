#include "AmbulanceDispatcher.hpp"
#include <iostream>
#include <limits>
#include <string>

AmbulanceDispatcher::AmbulanceDispatcher() {}

AmbulanceDispatcher::~AmbulanceDispatcher() {}

void AmbulanceDispatcher::run() {
    int choice;
    do {
        std::cout << "\n========================================" << std::endl;
        std::cout << "       AMBULANCE DISPATCHER MODULE" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "1. Register Ambulance" << std::endl;
        std::cout << "2. Rotate Shift" << std::endl;
        std::cout << "3. View Ambulance Schedule" << std::endl;
        std::cout << "4. View Current On-Duty" << std::endl;
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
                registerAmbulance();
                break;
            case 2:
                rotateShift();
                break;
            case 3:
                viewAmbulanceSchedule();
                break;
            case 4:
                viewCurrentOnDuty();
                break;
            case 5:
                std::cout << "\n[INFO] Returning to main menu..." << std::endl;
                break;
            default:
                std::cout << "\n[ERROR] Invalid choice. Please select 1-5." << std::endl;
        }
    } while(choice != 5);
}

void AmbulanceDispatcher::registerAmbulance() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "        REGISTER NEW AMBULANCE" << std::endl;
    std::cout << "========================================" << std::endl;
    
    std::string ambulanceID;
    std::string driverName;
    std::string region;
    
    // Get Ambulance ID
    std::cout << "Enter Ambulance ID (e.g., AMB001, AMB002): ";
    std::getline(std::cin, ambulanceID);
    
    // Get Driver Name
    std::cout << "Enter Driver/Team Name: ";
    std::getline(std::cin, driverName);
    
    // Get Region
    std::cout << "Enter Region (e.g., North, South, East, West, Central): ";
    std::getline(std::cin, region);
    
    // Create Ambulance object and enqueue to circular queue
    Ambulance newAmbulance(ambulanceID, driverName, region);
    ambulanceQueue.enqueue(newAmbulance);
    
    std::cout << "\nCurrent schedule size: " << ambulanceQueue.getSize() << " ambulances." << std::endl;
}

void AmbulanceDispatcher::rotateShift() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "          ROTATE AMBULANCE SHIFT" << std::endl;
    std::cout << "========================================" << std::endl;
    
    if (ambulanceQueue.isEmpty()) {
        std::cout << "\n[INFO] No ambulances in schedule to rotate." << std::endl;
        return;
    }
    
    // Show current on-duty before rotation
    Ambulance currentOnDuty = ambulanceQueue.getFront();
    std::cout << "\nCurrent on-duty: " << currentOnDuty.getAmbulanceID() 
              << " (" << currentOnDuty.getDriverName() << ")" << std::endl;
    
    // Rotate the shift
    ambulanceQueue.rotate();
    
    std::cout << "\nAmbulances in rotation: " << ambulanceQueue.getSize() << std::endl;
}

void AmbulanceDispatcher::viewAmbulanceSchedule() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "     VIEW FULL AMBULANCE SCHEDULE" << std::endl;
    std::cout << "========================================" << std::endl;
    
    ambulanceQueue.display();
}

void AmbulanceDispatcher::viewCurrentOnDuty() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "       CURRENT ON-DUTY AMBULANCE" << std::endl;
    std::cout << "========================================" << std::endl;
    
    if (ambulanceQueue.isEmpty()) {
        std::cout << "\n[INFO] No ambulances in schedule." << std::endl;
        return;
    }
    
    Ambulance currentAmbulance = ambulanceQueue.getFront();
    std::cout << "\nCurrently on duty:" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Ambulance ID: " << currentAmbulance.getAmbulanceID() << std::endl;
    std::cout << "Driver/Team: " << currentAmbulance.getDriverName() << std::endl;
    std::cout << "Region: " << currentAmbulance.getRegion() << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "[TIP] Use 'Rotate Shift' to switch to next ambulance" << std::endl;
}

