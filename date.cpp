//date.cpp
#include <string>
#include <sstream>
#include <iostream>
#include "date.h"

Date::Date(){
    dateString = "0/0/0000";
    month = 0;
    day = 0;
    year = 0;
}

void Date::init(std::string dateString){
    Date::dateString = dateString;
    std::stringstream ss;
    std::string tMonth;
    std::string tDay;
    std::string tYear;

    ss.clear();
    ss.str(Date::dateString);

    getline(ss, tMonth, '/');
    getline(ss, tDay, '/');
    getline(ss, tYear);

    ss.clear();
    ss.str("");

    ss << tDay << " " << tMonth << " " << tYear;
    ss >> Date::day >> Date::month >> Date::year;
}

void Date::printDate(){
    std::string months[] = {"Null","January", "Februrary","March", 
                                  "April","May","June","July","August","September",
                                  "October","November","December"};
    std::cout << months[Date::month] << " ";
    std::cout << Date::day << ", " << Date::year << std::endl;
}
