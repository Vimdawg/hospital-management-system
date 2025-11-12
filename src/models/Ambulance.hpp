#ifndef AMBULANCE_HPP
#define AMBULANCE_HPP

#include <string>

class Ambulance {
private:
    std::string ambulanceID;
    std::string driverName;
    std::string region;

public:
    Ambulance();
    Ambulance(const std::string& id, const std::string& driver, const std::string& reg);
    
    std::string getAmbulanceID() const;
    std::string getDriverName() const;
    std::string getRegion() const;
    
    void setAmbulanceID(const std::string& id);
    void setDriverName(const std::string& driver);
    void setRegion(const std::string& reg);
    
    void display() const;
};

#endif // AMBULANCE_HPP

