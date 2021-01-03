#include "student.h"
class Roster{
    private:
        const static int numStudents = 5;
        Student* classRosterArray[numStudents];
        int last = -1;
        
    public:
        void add(string studentID, string firstName, string lastName, 
            string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree);
        void parse(string studentData);
        void remove(string studentID);
        void printAll();
        void printAverageDaysInCourse(string studentID);
        void printInvalidEmails();
        void printByDegreeProgram(DegreeProgram degreeProgram);
        ~Roster();
};