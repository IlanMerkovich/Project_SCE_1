//
// Created by ilanz on 09/12/2024.
//

#ifndef PROJECT_PATIENT_H
#define PROJECT_PATIENT_H
#include "User.h"
#include "string"
using namespace std;

class Patient: public User{
private:
    string Health_Provider;
public:
    Patient(string Name,long Id,string Phone_num,long Password,string Healt_Provider);
    char *get_type()const;
    void saveToFile(const string &filename) const;
    static vector<Patient> readFromFile(const string &filename);
    string get_health_provider()const;
    void set_phone(string phone_num);
    void set_healt_care(string health_care);

};


#endif //PROJECT_PATIENT_H
