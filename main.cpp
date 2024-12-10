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

bool validate_id(long long id){
    if (id==0 || to_string(id).length()!=9)
        return false;
    return true;
}
Patient Register_patient(){
    string Name,Phone_number,Health_provider;
    long long id,password;
    cout<<endl;
    cout<<"=====================[Patient Registration]====================="<<endl;
    cout<<"System is ready to start registration process!"<<endl;
    cout<<"Please Enter you full name:"<<endl;
    getline(cin,Name);
    do {
        cout<<"Please Enter your id number(9-Digits number):"<<endl;
        cin >> id;
        if (!validate_id(id)) {
            cout << "Invalid ID. Please try again." << endl;
        }
    } while (!validate_id(id));
    cout<<"Please Enter your health care provider:"<<endl;
    cin>>Health_provider;
    cout<<"Please Enter your phone number:"<<endl;
    cin>>Phone_number;
    cout<<"Enter a strong password for you account (password must consist of numbers only):"<<endl;
    cin>>password;
    cout<<"Registration is OK!"<<endl;
    cout<<"===================[Patient Registration Completed!]==================="<<endl;
    Patient returned_patient(Name,id,Phone_number,password,Health_provider);
    returned_patient.saveToFile(PATIENTSFILE);
    return returned_patient;
}


int main(){

}
