#include "MedicalSupplyManager.hpp"
#include <iostream>
#include <limits>
#include <string>

MedicalSupplyManager::MedicalSupplyManager() {
    // Initialize stacks for common supply categories
    supplyStacks["Mask"] = Stack();
    supplyStacks["Glove"] = Stack();
    supplyStacks["Syringe"] = Stack();
    supplyStacks["Bandage"] = Stack();
    supplyStacks["Medicine"] = Stack();
    supplyStacks["Scissors"] = Stack();
}

MedicalSupplyManager::~MedicalSupplyManager() {}

void MedicalSupplyManager::run() {
    int choice;
    do {
        std::cout << "\n========================================" << std::endl;
        std::cout << "      MEDICAL SUPPLY MANAGER MODULE" << std::endl;
        std::cout << "      (Category-Based LIFO Stacks)" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "1. Add Supply to Category" << std::endl;
        std::cout << "2. Use Supply from Category" << std::endl;
        std::cout << "3. View Supplies in Category" << std::endl;
        std::cout << "4. View Top Supply in Category" << std::endl;
        std::cout << "5. View All Categories" << std::endl;
        std::cout << "6. Back to Main Menu" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "Enter your choice (1-6): ";
        
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
                addSupply();
                break;
            case 2:
                useSupply();
                break;
            case 3:
                viewSupplies();
                break;
            case 4:
                viewTopSupply();
                break;
            case 5:
                viewAllCategories();
                break;
            case 6:
                std::cout << "\n[INFO] Returning to main menu..." << std::endl;
                break;
            default:
                std::cout << "\n[ERROR] Invalid choice. Please select 1-6." << std::endl;
        }
    } while(choice != 6);
}

// Helper function to display available categories
void MedicalSupplyManager::displayCategories() const {
    std::cout << "\nAvailable Supply Categories:" << std::endl;
    std::cout << "========================================" << std::endl;
    int index = 1;
    for (std::map<std::string, Stack>::const_iterator it = supplyStacks.begin(); 
         it != supplyStacks.end(); ++it) {
        std::cout << index++ << ". " << it->first 
                  << " (Items: " << it->second.getSize() << ")" << std::endl;
    }
    std::cout << "========================================" << std::endl;
}

// Helper function to select a category
std::string MedicalSupplyManager::selectCategory() const {
    displayCategories();
    
    int categoryChoice;
    std::cout << "\nSelect category number: ";
    
    while (!(std::cin >> categoryChoice) || categoryChoice < 1 || categoryChoice > (int)supplyStacks.size()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "[ERROR] Invalid choice. Please select a valid category: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    // Get category name by index
    std::map<std::string, Stack>::const_iterator it = supplyStacks.begin();
    std::advance(it, categoryChoice - 1);
    return it->first;
}

// Helper function to check if category exists
bool MedicalSupplyManager::categoryExists(const std::string& category) const {
    return supplyStacks.find(category) != supplyStacks.end();
}

void MedicalSupplyManager::addSupply() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "      ADD NEW SUPPLY TO CATEGORY" << std::endl;
    std::cout << "========================================" << std::endl;
    
    // Select category
    std::string category = selectCategory();
    
    std::cout << "\nAdding supply to: " << category << " stack" << std::endl;
    std::cout << "========================================" << std::endl;
    
    int quantity;
    std::string batchID;
    
    // Get Quantity
    std::cout << "Enter Quantity: ";
    while (!(std::cin >> quantity) || quantity <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "[ERROR] Invalid input. Please enter a positive number: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    // Get Batch ID
    std::cout << "Enter Batch ID: ";
    std::getline(std::cin, batchID);
    
    // Create MedicalSupply object and push to specific category stack
    MedicalSupply newSupply(category, quantity, batchID);
    supplyStacks[category].push(newSupply);
    
    std::cout << "\nCurrent " << category << " stack size: " 
              << supplyStacks[category].getSize() << " batches." << std::endl;
    std::cout << "[NOTE] This batch will be used FIRST (LIFO - Last In, First Out)" << std::endl;
}

void MedicalSupplyManager::useSupply() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "      USE SUPPLY FROM CATEGORY (POP)" << std::endl;
    std::cout << "========================================" << std::endl;
    
    // Select category
    std::string category = selectCategory();
    
    if (supplyStacks[category].isEmpty()) {
        std::cout << "\n[INFO] No " << category << " supplies in stack to use." << std::endl;
        return;
    }
    
    // Pop supply from specific category stack
    MedicalSupply usedSupply = supplyStacks[category].pop();
    
    // Display used supply info
    if (usedSupply.getQuantity() != 0) {  // Valid supply
        std::cout << "\n[SUCCESS] " << category << " supply used successfully!" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "Supply Type: " << usedSupply.getSupplyType() << std::endl;
        std::cout << "Quantity: " << usedSupply.getQuantity() << std::endl;
        std::cout << "Batch ID: " << usedSupply.getBatchID() << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "Remaining " << category << " batches in stack: " 
                  << supplyStacks[category].getSize() << std::endl;
        std::cout << "[NOTE] Most recent batch used first (LIFO)" << std::endl;
    }
}

void MedicalSupplyManager::viewSupplies() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "    VIEW ALL SUPPLIES IN CATEGORY" << std::endl;
    std::cout << "========================================" << std::endl;
    
    // Select category
    std::string category = selectCategory();
    
    std::cout << "\nViewing " << category << " stack:" << std::endl;
    supplyStacks[category].display();
}

void MedicalSupplyManager::viewTopSupply() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "      TOP SUPPLY IN CATEGORY (PEEK)" << std::endl;
    std::cout << "========================================" << std::endl;
    
    // Select category
    std::string category = selectCategory();
    
    if (supplyStacks[category].isEmpty()) {
        std::cout << "\n[INFO] No " << category << " supplies in stack." << std::endl;
        return;
    }
    
    MedicalSupply topSupply = supplyStacks[category].peek();
    std::cout << "\nTop " << category << " supply (will be used next):" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Supply Type: " << topSupply.getSupplyType() << std::endl;
    std::cout << "Quantity: " << topSupply.getQuantity() << std::endl;
    std::cout << "Batch ID: " << topSupply.getBatchID() << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "[NOTE] This is the most recently added batch (LIFO)" << std::endl;
}

void MedicalSupplyManager::viewAllCategories() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "     ALL SUPPLY CATEGORIES OVERVIEW" << std::endl;
    std::cout << "========================================" << std::endl;
    
    bool hasSupplies = false;
    
    for (std::map<std::string, Stack>::const_iterator it = supplyStacks.begin(); 
         it != supplyStacks.end(); ++it) {
        
        std::cout << "\n" << it->first << " Stack:" << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        
        if (it->second.isEmpty()) {
            std::cout << "  [Empty - No batches in stack]" << std::endl;
        } else {
            std::cout << "  Total Batches: " << it->second.getSize() << std::endl;
            MedicalSupply topItem = it->second.peek();
            std::cout << "  Top Batch (LIFO): " << topItem.getBatchID() 
                      << " (Qty: " << topItem.getQuantity() << ")" << std::endl;
            hasSupplies = true;
        }
    }
    
    std::cout << "\n========================================" << std::endl;
    if (!hasSupplies) {
        std::cout << "[INFO] All categories are empty" << std::endl;
    } else {
        std::cout << "[NOTE] Each category uses LIFO (Last In, First Out)" << std::endl;
        std::cout << "[TIP] Most recent batch in each category used first" << std::endl;
    }
    std::cout << "========================================" << std::endl;
}

