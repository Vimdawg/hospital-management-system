#ifndef EMERGENCYCASE_HPP
#define EMERGENCYCASE_HPP

#include <string>

class EmergencyCase {
private:
    std::string caseID;
    std::string caseType;
    int priorityLevel;

public:
    EmergencyCase();
    EmergencyCase(const std::string& id, const std::string& type, int priority);
    
    std::string getCaseID() const;
    std::string getCaseType() const;
    int getPriorityLevel() const;
    
    void setCaseID(const std::string& id);
    void setCaseType(const std::string& type);
    void setPriorityLevel(int priority);
    
    void display() const;
};

#endif // EMERGENCYCASE_HPP

