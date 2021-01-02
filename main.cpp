#include "roster.h"

using namespace std;

int main(){

    //Create string array with roster data
    const string studentData[] = 
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
        "A5,Johnny,Huynh,jhuyn36@wgu.edu,25,30,31,34,SOFTWARE"
    };

    //Introduction info
    cout << "C867 Scripting and Programming - Applications" << std::endl;
    cout << "Language: C++" << std::endl;
    cout << "WGU ID: 001552351" << std::endl;
    cout << "Name: Johnny Huynh" << std::endl;

    //Create an instance of Roster
    Roster classRoster;
    const int numStudents = 5;
    
    /*
        Add each student into classRoster by first calling parse to retrieve
        each student attribute from the long string then calling add with these
        individual variables as parameter.
    */
    for (int x=0; x<numStudents; x++){

        classRoster.parse(studentData[x]);

    }

    //Display each student data by calling printAll 
    //which iteratively calls print for each student
    cout << "Student Roster:" << std::endl;
    classRoster.printAll();
    cout << std::endl;
    
    //Call printInvalidEmails to print out any invalid emails or error
    //message saying none were found
    cout << "Students with invalid Emails:" << std::endl;
    classRoster.printInvalidEmails();
    cout << std::endl;

    //Call printAverageDaysInCourse to print the average days for each student
    cout << "Average Days in courses for each student:" << std::endl;
    for(int x=0; x<numStudents; x++){
        int point = studentData[x].find(",");
        string studentID = studentData[x].substr(0, point);
        classRoster.printAverageDaysInCourse(studentID);
    }

    //Call printByDegreeProgram showing students for each degree
    for(int z = 0; z < 3; z++){
        cout << "Students by degree type:" << degrees[z] << endl;
        classRoster.printByDegreeProgram((DegreeProgram)z);
    }

    //Remove student with id A3
    cout << "Removing student with ID A3:" << std::endl;
    classRoster.remove("A3");
    cout << std::endl;

    //Show updated roster after deletion
    cout << "Displaying updated student roster:" << endl;
    classRoster.printAll();
    cout << std::endl;

    //Remove student with id A3 which shows error message
    cout << "Removing student with ID A3:" << std::endl;
    classRoster.remove("A3");
    cout << std::endl;

    //Wait for user input to end
    //getchar();
    system("pause");
    return 0;

}