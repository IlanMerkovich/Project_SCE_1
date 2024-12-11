//
// Created by ilanz on 09/12/2024.
//
#include "Doctor.h"

Doctor::Doctor(string Name, long Id, string Phone_num, long Password, string Reception_Area, string Specialization,
               long Licence_Number): User(Name,Id,Phone_num,Password){
    this->Licence_Number=Licence_Number;
    this->Reception_Area=Reception_Area;
    this->Specialization=Specialization;
}

char *Doctor::get_type()const{
    return "Doctor";
}

void Doctor::saveToFile(const string &filename) const{
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << Name << endl;
        file << id << endl;
        file << Phone_Number << endl;
        file << Password << endl;
        file << Reception_Area << endl;
        file << Specialization << endl;
        file << Licence_Number << endl;
        file << "-------------------" << endl;
        file.close();
    }
    else{
        cout<<"Error: Could not open file for writing." << endl;
    }
}

vector<Doctor> Doctor::readFromFile(const string &filename) {
    ifstream file(filename);
    vector<Doctor> doctors;
    if (file.is_open()) {
        string name, phone, receptionArea, specialization;
        long id, password, licence;
        while (getline(file, name)) {
            if (name == "-------------------") {
                continue;
            }
            file >> id;
            file.ignore();
            getline(file, phone);
            file >> password;
            file.ignore();
            getline(file, receptionArea);
            getline(file, specialization);
            file >> licence;
            file.ignore();
            doctors.push_back(Doctor(name, id, phone, password, receptionArea, specialization, licence));
        }
        file.close();
    } else {
        cout << "Error: Could not open file for reading." << endl;
    }
    return doctors;
}

string Doctor::get_receptionarea() const {
    return Reception_Area;
}

string Doctor::get_specialization() const {
    return Specialization;
}

long Doctor::get_licence() const {
    return Licence_Number;
}

void Doctor::set_phone(string new_number) {
    this->Phone_Number=new_number;
}

void Doctor::set_area(string new_area) {
    this->Reception_Area=new_area;
}

void Doctor::set_spec(string new_spec) {
    this->Specialization=new_spec;
}



