#include "roster.h"

//Assign attribute values to the roster object
void Roster::add(string studentID, string firstName, string lastName, 
string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree){

    int days [3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    classRosterArray[++last] = new Student(studentID, firstName, lastName,
    emailAddress, age, days, degree);

}

//Removes student from array and prints out updated roster
void Roster::remove(string studentID){
    bool check = false;

    //Looks for student id that matches parameter value
    for(int x = 0; x <= Roster::last; x++){
        if(classRosterArray[x]->getID() == studentID){
            check = true;
            if(x<numStudents){
                Student* stud = classRosterArray[x];
                classRosterArray[x] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = stud;
            }
            //update size of roster 
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

//Manually separate each attribute from the long parameter string into 
//individual variables corresponding to student attributes
void Roster::parse(string studentData){
    
    int point = studentData.find(",");
    
    //Obtain student id from the studentData
    string studentID = studentData.substr(0, point);

    //Obtain first name from studentData
    int curr = point + 1;
    point = studentData.find(",",curr);
    string firstName = studentData.substr(curr, point - curr);

    //Obtain last name from studentData
    curr = point + 1;
    point = studentData.find(",", curr);
    string lastName = studentData.substr(curr, point - curr);

    //Obtain email address from studentData
    curr = point + 1;
    point = studentData.find(",", curr);
    string emailAddress = studentData.substr(curr, point - curr);

    //Obtain age from studentData
    curr = point + 1;
    point = studentData.find(",", curr);
    int age = stoi(studentData.substr(curr, point - curr));

    //Obtain days 1,2, and 3 from studentData
    curr = point + 1;
    point = studentData.find(",", curr);
    int daysInCourse1 = stoi(studentData.substr(curr, point - curr));
    curr = point + 1;
    point = studentData.find(",", curr);
    int daysInCourse2 = stoi(studentData.substr(curr, point - curr));
    curr = point + 1;
    point = studentData.find(",", curr);
    int daysInCourse3 = stoi(studentData.substr(curr, point - curr));

    //Obtain degree program from studentData
    curr = point + 1;
    point = studentData.find(",", curr);
    string program = studentData.substr(curr, point - curr);

    DegreeProgram degree = SOFTWARE;
    if (program.at(0) == 'S' && program.at(1) == 'E'){
        degree = SECURITY;
    }
    else if (program.at(0) == 'N'){
        degree = NETWORK;
    }

    //Assign these newly attained variables into roster object
    add(studentID,firstName,lastName,emailAddress,age,daysInCourse1,daysInCourse2,daysInCourse3,degree);

}


//Iteratively call print for each student in roster array to show student data
void Roster::printAll(){

    for (int x = 0; x <= Roster::last; x++){
        classRosterArray[x]->print();
    }
}

//Display the averages for the three days for each student
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


//Print each student data according to degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram){

    for(int x = 0; x <= Roster::last; x++){
        if(Roster::classRosterArray[x]->getDegree() == degreeProgram){
            classRosterArray[x]->print();
        }
    }
    cout << std::endl;
}

//Print all students' emails that have no space and contains @ and . 
void Roster::printInvalidEmails(){

    bool check = false;

    for(int x = 0; x <= Roster::last; x++){
        string email = classRosterArray[x]->getEmail();
        
        if(email.find('.') == string::npos || email.find('@') == string::npos || !(email.find(' ') == string::npos)){
            check = true;
            cout << classRosterArray[x]->getFirstName() << " " << classRosterArray[x]->getLastName() 
            <<  " has invalid email of " << email << std::endl;
        }
    }
    if (!check){
        cout << "No invalid emails found" << std::endl;
    }
}

//Destructor to reallocate array memory after finished with program
Roster::~Roster(){
    for(int x = 0; x < numStudents; x++){
        cout << "Destroying student " << x + 1 << std::endl;
        delete classRosterArray[x];
        classRosterArray[x] = nullptr;

    }
}

