#include "PatientAdmissionClerk.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <string>
#include <vector>

PatientAdmissionClerk::PatientAdmissionClerk() : nextPatientID(1) {
    loadCounters();
    loadData();
}

PatientAdmissionClerk::~PatientAdmissionClerk() {
    saveData();
    saveCounters();
}

void PatientAdmissionClerk::run() {
    int choice;
    do {
        std::cout << "\n========================================" << std::endl;
        std::cout << "     PATIENT ADMISSION CLERK MODULE" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "1. Admit Patient" << std::endl;
        std::cout << "2. Discharge Patient" << std::endl;
        std::cout << "3. View Patient Queue" << std::endl;
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
                admitPatient();
                break;
            case 2:
                dischargePatient();
                break;
            case 3:
                viewPatientQueue();
                break;
            case 4:
                std::cout << "\n[INFO] Returning to main menu..." << std::endl;
                break;
            default:
                std::cout << "\n[ERROR] Invalid choice. Please select 1-4." << std::endl;
        }
    } while(choice != 4);
}

void PatientAdmissionClerk::admitPatient() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "          ADMIT NEW PATIENT" << std::endl;
    std::cout << "========================================" << std::endl;
    
    std::string patientName;
    std::string nationalIC;
    std::string conditionType;
    
    // Get Patient Name
    std::cout << "Enter Patient Name: ";
    std::getline(std::cin, patientName);
    
    // Get National IC Number
    std::cout << "Enter National IC Number: ";
    std::getline(std::cin, nationalIC);
    
    // Get Condition Type
    std::cout << "Enter Condition Type (e.g., General, Surgery, Maternity): ";
    std::getline(std::cin, conditionType);
    
    // Create Patient object with auto-generated ID and add to queue
    Patient newPatient(nextPatientID, patientName, nationalIC, conditionType);
    patientQueue.enqueue(newPatient);
    
    std::cout << "\n[SUCCESS] Patient admitted with ID: " << nextPatientID << std::endl;
    nextPatientID++;  // Increment for next patient
    
    std::cout << "Current queue size: " << patientQueue.getSize() << " patients waiting." << std::endl;
    
    saveData();
    saveCounters();
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
        std::cout << "IC Number: " << dischargedPatient.getNationalIC() << std::endl;
        std::cout << "Condition: " << dischargedPatient.getConditionType() << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Remaining patients in queue: " << patientQueue.getSize() << std::endl;
        
        saveData();
    }
}

void PatientAdmissionClerk::viewPatientQueue() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "      VIEW ALL PATIENTS IN QUEUE" << std::endl;
    std::cout << "========================================" << std::endl;
    
    patientQueue.display();
}

void PatientAdmissionClerk::loadCounters() {
    std::ifstream file("data/patients.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            if (line.find("# NextPatientID:") == 0) {
                nextPatientID = std::atoi(line.substr(17).c_str());
                break;
            }
        }
        file.close();
    }
}

void PatientAdmissionClerk::saveCounters() {
    // Counter is saved as part of saveData()
}

void PatientAdmissionClerk::loadData() {
    std::ifstream file("data/patients.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            // Skip comments and empty lines
            if (line.empty() || line[0] == '#') continue;
            
            std::stringstream ss(line);
            std::string token;
            int patientID;
            std::string patientName, nationalIC, conditionType;
            
            // Parse: PatientID|PatientName|NationalIC|ConditionType
            std::getline(ss, token, '|'); 
            patientID = std::atoi(token.c_str());
            std::getline(ss, patientName, '|');
            std::getline(ss, nationalIC, '|');
            std::getline(ss, conditionType, '|');
            
            Patient patient(patientID, patientName, nationalIC, conditionType);
            patientQueue.enqueue(patient);
        }
        file.close();
    }
}

void PatientAdmissionClerk::saveData() {
    std::ofstream file("data/patients.txt");
    file << "# Patient data file" << std::endl;
    file << "# NextPatientID: " << nextPatientID << std::endl;
    file << "# Format: PatientID|PatientName|NationalIC|ConditionType" << std::endl;
    
    // Save all patients in the queue
    Queue tempQueue;
    while (!patientQueue.isEmpty()) {
        Patient p = patientQueue.dequeue();
        file << p.getPatientID() << "|"
             << p.getPatientName() << "|"
             << p.getNationalIC() << "|"
             << p.getConditionType() << std::endl;
        tempQueue.enqueue(p);
    }
    
    // Restore queue
    while (!tempQueue.isEmpty()) {
        patientQueue.enqueue(tempQueue.dequeue());
    }
    
    file.close();
}


