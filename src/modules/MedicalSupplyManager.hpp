#ifndef MEDICALSUPPLYMANAGER_HPP
#define MEDICALSUPPLYMANAGER_HPP

#include "../data_structures/Stack.hpp"

class MedicalSupplyManager {
private:
    Stack supplyStack;

public:
    MedicalSupplyManager();
    ~MedicalSupplyManager();
    
    void run();
    void addSupply();
    void useSupply();
    void viewSupplies();
    void viewTopSupply();
};

#endif // MEDICALSUPPLYMANAGER_HPP

