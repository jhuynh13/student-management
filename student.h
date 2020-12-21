#pragma once
#include <iostream>
#include "Degree.h"
using std::string;
using std::cout;

class Student {
    public:
        const static int numberOfDays = 3;
    private:
        string studentID;
        string firstName;
        string lastName;
        string email;
        int age;
        int days[numberOfDays];
        DegreeProgram degree;
    public:
        Student();
        Student(string studentID, string firstName, string lastName, string email, int age, int days[], DegreeProgram degree);
        ~Student();

        string getID();
        string getFirstName();
        string getLastName();
        string getEmail();
        int getAge();
        int* getDays();
        DegreeProgram getDegree();

        void setID(string studentID);
        void setFirstName(string firstName);
        void setLastName(string lastName);
        void setEmail(string email);
        void setAge (int age);
        void setDays(int days[]);
        void setDegree(DegreeProgram degree);

        void printHeader();

        void print();

};