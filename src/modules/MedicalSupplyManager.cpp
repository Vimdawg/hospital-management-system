#include "MedicalSupplyManager.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <string>
#include <map>
#include <iomanip>

MedicalSupplyManager::MedicalSupplyManager() : nextItemID(1), nextBatchNumber(1) {
    loadData();
}

MedicalSupplyManager::~MedicalSupplyManager() {
    saveData();
}

void MedicalSupplyManager::run() {
    int choice;
    do {
        std::cout << "\n========================================" << std::endl;
        std::cout << "      MEDICAL SUPPLY MANAGER MODULE" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "1. Add Supply Stock" << std::endl;
        std::cout << "2. Use Last Added Supply" << std::endl;
        std::cout << "3. View Current Supply" << std::endl;
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
                addSupplyStock();
                break;
            case 2:
                useLastAddedSupply();
                break;
            case 3:
                viewCurrentSupply();
                break;
            case 4:
                std::cout << "\n[INFO] Returning to main menu..." << std::endl;
                break;
            default:
                std::cout << "\n[ERROR] Invalid choice. Please select 1-4." << std::endl;
        }
    } while(choice != 4);
}

void MedicalSupplyManager::addSupplyStock() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "         ADD SUPPLY STOCK BATCH" << std::endl;
    std::cout << "========================================" << std::endl;
    
    int currentBatchNumber = nextBatchNumber;
    std::string addMore;
    
    do {
        std::string supplyType;
        int quantity;
        
        // Get Supply Type
        std::cout << "\nEnter Supply Type (e.g., Mask, Glove, Syringe, Bandage): ";
        std::getline(std::cin, supplyType);
        
        // Get Quantity
        std::cout << "Enter Quantity: ";
        while (!(std::cin >> quantity) || quantity <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "[ERROR] Invalid input. Please enter a positive number: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        // Create MedicalSupply object with auto-generated IDs
        MedicalSupply newSupply(nextItemID, supplyType, quantity, currentBatchNumber);
        supplyStack.push(newSupply);
        
        std::cout << "[SUCCESS] Item ID " << nextItemID 
                  << " added to Batch #" << currentBatchNumber << std::endl;
        nextItemID++;
        
        // Ask if user wants to add more to this batch
        std::cout << "\nAdd another item to this batch? (yes/no): ";
        std::getline(std::cin, addMore);
        
    } while (addMore == "yes" || addMore == "y" || addMore == "Yes" || addMore == "YES");
    
    std::cout << "\n[SUCCESS] Batch #" << currentBatchNumber << " completed!" << std::endl;
    std::cout << "Total items in inventory: " << supplyStack.getSize() << std::endl;
    nextBatchNumber++;  // Increment batch number for next batch
    
    saveData();
}

void MedicalSupplyManager::useLastAddedSupply() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "         USE LAST ADDED SUPPLY" << std::endl;
    std::cout << "========================================" << std::endl;
    
    if (supplyStack.isEmpty()) {
        std::cout << "\n[INFO] No supplies in inventory to use." << std::endl;
        return;
    }
    
    // Pop the last added supply
    MedicalSupply lastSupply = supplyStack.pop();
    
    // Display used supply info
    if (lastSupply.getItemID() != 0) {  // Valid supply
        // Use one unit
        int newQuantity = lastSupply.getQuantity() - 1;
        
        std::cout << "\n[SUCCESS] Used 1 unit from last added supply!" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "Item ID: " << lastSupply.getItemID() << std::endl;
        std::cout << "Supply Type: " << lastSupply.getSupplyType() << std::endl;
        std::cout << "Previous Quantity: " << lastSupply.getQuantity() << std::endl;
        std::cout << "New Quantity: " << newQuantity << std::endl;
        std::cout << "Batch Number: " << lastSupply.getBatchNumber() << std::endl;
        std::cout << "========================================" << std::endl;
        
        // If there are still units left, push it back to the stack
        if (newQuantity > 0) {
            lastSupply.setQuantity(newQuantity);
            supplyStack.push(lastSupply);
        }
        
        std::cout << "\n[INFO] Remaining items in inventory: " << supplyStack.getSize() << std::endl;
        
        saveData();
    }
}

