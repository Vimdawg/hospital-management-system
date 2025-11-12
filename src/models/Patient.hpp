#ifndef PATIENT_HPP
#define PATIENT_HPP

#include <string>

class Patient {
private:
    int patientID;
    std::string patientName;
    std::string conditionType;

public:
    Patient();
    Patient(int id, const std::string& name, const std::string& condition);
    
    int getPatientID() const;
    std::string getPatientName() const;
    std::string getConditionType() const;
    
    void setPatientID(int id);
    void setPatientName(const std::string& name);
    void setConditionType(const std::string& condition);
    
    void display() const;
};

#endif // PATIENT_HPP

