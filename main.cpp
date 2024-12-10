#include "iostream"
#include "Appointment.h"
#include "User.h"
#include "Patient.h"
#include "Doctor.h"
#include "fstream"
#include "string"
#include "vector"
#include "limits"
#define PATIENTSFILE "Patients.txt"
#define DOCTORSFILE "Doctors.txt"
using namespace std;

//vector<Patient> patients = Patient::readFromFile(filename);
//vector<Doctor> doctors = Doctor::readFromFile(filename);

bool validate_id(long id){
    string id_str= to_string(id);
    if (id_str.length()!=9){
        return false;
    }
    return true;
}
bool validate_phone_number(string phone_num){
    if (phone_num.length()!=10){
        return false;
    }
    return true;
}
Patient Register_patient(){
    string Name,Phone_number,Health_provider;
    long long id,password;
    cout<<endl;
    cout<<"*=====================[Patient Registration]=====================*"<<endl;
    cout<<"System is ready to start registration process!"<<endl;
    cout<<"Please Enter you full name:"<<endl;
    cin.ignore();
    getline(cin,Name);
    do {
        cout<<"Please Enter your id number(9-Digits number):"<<endl;
        cin >> id;
        if (!validate_id(id)) {
            cout << "Invalid ID. Please try again." << endl;
        }
    } while(!validate_id(id));
    cout<<"Please Enter your health care provider:"<<endl;
    cin>>Health_provider;
    do {
        cout << "Please Enter your phone number:" << endl;
        cin >> Phone_number;
        if (!validate_phone_number(Phone_number)) {
            cout << "Invalid Phone number,please try again" << endl;
        }
    } while (!validate_phone_number(Phone_number));
    cout<<"Enter a strong password for you account (password must consist of numbers only):"<<endl;
    cin>>password;
    cout<<"Registration is OK!"<<endl;
    cout<<"*===================[Patient Registration Completed!]===================*"<<endl;
    Patient returned_patient(Name,id,Phone_number,password,Health_provider);
    returned_patient.saveToFile(PATIENTSFILE);
    return returned_patient;
}

Doctor Register_doctor(){
    string Name,Phone_number,area,specialization;
    long long id,password,licence;
    cout<<endl;
    cout<<"*=====================[Doctors Registration]=====================*"<<endl;
    cout<<"System is ready to start registration process!"<<endl;
    cout<<"Please Enter you full name:"<<endl;
    cin.ignore();
    getline(cin,Name);
    do {
        cout<<"Please Enter your id number(9-Digits number):"<<endl;
        cin >> id;
        if (!validate_id(id)){
            cout << "Invalid ID. Please try again." << endl;
        }
    } while (!validate_id(id));
    cout<<"Please Enter your medical licence number:"<<endl;
    cin>>licence;
    cout<<"Please Enter your medical specialization:"<<endl;
    cin>>specialization;
    cout<<"Please Enter where you receive your patients (area):"<<endl;
    cin>>area;
    do {
        cout << "Please Enter your phone number:" << endl;
        cin >> Phone_number;
        if (!validate_phone_number(Phone_number)) {
            cout << "Invalid Phone number,please try again" << endl;
        }
    } while (!validate_phone_number(Phone_number));
    cout<<"Enter a strong password for you account (password must consist of numbers only):"<<endl;
    cin>>password;
    cout<<"Registration is OK!"<<endl;
    cout<<"*===================[Doctors Registration Completed!]===================*"<<endl;
    Doctor returned_doctor(Name,id,Phone_number,password,area,specialization,licence);
    returned_doctor.saveToFile(DOCTORSFILE);
    return returned_doctor;
}
void displayWelcomeScreen() {
    cout<<endl;
    cout << "==============================================" << endl;
    cout << "       Welcome to the Appointment System " << endl;
    cout << "==============================================" << endl;
    cout << "Are you a: " << endl;
    cout << "1. Doctor" << endl;
    cout << "2. Patient" << endl;
    cout << "==============================================" << endl;
    cout << "Please select your role (1-2): ";
}
void displayFirstScreen() {
    cout<<endl;
    cout << "==============================================" << endl;
    cout << "       Welcome to the Appointment System " << endl;
    cout << "==============================================" << endl;
    cout<<"What would you like to do?"<<endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. Exit" << endl;
    cout << "==============================================" << endl;
    cout << "Please select an option (1-3): ";
}

int main(){
    vector<Patient> patients = Patient::readFromFile(PATIENTSFILE);
    vector<Doctor> doctors = Doctor::readFromFile(DOCTORSFILE);
    int choice=0;
    displayWelcomeScreen();
    cin>>choice;
    switch (choice){
        int reg_log_choice;
        case 1:
            displayFirstScreen();
            cin>>reg_log_choice;
            if (reg_log_choice==2){
                doctors.push_back(Register_doctor());
            }
            break;
        case 2:
            displayFirstScreen();
            cin>>reg_log_choice;
            if (reg_log_choice==2){
                patients.push_back(Register_patient());
            }
            cout<<endl;
            break;
        case 3:
            cout<<endl;
            break;
        default:
            cout<<"Invalid choice,please try again!"<<endl;
    }
}
