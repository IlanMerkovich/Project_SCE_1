//
// Created by ilanz on 21/11/2024.
//

#ifndef PROJECT_APPOINTMENT_H
#define PROJECT_APPOINTMENT_H
#include "string"
#include <fstream>
using namespace std;

class Appointment{
private:
    string Date;
    string Time;
    string Doctor_Summary;
    bool is_over;
    bool is_booked;
    long Doctor_ID;
    long Patient_ID;
public:
    Appointment(const string &date,const string &time);
    void Add_Summary(const string &summary);
    void Book_Appointment(long Doctor_ID,long Patient_ID);
    void Print_Details();
    void Print_Summary();
    void Cancel_Appointment();
    bool check_if_booked();
    bool check_if_over();
    };

#endif //PROJECT_APPOINTMENT_H
