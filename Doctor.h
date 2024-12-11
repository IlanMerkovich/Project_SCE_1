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
    void saveToFile(const string &filename)const;
    static vector<Doctor> readFromFile(const string &filename);
    string get_receptionarea()const;
    string get_specialization()const;
    long get_licence()const;
    void set_phone(string new_number);
    void set_area(string new_area);
    void set_spec(string new_spec);
};


#endif //PROJECT_DOCTOR_H
