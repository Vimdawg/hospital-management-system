#ifndef INPUTVALIDATOR_HPP
#define INPUTVALIDATOR_HPP

#include <string>

class InputValidator {
public:
    static bool isValidInteger(const std::string& input);
    static bool isValidMenuChoice(int choice, int min, int max);
    static void clearInputBuffer();
    static int getIntegerInput(const std::string& prompt);
    static std::string getStringInput(const std::string& prompt);
};

#endif // INPUTVALIDATOR_HPP

