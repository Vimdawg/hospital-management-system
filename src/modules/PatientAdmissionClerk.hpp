#ifndef PATIENTADMISSIONCLERK_HPP
#define PATIENTADMISSIONCLERK_HPP

#include "../data_structures/Queue.hpp"

class PatientAdmissionClerk {
private:
    Queue patientQueue;
    int nextPatientID;

public:
    PatientAdmissionClerk();
    ~PatientAdmissionClerk();
    
    void run();
    void admitPatient();
    void dischargePatient();
    void viewPatientQueue();
};

#endif // PATIENTADMISSIONCLERK_HPP

