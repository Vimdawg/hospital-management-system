#include "PatientAdmissionClerk.hpp"
#include <iostream>

PatientAdmissionClerk::PatientAdmissionClerk() {}

PatientAdmissionClerk::~PatientAdmissionClerk() {}

void PatientAdmissionClerk::run() {
    int choice;
    do {
        std::cout << "\n===== Patient Admission Clerk =====" << std::endl;
        std::cout << "1. Admit Patient" << std::endl;
        std::cout << "2. Discharge Patient" << std::endl;
        std::cout << "3. View Patient Queue" << std::endl;
        std::cout << "4. Back to Main Menu" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        switch(choice) {
            case 1:
                admitPatient();
                break;
            case 2:
                dischargePatient();
                break;
            case 3:
                viewPatientQueue();
                break;
            case 4:
                std::cout << "Returning to main menu..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while(choice != 4);
}

void PatientAdmissionClerk::admitPatient() {
    // TODO: Implement patient admission
    std::cout << "Admitting patient..." << std::endl;
}

void PatientAdmissionClerk::dischargePatient() {
    // TODO: Implement patient discharge
    std::cout << "Discharging patient..." << std::endl;
}

void PatientAdmissionClerk::viewPatientQueue() {
    // TODO: Display patient queue
    patientQueue.display();
}

