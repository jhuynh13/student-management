#include "Roster.h"

void Roster::add(string studentID, string firstName, string lastName, 
string email, int age, int day1, int day2, int day3, DegreeProgram degree){
    int days [3] = {day1, day2, day3};
    studentArray[++last] = new Student(studentID, firstName, lastName,
    email, age, days, degree);
}

void Roster::printAll(){
    
    cout << "Output format: Student ID|First Name|Last name|Email|Age|Days|Degree\n";

    for (int i = 0; i <= Roster::last; i++){
        cout << studentArray[i]->getID();
        cout << '\t';
        cout << studentArray[i]->getFirstName();
        cout << '\t';
        cout << studentArray[i]->getLastName();
        cout << '\t';
        cout << studentArray[i]->getEmail();
        cout << '\t';
        cout << studentArray[i]->getAge();
        cout << '\t';
        cout << studentArray[i]->getDays()[0];
        cout << '\t';
        cout << studentArray[i]->getDays()[1];
        cout << '\t';
        cout << studentArray[i]->getDays()[2];
        cout << '\t';
        cout << degrees[studentArray[i]->getDegree()] << std::end1;

    }
}