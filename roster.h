#pragma once
#include "Student.h"
class Roster{
    private:
        int last = -1;
        const static int numStudents = 5;
        Student* studentArray[numStudents];
    public:
        void parse(string row);
        void add(string studentID, string firstName, string lastName, 
            string email, int age, int day1, int day2, int day3, DegreeProgram degree);
        void remove(string studentID);
        void printAll();
        void printAverageDaysInCourse(string studentID);
        void printInvalidEmails();
        void printByDegreeProgram(DegreeProgram degreeProgram);
};