#include "MedicalSupplyManager.hpp"
#include <iostream>
#include <limits>
#include <string>
#include <map>
#include <iomanip>

MedicalSupplyManager::MedicalSupplyManager() : nextItemID(1), nextBatchNumber(1) {}

MedicalSupplyManager::~MedicalSupplyManager() {}

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
