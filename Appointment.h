//
// Created by ilanz on 21/11/2024.
//

#ifndef PROJECT_APPOINTMENT_H
#define PROJECT_APPOINTMENT_H
#include "string"
#include <fstream>
#include "vector"

using namespace std;

class Appointment{
private:
    string Date;
    string Time;
    string Doctor_Summary;
    bool is_over;
    bool is_booked;
    bool is_canceled;
    long Doctor_ID;
    long Patient_ID;
    float rating;
    string Area;
    string specialization;
public:
    Appointment(const string date,const string time,const string Area,long Doc_id,string specialization);
    void saveToFile(const string &filename) const;
    static vector<Appointment> readFromFile(const string &filename);
    void Add_Summary(string summary);
    void Book_Appointment(long Patient_ID);
    void Print_Details();
    void Print_Summary();
    void Cancel_Appointment();
    void Make_Appointment_Unavail();
    bool check_if_booked();
    bool check_if_over();
    string get_date()const;
    string get_time()const;
    string get_area()const;
    long get_doc_id()const;
    long get_pat_id()const;
    void set_doc_id(long doc_id);
    void set_pat_id(long pat_id);
    int get_rating()const;
    string get_specialization()const;
    bool check_if_unvail()const;
    void Rate_doc(int rate);
    };

#endif //PROJECT_APPOINTMENT_H
