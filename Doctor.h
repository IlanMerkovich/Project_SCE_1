//
// Created by ilanz on 09/12/2024.
//

#ifndef PROJECT_DOCTOR_H
#define PROJECT_DOCTOR_H
#include "User.h"
#include "string"
#include "iostream"
#include "fstream"
using namespace std;

class Doctor: public User{
private:
    string Reception_Area;
    string Specialization;
    long Licence_Number;
public:
    Doctor(string Name,long Id,string Phone_num,long Password,string Reception_Area,string Specialization,long Licence_Number);
    char *get_type()const;
    void saveToFile(const string &filename) const;
    static vector<Doctor> readFromFile(const string &filename);
};


#endif //PROJECT_DOCTOR_H
