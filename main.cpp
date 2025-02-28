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
  //printStudents(students);
  showStudentNames(students);
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
    

