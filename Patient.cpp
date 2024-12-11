//
// Created by ilanz on 09/12/2024.
//
#include "iostream"
#include "string"
#include "Patient.h"
using namespace std;

Patient::Patient(string Name, long Id, string Phone_num, long Password, string Healt_Provider): User(Name,Id,Phone_num,Password){
    this->Health_Provider=Healt_Provider;
}
char *Patient::get_type() const {
    return "Patient";
}

void Patient::saveToFile(const string &filename) const{
    ofstream file(filename,ios::app);
    if (file.is_open()){
        file<<Name<<endl;
        file<<id<<endl;
        file<<Phone_Number<<endl;
        file<<Password<<endl;
        file<<Health_Provider<<endl;
        file << "-------------------" << endl;
        file.close();
    }
    else{
        cout<<"Error: Could not open file for writing." << endl;
    }
}

vector<Patient> Patient::readFromFile(const string &filename) {
    ifstream file(filename);
    vector<Patient> patients;
    if (file.is_open()){
        string name, phone, healthProvider;
        long id, password;
        while (getline(file, name)) {
            if (name == "-------------------") {
                continue;
            }
            file >> id;
            file.ignore();
            getline(file, phone);
            file >> password;
            file.ignore();
            getline(file, healthProvider);
            patients.emplace_back(name, id, phone, password, healthProvider);
        }
        file.close();
    }
    else {
        cout << "Error: Could not open file for reading." << endl;
    }
    return patients;
}

string Patient::get_health_provider() const {
    return Health_Provider;
}

void Patient::set_phone(string phone_num) {
    this->Phone_Number=phone_num;
}

void Patient::set_healt_care(string health_care) {
    this->Health_Provider=health_care;
}