void MedicalSupplyManager::viewCurrentSupply() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "       CURRENT SUPPLY INVENTORY" << std::endl;
    std::cout << "========================================" << std::endl;
    
    if (supplyStack.isEmpty()) {
        std::cout << "\n[INFO] No supplies in inventory." << std::endl;
        return;
    }
    
    std::cout << "\nAll Items (Different batches shown separately):" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    supplyStack.display();
    
    // Calculate and display totals by type
    std::cout << "\n========================================" << std::endl;
    std::cout << "         TOTAL SUMMARY BY TYPE" << std::endl;
    std::cout << "========================================" << std::endl;
    
    // We need to traverse the stack to calculate totals
    // Since we can't directly access all elements, we'll pop and repush
    Stack tempStack;
    std::map<std::string, int> typeTotals;
    
    // Pop all items and calculate totals
    while (!supplyStack.isEmpty()) {
        MedicalSupply supply = supplyStack.pop();
        typeTotals[supply.getSupplyType()] += supply.getQuantity();
        tempStack.push(supply);
    }
    
    // Restore the original stack
    while (!tempStack.isEmpty()) {
        supplyStack.push(tempStack.pop());
    }
    
    // Display totals
    if (typeTotals.empty()) {
        std::cout << "\n[INFO] No supplies to summarize." << std::endl;
    } else {
        std::cout << std::left << std::setw(20) << "Type" << std::right << std::setw(10) << "Total Qty" << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        for (std::map<std::string, int>::const_iterator it = typeTotals.begin(); 
             it != typeTotals.end(); ++it) {
            std::cout << std::left << std::setw(20) << it->first 
                      << std::right << std::setw(10) << it->second << std::endl;
        }
    }
    std::cout << "========================================" << std::endl;
}

void MedicalSupplyManager::loadData() {
    std::ifstream file("data/supplies.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            if (line.find("# NextItemID:") == 0) {
                nextItemID = std::atoi(line.substr(14).c_str());
                continue;
            }
            if (line.find("# NextBatchNumber:") == 0) {
                nextBatchNumber = std::atoi(line.substr(19).c_str());
                continue;
            }
            if (line.empty() || line[0] == '#') continue;
            
            std::stringstream ss(line);
            std::string token;
            int itemID, quantity, batchNumber;
            std::string supplyType;
            
            std::getline(ss, token, '|');
            itemID = std::atoi(token.c_str());
            std::getline(ss, supplyType, '|');
            std::getline(ss, token, '|');
            quantity = std::atoi(token.c_str());
            std::getline(ss, token, '|');
            batchNumber = std::atoi(token.c_str());
            
            MedicalSupply supply(itemID, supplyType, quantity, batchNumber);
            supplyStack.push(supply);
        }
        file.close();
    }
}

void MedicalSupplyManager::saveData() {
    std::ofstream file("data/supplies.txt");
    file << "# Medical supplies data file" << std::endl;
    file << "# NextItemID: " << nextItemID << std::endl;
    file << "# NextBatchNumber: " << nextBatchNumber << std::endl;
    file << "# Format: ItemID|SupplyType|Quantity|BatchNumber" << std::endl;
    
    // Save all supplies
    Stack tempStack;
    while (!supplyStack.isEmpty()) {
        MedicalSupply s = supplyStack.pop();
        file << s.getItemID() << "|"
             << s.getSupplyType() << "|"
             << s.getQuantity() << "|"
             << s.getBatchNumber() << std::endl;
        tempStack.push(s);
    }
    
    // Restore stack
    while (!tempStack.isEmpty()) {
        supplyStack.push(tempStack.pop());
    }
    
    file.close();
}
