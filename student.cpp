#include <iostream>
#include <string>
#include "student.h"

Student::Student() { //Default constructor just in case something doesn't work
    this->studentID = "NoID"; //Default, indicates ID was not set
    this->firstName = "No fName"; //Default, indicates first name was not set
    this->lastName = "No lName"; //Default, indicates last name was not set
    this->emailAddress = "No email"; //Default, indicates email address was not set
    this->studentAge = -1; //Default, indicates age was not set
    for (int i = 0; i < arraySizeDays; i++) this->daysToCompleteCourse[i] = 0; //Indicates days to complete course was not set
    this->degreeProgram = DegreeProgram::UNDECIDED; //Indicates degree program was not set
}

Student::Student(std::string studentID, std::string firstName, std::string lastName,
    std::string emailAddress, int studentAge, int daysToCompleteCourse[], DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->studentAge = studentAge;
    for (int i = 0; i < arraySizeDays; i++) this->daysToCompleteCourse[i] = daysToCompleteCourse[i];
    this->degreeProgram = degreeProgram;
}

std::string Student::GetID() { return studentID; }
std::string Student::GetFirstName() { return firstName; }
std::string Student::GetLastName() { return lastName; }
std::string Student::GetEmail() { return emailAddress; }
int Student::GetAge() { return studentAge; }
int* Student::GetDaysToComplete() { return daysToCompleteCourse; }
DegreeProgram Student::GetDegreeProgram() { return degreeProgram; }

void Student::SetID(std::string ID) { studentID = ID; }//So glad I made these
void Student::SetFirstName(std::string firstName) { firstName = firstName; }
void Student::SetLastName(std::string lastName) { lastName = lastName; }//many use
void Student::SetEmail(std::string emailAddress) { emailAddress = emailAddress; }
void Student::SetAge(int studentAge) { studentAge = studentAge; }//such helpful
void Student::SetDaysToComplete(int daysToCompleteCourse[]) {
    for (int i = 0; i < arraySizeDays; i++) daysToCompleteCourse[i] = daysToCompleteCourse[i];
}//now that I look at it, might be a good idea to change the names or add this-> to avoid confusion...
void Student::SetDegreeProgram(DegreeProgram degreeProgram) { degreeProgram = degreeProgram; }

void Student::Print() {//probably could have just used this instead of writing it all out again in PrintAll()...
    std::cout << GetID() << '\t';
    std::cout << GetFirstName() << '\t';
    std::cout << GetLastName() << '\t';
    std::cout << GetEmail() << '\t';
    std::cout << GetAge() << "\t{";
    std::cout << GetDaysToComplete()[0] << ',';
    std::cout << GetDaysToComplete()[1] << ',';
    std::cout << GetDaysToComplete()[2] << "}\t";
    std::cout << degreePrograms[GetDegreeProgram()] << '\n';
    //but that's okay, live and learn
}