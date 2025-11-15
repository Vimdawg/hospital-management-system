#ifndef MEDICALSUPPLYMANAGER_HPP
#define MEDICALSUPPLYMANAGER_HPP

#include "../data_structures/Stack.hpp"
#include <string>

class MedicalSupplyManager {
private:
    Stack supplyStack;
    int nextItemID;
    int nextBatchNumber;

public:
    MedicalSupplyManager();
    ~MedicalSupplyManager();
    
    void run();
    void addSupplyStock();
    void useLastAddedSupply();
    void viewCurrentSupply();
};

#endif // MEDICALSUPPLYMANAGER_HPP

