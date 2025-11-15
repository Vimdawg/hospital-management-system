#ifndef AMBULANCE_HPP
#define AMBULANCE_HPP

#include <string>

class Ambulance {
private:
    std::string licensePlate;

public:
    Ambulance();
    Ambulance(const std::string& plate);
    
    std::string getLicensePlate() const;
    void setLicensePlate(const std::string& plate);
    
    void display() const;
};

#endif // AMBULANCE_HPP

