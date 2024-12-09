#include "iostream"
#include "Appointment.h"
#include "User.h"
#include "Patient.h"
#include "Doctor.h"
#include "fstream"
#include "string"
#include "vector"
using namespace std;

//vector<Patient> patients = Patient::readFromFile(filename);
//vector<Doctor> doctors = Doctor::readFromFile(filename);

int validate_register_data_patient(string Health_provider,long id){
    if (id==0 || to_string(id).length()!=9)
        return 1;
    if (Health_provider!="Leumit" || Health_provider!="Macabi" || Health_provider!="Meuhedet" || Health_provider!="Clalit")
        return 2;
    return 0;
}
bool Register_patient(string Name,string Phone_number,string Health_provider,long id,long password){
    cout<<"=========================="<<endl;
    cout<<"System is ready to start registration process!"<<endl;

}


int main(){
    string name,phone_number,health_care;
    long id,pass;
    getline(cin,name);
    cout<<name;
    cin>>id;
    cout<<id;
}