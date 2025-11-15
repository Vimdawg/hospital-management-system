#include "AmbulanceDispatcher.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <string>

AmbulanceDispatcher::AmbulanceDispatcher() {
    loadData();
}

AmbulanceDispatcher::~AmbulanceDispatcher() {
    saveData();
}

void AmbulanceDispatcher::run() {
    int choice;
    do {
        std::cout << "\n========================================" << std::endl;
        std::cout << "       AMBULANCE DISPATCHER MODULE" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "1. Register Ambulance" << std::endl;
        std::cout << "2. Rotate Ambulance Shift" << std::endl;
        std::cout << "3. Show Current Ambulance Rotation" << std::endl;
        std::cout << "4. Back to Main Menu" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "Enter your choice (1-4): ";
        
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
                rotateAmbulanceShift();
                break;
            case 3:
                showCurrentRotation();
                break;
            case 4:
                std::cout << "\n[INFO] Returning to main menu..." << std::endl;
                break;
            default:
                std::cout << "\n[ERROR] Invalid choice. Please select 1-4." << std::endl;
        }
    } while(choice != 4);
}

void AmbulanceDispatcher::registerAmbulance() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "        REGISTER NEW AMBULANCE" << std::endl;
    std::cout << "========================================" << std::endl;
    
    std::string licensePlate;
    
    // Get License Plate
    std::cout << "Enter License Plate Number: ";
    std::getline(std::cin, licensePlate);
    
    // Create Ambulance object and enqueue to circular queue
    Ambulance newAmbulance(licensePlate);
    ambulanceQueue.enqueue(newAmbulance);
    
    std::cout << "\n[SUCCESS] Ambulance " << licensePlate << " registered successfully!" << std::endl;
    std::cout << "Total ambulances in rotation: " << ambulanceQueue.getSize() << std::endl;
    
    saveData();
}

void AmbulanceDispatcher::rotateAmbulanceShift() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "       ROTATE AMBULANCE SHIFT" << std::endl;
    std::cout << "========================================" << std::endl;
    
    if (ambulanceQueue.isEmpty()) {
        std::cout << "\n[INFO] No ambulances in rotation to rotate." << std::endl;
        return;
    }
    
    // Show current on-duty before rotation
    Ambulance currentOnDuty = ambulanceQueue.getFront();
    std::cout << "\nCurrent 1st in queue: " << currentOnDuty.getLicensePlate() << std::endl;
    
    // Rotate the shift
    ambulanceQueue.rotate();
    
    // Show new on-duty after rotation
    Ambulance newOnDuty = ambulanceQueue.getFront();
    std::cout << "New 1st in queue: " << newOnDuty.getLicensePlate() << std::endl;
    
    std::cout << "\n[SUCCESS] Ambulance shift rotated successfully!" << std::endl;
    std::cout << "Total ambulances in rotation: " << ambulanceQueue.getSize() << std::endl;
    
    saveData();
}

void AmbulanceDispatcher::showCurrentRotation() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "    CURRENT AMBULANCE ROTATION" << std::endl;
    std::cout << "========================================" << std::endl;
    
    if (ambulanceQueue.isEmpty()) {
        std::cout << "\n[INFO] No ambulances in rotation schedule." << std::endl;
        return;
    }
    
    std::cout << "\nTotal ambulances in rotation: " << ambulanceQueue.getSize() << std::endl;
    std::cout << "\nRotation order (1st is currently on duty):" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    
    ambulanceQueue.display();
    
    std::cout << "========================================" << std::endl;
    std::cout << "[TIP] Use 'Rotate Ambulance Shift' to move to next ambulance" << std::endl;
}

void AmbulanceDispatcher::loadData() {
    std::ifstream file("data/ambulances.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            if (line.empty() || line[0] == '#') continue;
            
            // Each line contains just the license plate
            Ambulance ambulance(line);
            ambulanceQueue.enqueue(ambulance);
        }
        file.close();
    }
}

void AmbulanceDispatcher::saveData() {
    std::ofstream file("data/ambulances.txt");
    file << "# Ambulances data file" << std::endl;
    file << "# Format: LicensePlate" << std::endl;
    
    // Save all ambulances
    CircularQueue tempQueue;
    int count = ambulanceQueue.getSize();
    for (int i = 0; i < count; i++) {
        Ambulance a = ambulanceQueue.dequeue();
        file << a.getLicensePlate() << std::endl;
        tempQueue.enqueue(a);
    }
    
    // Restore queue
    for (int i = 0; i < count; i++) {
        ambulanceQueue.enqueue(tempQueue.dequeue());
    }
    
    file.close();
}
