//student.cpp
#include "date.h"
#include "address.h"
#include "student.h"
#include <sstream>
#include <iostream>

Student::Student(){
    studentString = "";
    firstName = "";
    lastName = "";
    dob = new Date();
    expectedGrad = new Date();
    address = new Address;
    creditHours = 0;
}

Student::~Student(){
    delete dob;
    delete expectedGrad;
    delete address;
}

void Student::init(std::string studentString){
    Student::studentString = studentString;
    std::stringstream ss;
    std::string street;
    std::string city;
    std::string state;
    std::string zip;
    std::string tdob;
    std::string texpectedGrad;
    std::string tcreditHours;

    
    ss.str(studentString);
    getline(ss, firstName, ',');
    getline(ss, lastName, ',');
    getline(ss, street, ',');
    getline(ss, city, ',');
    getline(ss, state, ',');
    getline(ss, zip, ',');
    getline(ss, tdob, ',');
    getline(ss, texpectedGrad, ',');
    getline(ss, tcreditHours);
    
    address->init(street, city, state, zip);
    dob->init(tdob);
    expectedGrad->init(texpectedGrad);

    ss.clear();
    ss.str("");

    ss.str(tcreditHours);
    ss >> creditHours;
}

void Student::printStudent(){
    std::cout << firstName << " " << lastName << std::endl;
    address->printAddress();
    std::cout << "DOB: ";
    dob->printDate();
    std::cout << "Grad: ";
    expectedGrad->printDate();
    std::cout << "Credits: " << creditHours;

}    
