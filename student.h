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
        Degree degree;
    public:
        Student();
        Student(string studentID, string firstName, string lastName, string email, int age, int days[], Degree degree);
        ~Student();

        string getID();
        string getFirstName();
        string getLastName();
        string getEmail();
        int getAge();
        int* getDays();
        Degree getDegree();

        void setID(string studentID);
        void setFirstName(string firstName);
        void setLastName(string lastName);
        void setEmail(string email);
        void setAge (int age);
        void setDays(int days[]);
        void setDegree(Degree degree);

        void printHeader();

        void print();

};