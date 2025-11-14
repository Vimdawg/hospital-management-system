#ifndef MEDICALSUPPLYMANAGER_HPP
#define MEDICALSUPPLYMANAGER_HPP

#include "../data_structures/Stack.hpp"
#include <map>
#include <string>

class MedicalSupplyManager {
private:
    // Category-based stacks - one stack per supply type
    std::map<std::string, Stack> supplyStacks;
    
    // Helper functions
    void displayCategories() const;
    std::string selectCategory() const;
    bool categoryExists(const std::string& category) const;

public:
    MedicalSupplyManager();
    ~MedicalSupplyManager();
    
    void run();
    void addSupply();
    void useSupply();
    void viewSupplies();
    void viewTopSupply();
    void viewAllCategories();
};

#endif // MEDICALSUPPLYMANAGER_HPP

