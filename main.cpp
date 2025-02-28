#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include "date.h"
#include "address.h"
#include "student.h"

void loadStudents(std::vector<Student*>& students);
void printStudents(std::vector<Student*>& students);
void showStudentNames(std::vector<Student*>& students);
void findStudent(std::vector<Student*>& students);
void delStudent(std::vector<Student*>& students);
std::string menu();


int main(){
    std::vector<Student*> students;
    loadStudents(students);
    bool keepGoing = true;

    while (keepGoing){
        std::string choice = menu();        
        if (choice == "0"){
            keepGoing = false;
        }
        else if (choice == "1"){
            printStudents(students);
        }
        else if (choice == "2"){
            showStudentNames(students);
        }
        else if (choice == "3") {
            findStudent(students);
        }
        else{
            std::cout << "Please choose an integer 0-3" << std::endl;
        }
    } 
    delStudent(students);
} 

void loadStudents(std::vector<Student*>& students){
    std::ifstream inFile;
    std::string studentString;

    inFile.open("students.csv");
    while (!inFile.eof()){
        getline(inFile, studentString);
        Student* student = new Student;
        student->init(studentString);
        students.push_back(student);
    }
    inFile.close();
}

void printStudents(std::vector<Student*>& students){
    for (int i = 0; i < (students.size() - 1); i++){
        students[i]->printStudent();
        std::cout << std::endl << "______________________________________" << std::endl;
        }
}

void showStudentNames(std::vector<Student*>& students){
     for (int i = 0; i < (students.size() - 1); i++){
         std::cout <<  students[i]->getLastFirst() << std::endl;

    }
}


void delStudent(std::vector<Student*>& students){
    for (int i = 0; i < (students.size() - 1); i++){
        delete students[i];
    }
}

void findStudent(std::vector<Student*>& students){
    std::string search;
    std::cout << "Last name of student: ";
    std::cin >> search;

    for (int i = 0; i < (students.size() - 1); i++) {
        std::stringstream ss;
        ss << students[i]->getLastFirst();
        std::string lastName;
        getline(ss, lastName, ' ');
        if (lastName.find(search) != std::string::npos){
            students[i]->printStudent();
            std::cout << std::endl << "____________________________" << std::endl;
        }
    }
}

std::string menu(){
    std::string choice;

    std::cout << "0) Quit " << std::endl << "1) Print all student data" << std::endl;
    std::cout << "2) Print all student names" << std::endl << "3) Find a student" << std::endl;
    std::cout << std::endl << "Please choose 0-3: ";
    std::cin >> choice;
    return choice;
}
    

    

