#ifndef MEDICALSUPPLY_HPP
#define MEDICALSUPPLY_HPP

#include <string>

class MedicalSupply {
private:
    int itemID;
    std::string supplyType;
    int quantity;
    int batchNumber;

public:
    MedicalSupply();
    MedicalSupply(int id, const std::string& type, int qty, int batch);
    
    int getItemID() const;
    std::string getSupplyType() const;
    int getQuantity() const;
    int getBatchNumber() const;
    
    void setItemID(int id);
    void setSupplyType(const std::string& type);
    void setQuantity(int qty);
    void setBatchNumber(int batch);
    
    void display() const;
};

#endif // MEDICALSUPPLY_HPP

