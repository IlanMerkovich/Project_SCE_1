cmake_minimum_required(VERSION 3.27)
project(Project)

set(CMAKE_CXX_STANDARD 23)

add_executable(Project main.cpp
        Appointment.cpp
        Appointment.h
        User.cpp
        User.h
        Patient.cpp
        Patient.h
        Doctor.cpp
        Doctor.h
)
