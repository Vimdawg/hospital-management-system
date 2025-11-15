#include "EmergencyDeptOfficer.hpp"
#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <sstream>

EmergencyDeptOfficer::EmergencyDeptOfficer() : nextCaseID(1) {
    loadData();
}

EmergencyDeptOfficer::~EmergencyDeptOfficer() {
    saveData();
}

void EmergencyDeptOfficer::run() {
    int choice;
    do {
        std::cout << "\n========================================" << std::endl;
        std::cout << "    EMERGENCY DEPARTMENT OFFICER MODULE" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "1. Log Emergency Case" << std::endl;
        std::cout << "2. Process Emergency Case" << std::endl;
        std::cout << "3. View All Emergency Cases" << std::endl;
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
                logEmergencyCase();
                break;
            case 2:
                processEmergencyCase();
                break;
            case 3:
                viewEmergencyCases();
                break;
            case 4:
                std::cout << "\n[INFO] Returning to main menu..." << std::endl;
                break;
            default:
                std::cout << "\n[ERROR] Invalid choice. Please select 1-4." << std::endl;
        }
    } while(choice != 4);
}

void EmergencyDeptOfficer::logEmergencyCase() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "        LOG NEW EMERGENCY CASE" << std::endl;
    std::cout << "========================================" << std::endl;
    
    std::string patientName;
    std::string caseType;
    int priorityLevel;
    
    // Get Patient Name
    std::cout << "Enter Patient Name: ";
    std::getline(std::cin, patientName);
    
    // Get Case Type
    std::cout << "Enter Type of Emergency (e.g., Accident, Cardiac, Trauma, Stroke): ";
    std::getline(std::cin, caseType);
    
    // Get Priority Level
    std::cout << "\nPriority Levels Guide:" << std::endl;
    std::cout << "  9-10: CRITICAL (Life-threatening)" << std::endl;
    std::cout << "  7-8:  HIGH (Urgent care needed)" << std::endl;
    std::cout << "  5-6:  MEDIUM (Moderate urgency)" << std::endl;
    std::cout << "  1-4:  LOW (Non-urgent)" << std::endl;
    std::cout << "\nEnter Priority Level (1-10): ";
    
    while (!(std::cin >> priorityLevel) || priorityLevel < 1 || priorityLevel > 10) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "[ERROR] Invalid input. Please enter a number between 1-10: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    // Generate case ID
    std::ostringstream caseIDStream;
    caseIDStream << "EC" << nextCaseID;
    std::string caseID = caseIDStream.str();
    
    // Create EmergencyCase object and insert to priority queue
    EmergencyCase newCase(caseID, patientName, caseType, priorityLevel);
    emergencyQueue.insert(newCase);
    
    std::cout << "\n[SUCCESS] Emergency case logged with ID: " << caseID << std::endl;
    nextCaseID++;  // Increment for next case
    
    std::cout << "Current queue size: " << emergencyQueue.getSize() << " emergency cases pending." << std::endl;
    
    saveData();
}

void EmergencyDeptOfficer::processEmergencyCase() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "      PROCESS HIGHEST PRIORITY CASE" << std::endl;
    std::cout << "========================================" << std::endl;
    
    if (emergencyQueue.isEmpty()) {
        std::cout << "\n[INFO] No emergency cases to process." << std::endl;
        return;
    }
    
    // Extract highest priority case
    EmergencyCase processedCase = emergencyQueue.extractHighestPriority();
    
    // Display processed case info
    if (!processedCase.getCaseID().empty()) {  // Valid case
        std::cout << "\n[SUCCESS] Emergency case processed!" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "Case ID: " << processedCase.getCaseID() << std::endl;
        std::cout << "Patient Name: " << processedCase.getPatientName() << std::endl;
        std::cout << "Case Type: " << processedCase.getCaseType() << std::endl;
        std::cout << "Priority Level: " << processedCase.getPriorityLevel() << std::endl;
        
        // Show priority label
        int priority = processedCase.getPriorityLevel();
        std::string priorityLabel;
        if (priority >= 9) priorityLabel = "CRITICAL";
        else if (priority >= 7) priorityLabel = "HIGH";
        else if (priority >= 5) priorityLabel = "MEDIUM";
        else priorityLabel = "LOW";
        
        std::cout << "Priority Category: " << priorityLabel << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "Remaining cases in queue: " << emergencyQueue.getSize() << std::endl;
        
        saveData();
    }
}

void EmergencyDeptOfficer::viewEmergencyCases() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "     VIEW ALL EMERGENCY CASES" << std::endl;
    std::cout << "========================================" << std::endl;
    
    emergencyQueue.display();
}

void EmergencyDeptOfficer::loadData() {
    std::ifstream file("data/emergency_cases.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            if (line.find("# NextCaseID:") == 0) {
                nextCaseID = std::atoi(line.substr(14).c_str());
                continue;
            }
            if (line.empty() || line[0] == '#') continue;
            
            std::stringstream ss(line);
            std::string caseID, patientName, caseType, token;
            int priorityLevel;
            
            std::getline(ss, caseID, '|');
            std::getline(ss, patientName, '|');
            std::getline(ss, caseType, '|');
            std::getline(ss, token, '|');
            priorityLevel = std::atoi(token.c_str());
            
            EmergencyCase emergencyCase(caseID, patientName, caseType, priorityLevel);
            emergencyQueue.insert(emergencyCase);
        }
        file.close();
    }
}

void EmergencyDeptOfficer::saveData() {
    std::ofstream file("data/emergency_cases.txt");
    file << "# Emergency cases data file" << std::endl;
    file << "# NextCaseID: " << nextCaseID << std::endl;
    file << "# Format: CaseID|PatientName|CaseType|PriorityLevel" << std::endl;
    
    // Save all cases - extract and reinsert
    PriorityQueue tempQueue;
    while (!emergencyQueue.isEmpty()) {
        EmergencyCase c = emergencyQueue.extractHighestPriority();
        file << c.getCaseID() << "|"
             << c.getPatientName() << "|"
             << c.getCaseType() << "|"
             << c.getPriorityLevel() << std::endl;
        tempQueue.insert(c);
    }
    
    // Restore queue
    while (!tempQueue.isEmpty()) {
        emergencyQueue.insert(tempQueue.extractHighestPriority());
    }
    
    file.close();
}


