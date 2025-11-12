#include <iostream>
#include <limits>
#include "modules/PatientAdmissionClerk.hpp"
#include "modules/MedicalSupplyManager.hpp"
#include "modules/EmergencyDeptOfficer.hpp"
#include "modules/AmbulanceDispatcher.hpp"
#include "utils/MenuSystem.hpp"
#include "utils/InputValidator.hpp"

int main() {
    // Create module instances
    PatientAdmissionClerk admissionClerk;
    MedicalSupplyManager supplyManager;
    EmergencyDeptOfficer emergencyOfficer;
    AmbulanceDispatcher dispatcher;
    
    int choice;
    
    std::cout << "\n========================================" << std::endl;
    std::cout << "  Welcome to Hospital Patient Care" << std::endl;
    std::cout << "     Management System (HPCMS)" << std::endl;
    std::cout << "========================================" << std::endl;
    
    do {
        MenuSystem::displayMainMenu();
        
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
                admissionClerk.run();
                break;
            case 2:
                supplyManager.run();
                break;
            case 3:
                emergencyOfficer.run();
                break;
            case 4:
                dispatcher.run();
                break;
            case 5:
                std::cout << "\n========================================" << std::endl;
                std::cout << "  Thank you for using HPCMS!" << std::endl;
                std::cout << "  Goodbye!" << std::endl;
                std::cout << "========================================\n" << std::endl;
                break;
            default:
                std::cout << "\n[ERROR] Invalid choice. Please select 1-5." << std::endl;
        }
    } while(choice != 5);
    
    return 0;
}

