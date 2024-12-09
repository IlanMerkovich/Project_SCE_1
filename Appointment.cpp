//
// Created by ilanz on 21/11/2024.
//
#include "iostream"
#include "Appointment.h"
using namespace std;


void Appointment::Add_Summary(const string &summary){
    Doctor_Summary=summary;
    is_over= true;
}

void Appointment::Book_Appointment(long Doctor_ID,long Patient_ID){
    if (is_booked){
        cout<<"This appointment is already booked"<<endl;
    }
    else{
        this->Doctor_ID=Doctor_ID;
        this->Patient_ID=Patient_ID;
        is_booked= true;
    }
}

void Appointment::Print_Details(){
    cout<<Date<<" , "<<Time<<"."<<endl;
}

void Appointment::Print_Summary(){
    cout<<Doctor_Summary;

}

bool Appointment::check_if_booked(){
    return is_booked;
}

bool Appointment::check_if_over() {
    return is_booked;
}

void Appointment::Cancel_Appointment(){
    if (is_booked)
        is_booked= false;
    else
        cout<<"This appointment is not booked."<<endl;
}
Appointment::Appointment(const string &date, const string &time) {
    this->Date=date;
    this->Time=time;
    is_booked=0;
    is_over=0;
}



