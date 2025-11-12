#include <iostream>
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
    
    std::cout << "Welcome to Hospital Patient Care Management System (HPCMS)" << std::endl;
    
    do {
        MenuSystem::displayMainMenu();
        std::cin >> choice;
        
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
                std::cout << "\nThank you for using HPCMS. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please select 1-5." << std::endl;
        }
    } while(choice != 5);
    
    return 0;
}

