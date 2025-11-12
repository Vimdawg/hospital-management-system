#ifndef MEDICALSUPPLY_HPP
#define MEDICALSUPPLY_HPP

#include <string>

class MedicalSupply {
private:
    std::string supplyType;
    int quantity;
    std::string batchID;

public:
    MedicalSupply();
    MedicalSupply(const std::string& type, int qty, const std::string& batch);
    
    std::string getSupplyType() const;
    int getQuantity() const;
    std::string getBatchID() const;
    
    void setSupplyType(const std::string& type);
    void setQuantity(int qty);
    void setBatchID(const std::string& batch);
    
    void display() const;
};

#endif // MEDICALSUPPLY_HPP

