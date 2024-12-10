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
#define APPOINTMENTSFILE "Appointments.txt"
using namespace std;

vector<Patient> Patients = Patient::readFromFile(PATIENTSFILE);
vector<Doctor> Doctors = Doctor::readFromFile(DOCTORSFILE);
vector<Appointment> Appointments = Appointment::readFromFile(APPOINTMENTSFILE);

bool validate_id(long id){
    string id_str= to_string(id);
    if (id_str.length()!=9){
        return false;
    }
    for (int i = 0; i < Patients.size(); ++i){
        if (Patients[i].get_id()==id){
            return false;
        }
    }
    for (int i = 0; i < Doctors.size(); ++i){
        if (Doctors[i].get_id()==id){
            return false;
        }
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
    cout << "==================================================" << endl;
    cout << "*                                                *" << endl;
    cout << "*             WELCOME TO HEALTH4U                *" << endl;
    cout << "*                                                *" << endl;
    cout << "**************************************************" << endl;
    cout << "*                                                *" << endl;
    cout << "*  Your health, your priority. Anytime, Anywhere *" << endl;
    cout << "*                                                *" << endl;
    cout << "**************************************************" << endl;
    cout << endl;
    cout<< endl;
    cout<<  "==================================================" <<endl;
    cout << "                 Are you a: " << endl;
    cout << "                 1. Doctor" << endl;
    cout << "                 2. Patient" << endl;
    cout << "==================================================" << endl;
    cout << "          [To turn off system select 3]          " << endl;
    cout << endl;
    cout << "Please select your role (1-2): ";
}
void displayFirstScreen() {
    cout<<endl;
    cout << "==============================================" << endl;
    cout << "       Welcome to the Appointment System " << endl;
    cout << "==============================================" << endl;
    cout<<  "         What would you like to do?"<<endl;
    cout << "              1. Login" << endl;
    cout << "              2. Register" << endl;
    cout << "              3. Exit to main menu" << endl;
    cout << "==============================================" << endl;
    cout << "Please select an option (1-3): ";
}
int Login_Doctor(){
    long id=0,password=0;
    cout << "===============================" << endl;
    cout << "Enter your ID (9-Digits):"<<endl;
    cin >>id;
    cout << "Enter your password:"<<endl;
    cin>> password;
    cout << "===============================" << endl;
    for (int i = 0; i < Doctors.size(); ++i){
        if (Doctors[i].get_id()==id && Doctors[i].get_password()==password){
            return i;
        }
    }
    return -1;
}
int Login_Patient(){
    long id=0,password=0;
    cout << "===============================" << endl;
    cout << "Enter your ID (9-Digits):"<<endl;
    cin >>id;
    cout << "Enter your password:"<<endl;
    cin>> password;
    cout << "===============================" << endl;
    for (int i = 0; i < Patients.size(); ++i){
        if (Patients[i].get_id()==id && Patients[i].get_password()==password){
            return i;
        }
    }
    return -1;
}
void displayDoctorMenu(){
    cout << "*************************************************" << endl;
    cout << "*                                               *" << endl;
    cout << "*              WELCOME, DOCTOR!                 *" << endl;
    cout << "*                                               *" << endl;
    cout << "*************************************************" << endl;
    cout << "*                                               *" << endl;
    cout << "*       Here are your available options:        *" << endl;
    cout << "*                                               *" << endl;
    cout << "*************************************************" << endl;
    cout << "1. View Profile" << endl;
    cout << "2. View Appointments" << endl;
    cout << "3. Mark Unavailable Dates" << endl;
    cout << "4. Update Past Appointments and Add Summary" << endl;
    cout << "5. Add Appointments" << endl;
    cout << "6. View Patient Ratings" << endl;
    cout << "7. Logout" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "Enter your choice (1-7): "<<endl;
    cout << "-------------------------------------------------" << endl;
}
void displayPatientMenu(){
    cout << "*************************************************" << endl;
    cout << "*                                               *" << endl;
    cout << "*              WELCOME, PATIENT!                *" << endl;
    cout << "*                                               *" << endl;
    cout << "*************************************************" << endl;
    cout << "*                                               *" << endl;
    cout << "*        Here are your available options:       *" << endl;
    cout << "*                                               *" << endl;
    cout << "*************************************************" << endl;
    cout << "1. View Profile" << endl;
    cout << "2. View My Scheduled Appointments" << endl;
    cout << "3. View All Available Appointments (with Filters)" << endl;
    cout << "4. Book an Appointment" << endl;
    cout << "5. Cancel an Appointment" << endl;
    cout << "6. View Past Appointment Summaries" << endl;
    cout << "7. Rate a Doctor for a Past Appointment" << endl;
    cout << "8. View First Aid Instructions" << endl;
    cout << "9. Logout" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "Enter your choice (1-9): "<<endl;
    cout << "-------------------------------------------------" << endl;
}
void createAppointmentsForDate(const string &date, long doctorID, const string &area){
    for (int hour = 9; hour <= 17; ++hour) {
        string time = (hour < 10 ? "0" : "") + to_string(hour) + ":00";
        Appointment newAppointment(date, time,area,doctorID);
        newAppointment.saveToFile(APPOINTMENTSFILE);
        Appointments.push_back(newAppointment);
    }
    cout << "Appointments created successfully for date " << date << " from 9:00 to 17:00." << endl;
}

int main()
{
    int choice=0;
    while(true)
    {
        displayWelcomeScreen();
        cin>>choice;
        while(true){
            int reg_log_choice=0;
            if (choice==1){ //doctor//
                displayFirstScreen();
                cin>>reg_log_choice;
                if (reg_log_choice==1){
                    int index=Login_Doctor();
                    if (index==-1) {
                        cout << "Could not log you in! Please check your id or password!" << endl;
                    }
                    else{
                        while(true){
                            displayDoctorMenu();
                        }
                    }

                }
                if (reg_log_choice==2){
                    Doctors.push_back(Register_doctor());
                    reg_log_choice=0;
                }
                if (reg_log_choice==3){
                    cout<<"====================="<<endl;
                    cout<<"Exiting to main menu!"<<endl;
                    cout<<"====================="<<endl;
                    break;
                }
            }
            if (choice==2){ //patient//
                displayFirstScreen();
                cin >> reg_log_choice;
                if (reg_log_choice == 1){
                    int index=Login_Patient();
                    if (index==-1){
                        cout << "Could not log you in! Please check your id or password!" << endl;
                    }
                    else{
                        while(true){

                        }
                    }
                }
                if (reg_log_choice == 2){
                    Patients.push_back(Register_patient());
                }
                if (reg_log_choice==3){ //exit to main menu//
                    cout<<"====================="<<endl;
                    cout<<"Exiting to main menu!"<<endl;
                    cout<<"====================="<<endl;
                    break;
                }
            }
            if (choice==3){
                exit(0);
            }
        }
    }
}
