#include "student.h"

//Student constructor with parameter values
Student::Student(string studentID,string firstName,string lastName,string emailAddress1,int age, int daysInCourse[],DegreeProgram degree){

    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress1;
    this->age = age;
    this->daysInCourse[0] = daysInCourse[0];
    this->daysInCourse[1] = daysInCourse[1];
    this->daysInCourse[2] = daysInCourse[2];
    this->degree = degree;

}

Student::~Student(){}

string Student::getID(){
    return this->studentID;
}
string Student::getFirstName(){
    return this->firstName;
}
string Student::getLastName(){
    return this->lastName;
}
string Student::getEmail(){
    return this->emailAddress;
}
int Student::getAge(){
    return this->age;
}
int* Student::getDays(){
    return this->daysInCourse;
}
DegreeProgram Student::getDegree(){
    return this->degree;
}


void Student::setID(string studentID){
    this->studentID = studentID;
}
void Student::setFirstName(string firstName){
    this->firstName = firstName;
}
void Student::setLastName(string lastName){
    this->lastName = lastName;
}
void Student::setEmail (string emailAddress){
    this->emailAddress = emailAddress;
}
void Student::setAge (int age){
    this->age = age;
}
void Student::setDays(int days[]){
    this->daysInCourse[0] = daysInCourse[0];
    this->daysInCourse[1] = daysInCourse[1];
    this->daysInCourse[2] = daysInCourse[2];
}
void Student::setDegree(DegreeProgram degree){
    this->degree = degree;
}

//Print out every attribute for this student object
void Student::print(){
    cout << this->getID() << '\t';
    cout << this->getFirstName() << '\t';
    cout << this->getLastName() << '\t';
    cout << this->getEmail() << '\t';
    cout << this->getAge() << '\t';
    cout << this->getDays()[0] << ',';
    cout << this->getDays()[1] << ',';
    cout << this->getDays()[2] << '\t';
    cout << degrees[this->getDegree()] << '\n';
}