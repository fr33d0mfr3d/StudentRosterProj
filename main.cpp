#include <iostream>
#include <string>
#include "roster.h"
//Read that best practice is to avoid "using namespace" so I decided to just type std:: for practice
//Also used \n unless I wanted it to print, doesn't matter here but I believe it's good for speed.
//used endl at the end of each function so that whatever worked would flush to the output

//When I was writing the functions I was looking at the potential desired output and did some formatting inside
//the functions. In the future I'll just leave that to the main() function, it made it a bit messy trying to figure out
//where I'd put newline characters to get the spacing to look right

int main() {
    const std::string studentData[] =
    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Ammon,Bingham,abing44@wgu.edu,25,5,18,20,SOFTWARE" };
    const int numStudents = 5;
    Roster classRoster;


    std::cout << "C867-Scripting & Programming: Applications\n";
    std::cout << "Language: C++\n";
    std::cout << "Student ID: 010769386\n";
    std::cout << "Name: Ammon Bingham\n";

    std::cout << "\nDisplaying all students:" << std::endl;
    for (int i = 0; i < numStudents; i++) {
        classRoster.Parse(studentData[i]);//Parses through studentData by comma and adds each as object to classRosterArray
    }
    classRoster.PrintAll();
    std::cout << std::endl;

    classRoster.PrintInvalidEmails();
    std::cout << std::endl;

    for (int i = 0; i <= classRoster.lastIndex; i++) {//loops through each student object, then prints average days in a course for each studentID
        Student* student = classRoster.classRosterArray[i];
        classRoster.PrintAverageDaysInCourse(student->GetID());
    }

    std::cout << "\nShowing students in degree program: SOFTWARE";
    classRoster.PrintByDegreeProgram(SOFTWARE);
    std::cout << std::endl;

    std::cout << "Removing A3:\n"; //PrintAll() is called inside Remove() if a student is removed
    classRoster.Remove("A3");

    std::cout << "Removing A3 again:\n";
    classRoster.Remove("A3");

    std::cout << "Osi.";

    return 0;
}