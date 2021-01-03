#include <iomanip>
#include <iostream>
#include "degree.h"
using std::string;
using std::cout;

//Skeleton for student class with attributes and methods
class Student {
    public:
        const static int numberOfDays = 3;
    private:
        string studentID;
        string firstName;
        string lastName;
        string emailAddress;
        int age;
        int daysInCourse[numberOfDays];
        DegreeProgram degree;
    public:
        Student();
        Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[], DegreeProgram degree);
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
        void setEmail(string emailAddress);
        void setAge (int age);
        void setDays(int daysInCourse[]);
        void setDegree(DegreeProgram degree);

        void print();

};