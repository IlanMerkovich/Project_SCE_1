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
    cout << "**************************************************" << endl;
    cout << "*                                                *" << endl;
    cout << "*             WELCOME TO HEALTH4U                *" << endl;
    cout << "*                                                *" << endl;
    cout << "**************************************************" << endl;
    cout << "*                                                *" << endl;
    cout << "*  Your health, your priority. Anytime, Anywhere *" << endl;
    cout << "*                                                *" << endl;
    cout << "**************************************************" << endl;
    cout << endl;
    cout << endl;
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
    cout << "7. Logout and save your actions" << endl;
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
    cout << "9. Logout and save your actions" << endl;
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
void display_doctor_choice1(){
    cout << "*************************************************" << endl;
    cout << "*                 Doctor Profile                *" << endl;
    cout << "*************************************************" << endl;
    cout << "*                                               *" <<endl;
    cout << "*             1.View My Profile                 *" <<endl;
    cout << "*             2.Edit my profile                 *" <<endl;
    cout << "*                                               *" <<endl;
    cout << "*************************************************" <<endl;
}
void display_doctors_details(int index){
    cout << "*************************************************" <<endl;
    cout << "*                Doctors Details:               *" <<endl;
    cout << "*************************************************" <<endl;
    cout << "*Name: "<<Doctors[index].get_name()<<endl;
    cout << "*Phone number: "<<Doctors[index].get_phone()<<endl;
    cout << "*Specialization: "<<Doctors[index].get_specialization()<<endl;
    cout << "*Area of reception: "<<Doctors[index].get_receptionarea()<<endl;
    cout << "*Licence number: "<<Doctors[index].get_licence()<<endl;
    cout << "*ID: "<<Doctors[index].get_id()<<endl;
    cout << "*************************************************" <<endl;
}
void display_doctors_changes() {
    cout << "*************************************************" << endl;
    cout << "*                Edit my profile                *" << endl;
    cout << "*************************************************" << endl;
    cout << "*         What would you like to change?:       *" << endl;
    cout << "*            1. Phone number                    *" << endl;
    cout << "*            2. Specialization                  *" << endl;
    cout << "*            3. Area of Reception               *" << endl;
    cout << "*************************************************" << endl;
    cout<<endl;
}
void display_doctors_scheduald_app(int index){
    cout<<"***************************************************" <<endl;
    cout<<" Printing all appointments for "<<Doctors[index].get_name()<<""<<endl;
    for (int i = 0; i < Appointments.size(); ++i){
        if (Appointments[i].get_doc_id() == Doctors[index].get_id() && Appointments[i].check_if_booked()){
            Appointments[i].Print_Details();
        }
    }
}
int calculate_doc_app_num(int index){
    int counter=0;
    for (int i = 0; i <Appointments.size(); ++i){
        if (Appointments[i].check_if_booked() && Appointments[i].get_doc_id()==Doctors[index].get_id()){
            counter++;
        }
    }
    return counter;
}
float calculate_doc_rating(int index){
    int counter=0;
    float rating=0;
    for (int i = 0; i < Appointments.size(); ++i) {
        if (Appointments[i].get_doc_id()==Doctors[index].get_id() && Appointments[i].check_if_over()){
            counter++;
            rating+=Appointments[i].get_rating();
        }
    }
    return rating/counter;
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
            //doctor//
            if (choice==1){
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
                            int menu_choice=0;
                            cin>>menu_choice;
                            if (menu_choice==1)
                            {
                                display_doctor_choice1();
                                int profile_choice;
                                cin >> profile_choice;
                                if (profile_choice == 1) {
                                    display_doctors_details(index);
                                }
                                if (profile_choice == 2) {
                                    display_doctors_changes();
                                    int edit_choice = 0;
                                    cin >> edit_choice;
                                    if (edit_choice == 1) {
                                        cout << "Enter your new phone number:";
                                        string new_number;
                                        cin >> new_number;
                                        if (validate_phone_number(new_number)) {
                                            Doctors[index].set_phone(new_number);
                                            cout << "** Phone number changed successfully **" << endl;
                                        } else
                                            cout << "Invalid Phone number. Try again!" << endl;
                                    }
                                    if (edit_choice == 2) {
                                        cout << "Enter you new Specialization: " << endl;
                                        string new_spec;
                                        cin >> new_spec;
                                        Doctors[index].set_spec(new_spec);
                                    }
                                    if (edit_choice == 3) {
                                        cout << "Enter your new area of reception: " << endl;
                                        string new_area;
                                        cin >> new_area;
                                        Doctors[index].set_area(new_area);
                                    }
                                }
                            }
                            if (menu_choice==2){
                                display_doctors_scheduald_app(index);
                                cout<<endl;
                            }
                            if (menu_choice==3){
                                cout<<"Please select a date you will be unavailable:"<<endl;
                                string unavil_date;
                                cin>>unavil_date;
                                for (int i = 0; i < Appointments.size(); ++i){
                                    if (Appointments[i].get_date() == unavil_date && Appointments[i].get_doc_id() == Doctors[index].get_id()) {
                                        Appointments[i].Make_Appointment_Unavail();
                                    }
                                }
                            }
                            if (menu_choice==4){
                                if (calculate_doc_app_num(index)==0){
                                    cout<<"You have no appointments yet"<<endl;
                                }
                                else{
                                    display_doctors_scheduald_app(index);
                                    cout<<endl;
                                    string update_date,update_time,app_summary;
                                    cout<<"Enter appointment date and time you want to finsih and add summary:"<<endl;
                                    cout<<"Enter date:"<<endl;
                                    cin>>update_date;
                                    cout<<"Enter time:"<<endl;
                                    cin>>update_time;
                                    for (int i = 0; i < Appointments.size(); ++i) {
                                        if (Appointments[i].get_time()==update_time && Appointments[i].get_date()==update_date && Appointments[i].get_doc_id()==Doctors[index].get_id()){
                                            cout<<"Appointment found, Please enter your summary:"<<endl;
                                            cin.ignore();
                                            getline(cin,app_summary);
                                            Appointments[i].Add_Summary(app_summary);
                                            cout<<"Appointment summary updated successfully"<<endl;
                                        }
                                    }
                                }
                            }
                            if (menu_choice==5){
                                string date_gen;
                                cout<<"Please enter the date you will work to generate appointments:"<<endl;
                                cin>>date_gen;
                                cout<<"You chose to generate appointments on the "<<date_gen<<endl;
                                createAppointmentsForDate(date_gen,Doctors[index].get_id(),Doctors[index].get_receptionarea());
                                cout<<endl;
                            }
                            if (menu_choice==6){
                                cout<<"Displaying rating for: "<<Doctors[index].get_name()<<endl;
                                cout<<"Your rating is: "<<calculate_doc_rating(index)<<" start!"<<endl;

                            }
                            if (menu_choice==7){
                                cout<<"Are you sure you want to exit? 1-yes,0-no"<<endl;
                                int exit_choice;
                                cin>>exit_choice;
                                if (exit_choice==1){
                                    break;
                                }
                                else
                                    continue;
                            }
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
            //patient//
            if (choice==2){
                displayFirstScreen();
                cin >> reg_log_choice;
                if (reg_log_choice == 1){
                    int index=Login_Patient();
                    if (index==-1){
                        cout << "Could not log you in! Please check your id or password!" << endl;
                    }
                    else{
                        while(true){
                            displayPatientMenu();
                            int menu_choice=0;
                            cin>>menu_choice;
                        }
                    }
                }
                if (reg_log_choice == 2){
                    Patients.push_back(Register_patient());
                }
                //exit to main menu//
                if (reg_log_choice==3){
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
