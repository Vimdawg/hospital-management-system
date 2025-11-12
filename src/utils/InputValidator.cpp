#include "InputValidator.hpp"
#include <iostream>
#include <limits>

bool InputValidator::isValidInteger(const std::string& input) {
    // TODO: Implement integer validation
    return true;
}

bool InputValidator::isValidMenuChoice(int choice, int min, int max) {
    return (choice >= min && choice <= max);
}

void InputValidator::clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int InputValidator::getIntegerInput(const std::string& prompt) {
    int value;
    std::cout << prompt;
    while (!(std::cin >> value)) {
        std::cout << "Invalid input. Please enter a number: ";
        clearInputBuffer();
    }
    clearInputBuffer();
    return value;
}

std::string InputValidator::getStringInput(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::cin.ignore();
    std::getline(std::cin, input);
    return input;
}

