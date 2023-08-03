#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <iomanip>
#include "degree.h"


class Student {
public:
    const static int arraySizeDays = 3;//can't accidentally change it now!
private:
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int studentAge;
    int daysToCompleteCourse[arraySizeDays];
    DegreeProgram degreeProgram;
public:
    Student();
    Student(std::string studentID, std::string firstName, std::string lastName,
        std::string emailAddress, int studentAge, int daysToCompleteCourse[], DegreeProgram degreeProgram);
    // ~Student(); I believe this is taken care of by ~Roster()

    std::string GetID();
    std::string GetFirstName();
    std::string GetLastName();
    std::string GetEmail();
    int GetAge();
    int* GetDaysToComplete();
    DegreeProgram GetDegreeProgram();

    void SetID(std::string ID);
    void SetFirstName(std::string firstName);
    void SetLastName(std::string lastName);
    void SetEmail(std::string emailAddress);
    void SetAge(int studentAge);
    void SetDaysToComplete(int DaysToCompleteCourse[]);
    void SetDegreeProgram(DegreeProgram degreeProgram);

    void Print();
};

#endif