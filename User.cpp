//
// Created by ilanz on 21/11/2024.
//

#include "User.h"
#include "string"
using namespace std;

User::User(string Name, long Id, string Phone_num,long Password){
    this->Name=Name;
    this->id=Id;
    this->Phone_Number=Phone_num;
    this->Password=Password;
}

long long User::get_id() const {
    return id;
}

string User::get_name() const {
    return Name;
}

long User::get_password() const {
    return Password;
}

