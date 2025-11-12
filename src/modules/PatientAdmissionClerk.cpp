#include "PatientAdmissionClerk.hpp"
#include <iostream>
#include <limits>
#include <string>

PatientAdmissionClerk::PatientAdmissionClerk() {}

PatientAdmissionClerk::~PatientAdmissionClerk() {}

void PatientAdmissionClerk::run() {
    int choice;
    do {
        std::cout << "\n========================================" << std::endl;
        std::cout << "     PATIENT ADMISSION CLERK MODULE" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "1. Admit Patient" << std::endl;
        std::cout << "2. Discharge Patient" << std::endl;
        std::cout << "3. View Patient Queue" << std::endl;
        std::cout << "4. View Next Patient" << std::endl;
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
                admitPatient();
                break;
            case 2:
                dischargePatient();
                break;
            case 3:
                viewPatientQueue();
                break;
            case 4:
                viewNextPatient();
                break;
            case 5:
                std::cout << "\n[INFO] Returning to main menu..." << std::endl;
                break;
            default:
                std::cout << "\n[ERROR] Invalid choice. Please select 1-5." << std::endl;
        }
    } while(choice != 5);
}

void PatientAdmissionClerk::admitPatient() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "          ADMIT NEW PATIENT" << std::endl;
    std::cout << "========================================" << std::endl;
    
    int patientID;
    std::string patientName;
    std::string conditionType;
    
    // Get Patient ID
    std::cout << "Enter Patient ID: ";
    while (!(std::cin >> patientID)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "[ERROR] Invalid input. Please enter a numeric ID: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    // Get Patient Name
    std::cout << "Enter Patient Name: ";
    std::getline(std::cin, patientName);
    
    // Get Condition Type
    std::cout << "Enter Condition Type (e.g., General, Surgery, Maternity): ";
    std::getline(std::cin, conditionType);
    
    // Create Patient object and add to queue
    Patient newPatient(patientID, patientName, conditionType);
    patientQueue.enqueue(newPatient);
    
    std::cout << "\nCurrent queue size: " << patientQueue.getSize() << " patients waiting." << std::endl;
}

void PatientAdmissionClerk::dischargePatient() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "         DISCHARGE PATIENT" << std::endl;
    std::cout << "========================================" << std::endl;
    
    if (patientQueue.isEmpty()) {
        std::cout << "\n[INFO] No patients in queue to discharge." << std::endl;
        return;
    }
    
    // Dequeue patient
    Patient dischargedPatient = patientQueue.dequeue();
    
    // Display discharged patient info
    if (dischargedPatient.getPatientID() != 0) {  // Valid patient
        std::cout << "\n[SUCCESS] Patient discharged successfully!" << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Patient ID: " << dischargedPatient.getPatientID() << std::endl;
        std::cout << "Name: " << dischargedPatient.getPatientName() << std::endl;
        std::cout << "Condition: " << dischargedPatient.getConditionType() << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Remaining patients in queue: " << patientQueue.getSize() << std::endl;
    }
}

void PatientAdmissionClerk::viewPatientQueue() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "      VIEW ALL PATIENTS IN QUEUE" << std::endl;
    std::cout << "========================================" << std::endl;
    
    patientQueue.display();
}

void PatientAdmissionClerk::viewNextPatient() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "         NEXT PATIENT TO SEE" << std::endl;
    std::cout << "========================================" << std::endl;
    
    if (patientQueue.isEmpty()) {
        std::cout << "\n[INFO] No patients in queue." << std::endl;
        return;
    }
    
    Patient nextPatient = patientQueue.getFront();
    std::cout << "\nNext patient to be seen:" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Patient ID: " << nextPatient.getPatientID() << std::endl;
    std::cout << "Name: " << nextPatient.getPatientName() << std::endl;
    std::cout << "Condition: " << nextPatient.getConditionType() << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}

