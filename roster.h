#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"

class Roster {
public:
    int lastIndex = -1;//really helpful for multiple functions
    const static int numStudents = 5;//can't accidentally change it now! Public for easy access in definitions
    Student* classRosterArray[numStudents];//where all the students will go after parsing!

    void Parse(std::string row);
    void Add(std::string studentID, std::string firstName, std::string lastName,
        std::string emailAddress, int studentAge, int daysToCompleteCourse1, int daysToCompleteCourse2,
        int daysToCompleteCourse3, DegreeProgram degreeprogram);
    void Remove(std::string studentID);
    void PrintAll();
    void PrintAverageDaysInCourse(std::string studentID);
    void PrintInvalidEmails();
    void PrintByDegreeProgram(DegreeProgram degreeProgram);
    ~Roster();
};

#endif