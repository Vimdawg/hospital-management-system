#include "MenuSystem.hpp"
#include <iostream>

void MenuSystem::displayMainMenu() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "Hospital Patient Care Management System" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "1. Patient Admission Clerk" << std::endl;
    std::cout << "2. Medical Supply Manager" << std::endl;
    std::cout << "3. Emergency Department Officer" << std::endl;
    std::cout << "4. Ambulance Dispatcher" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Enter your choice: ";
}

