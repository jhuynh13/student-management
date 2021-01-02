#include "Roster.h"

void Roster::add(string studentID, string firstName, string lastName, 
string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree){

    int days [3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    classRosterArray[++last] = new Student(studentID, firstName, lastName,
    emailAddress, age, days, degree);

}

void Roster::remove(string studentID){
    bool check = false;

    for(int x = 0; x <= Roster::last; x++){
        if(classRosterArray[x]->getID() == studentID){
            check = true;
            if(x<numStudents){
                Student* stud = classRosterArray[x];
                classRosterArray[x] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = stud;
            }
            Roster::last--;
        }
    }
    if(check){
        cout << studentID << "student id is removed." << std::endl << std::endl;
        this->printAll();
    }
    else{
        cout << studentID << " student id was not found." << std::endl << std::endl;
    }
}

void Roster::parse(string studentData){
    DegreeProgram degree = SOFTWARE;
    if (studentData.at(0) == 'S' && studentData.at(1) == 'E'){
        degree = SECURITY;
    }
    else if (studentData.at(0) == 'N'){
        degree = NETWORK;
    }

    int point = studentData.find(",");
    
    string studentID = studentData.substr(0, point);

    int curr = point + 1;
    point = studentData.find(",",curr);
    string firstName = studentData.substr(curr, point - curr);

    curr = point + 1;
    point = studentData.find(",", curr);
    string lastName = studentData.substr(curr, point - curr);

    curr = point + 1;
    point = studentData.find(",", curr);
    string emailAddress = studentData.substr(curr, point - curr);

    curr = point + 1;
    point = studentData.find(",", curr);
    int age = stoi(studentData.substr(curr, point - curr));

    curr = point + 1;
    point = studentData.find(",", curr);
    int daysInCourse1 = stoi(studentData.substr(curr, point - curr));
    curr = point + 1;
    point = studentData.find(",", curr);
    int daysInCourse2 = stoi(studentData.substr(curr, point - curr));
    curr = point + 1;
    point = studentData.find(",", curr);
    int daysInCourse3 = stoi(studentData.substr(curr, point - curr));

    add(studentID,firstName,lastName,emailAddress,age,daysInCourse1,daysInCourse2,daysInCourse3,degree);

}

void Roster::printAll(){
    
    cout << "Output format: Student ID|First Name|Last name|Email|Age|Days|Degree\n";

    for (int x = 0; x <= Roster::last; x++){
        classRosterArray[x]->print();
        /*
        cout << classRosterArray[x]->getID();
        cout << '\t';
        cout << classRosterArray[x]->getFirstName();
        cout << '\t';
        cout << classRosterArray[x]->getLastName();
        cout << '\t';
        cout << classRosterArray[x]->getEmail();
        cout << '\t';
        cout << classRosterArray[x]->getAge();
        cout << '\t';
        cout << classRosterArray[x]->getDays()[0];
        cout << '\t';
        cout << classRosterArray[x]->getDays()[1];
        cout << '\t';
        cout << classRosterArray[x]->getDays()[2];
        cout << '\t';
        cout << degrees[classRosterArray[x]->getDegree()] << std::endl;
        */
    }
}

void Roster::printAverageDaysInCourse(string studentID){
    for (int x=0; x<= Roster::last; x++){
        if(classRosterArray[x]->getID()==studentID){
            cout << studentID << ":";
            cout << (classRosterArray[x]->getDays()[0] + 
            classRosterArray[x]->getDays()[1] + 
            classRosterArray[x]->getDays()[2])/3.0 << std::endl;
        }
    }
    cout << std::endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram){
    cout << "Output format: Student ID|First Name|Last name|Email|Age|Days|Degree\n";
    for(int x = 0; x <= Roster::last; x++){
        if(Roster::classRosterArray[x]->getDegree() == degreeProgram){
            classRosterArray[x]->print();
        }
    }
    cout << std::endl;
}

void Roster::printInvalidEmails(){

    bool check = false;

    for(int x = 0; x <= Roster::last; x++){
        string email = classRosterArray[x]->getEmail();
        
        if(email.find(' ') == string::npos && email.find('.') > 0 && email.find('@') > 0){
            check = true;
            cout << classRosterArray[x]->getFirstName() << " " << classRosterArray[x]->getLastName() 
            <<  "has invalid email of " << email << std::endl;
        }
    }
    if (!check){
        cout << "No invalid emails found" << std::endl;
    }
}

Roster::~Roster(){
    for(int x = 0; x < numStudents; x++){
        cout << "Destroying student " << x + 1 << std::endl;
        delete classRosterArray[x];
        classRosterArray[x] = nullptr;

    }
}

