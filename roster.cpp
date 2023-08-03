#include <iostream>
#include <string>
#include "roster.h"
//went searching for something to remove a couple decimal places from PrintAverageDaysInCourse() and this was
//really cool, so I added it! I could have just added std::fixed << std::setprecision(2) to the front of
//my output since there is only one, but this was more interesting/fun and a bit cleaner imo
#define FIXED_FLOAT(x) std::fixed <<std::setprecision(2)<<(x)

void Roster::Parse(std::string studentData) {
    int commaIndex = studentData.find(","); //data is split by commas, so use those to separate my variables
    std::string stuID = studentData.substr(0, commaIndex);

    int previousComma = commaIndex + 1; //+1 to avoid getting the previous comma over and over
    commaIndex = studentData.find(",", previousComma); //previousComma tells where to start looking, in this case index 3
    std::string fName = studentData.substr(previousComma, commaIndex - previousComma);
    //previousComma = 3, if fName is John commaIndex is 7, so commaIndex - previousComma gives len of str

    previousComma = commaIndex + 1;
    commaIndex = studentData.find(",", previousComma);
    std::string lName = studentData.substr(previousComma, commaIndex - previousComma);

    previousComma = commaIndex + 1;
    commaIndex = studentData.find(",", previousComma);
    std::string email = studentData.substr(previousComma, commaIndex - previousComma);

    previousComma = commaIndex + 1;
    commaIndex = studentData.find(",", previousComma);
    int stuAge = stoi(studentData.substr(previousComma, commaIndex - previousComma));

    previousComma = commaIndex + 1;
    commaIndex = studentData.find(",", previousComma);
    int days1 = stoi(studentData.substr(previousComma, commaIndex - previousComma));

    previousComma = commaIndex + 1;
    commaIndex = studentData.find(",", previousComma);
    int days2 = stoi(studentData.substr(previousComma, commaIndex - previousComma));

    previousComma = commaIndex + 1;
    commaIndex = studentData.find(",", previousComma);
    int days3 = stoi(studentData.substr(previousComma, commaIndex - previousComma));

    DegreeProgram stuProg = UNDECIDED; //Default just in case it didn't work, wanted to know where
    //Kind of a hack... each program ends in different letter. Could've also used functions to pull the last few chars, but this worked
    if (studentData.back() == 'E') stuProg = SOFTWARE;
    else if (studentData.back() == 'Y') stuProg = SECURITY;
    else if (studentData.back() == 'K') stuProg = NETWORK;

    Add(stuID, fName, lName, email, stuAge, days1, days2, days3, stuProg); //Add to classRosterArray
}

void Roster::Add(std::string studentID, std::string firstName, std::string lastName,
    std::string emailAddress, int studentAge, int daysToCompleteCourse1, int daysToCompleteCourse2,
    int daysToCompleteCourse3, DegreeProgram degreeprogram) {
    int daysArray[3] = { daysToCompleteCourse1,
daysToCompleteCourse2, daysToCompleteCourse3 };
    //Put all days into one array to help think about them as one object
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, studentAge, daysArray, degreeprogram);
    //lastIndex is helpful elsewhere, using ++ before starts it at index 0, then updates with each new student
}

void Roster::Remove(std::string studentID) {
    bool stuRemoved = false; //Has to prove itself true in order to work
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (classRosterArray[i]->GetID() == studentID) {
            stuRemoved = true;
            if (i < lastIndex) { //Moves student to the last index, then changes the last index to not include it.
                //Had to add sorting to PrintAll(), otherwise A5 was printing before A4 after this if statement
                Student* tmp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[lastIndex];
                classRosterArray[lastIndex] = tmp;
            }
            Roster::lastIndex = lastIndex - 1;
        }
    }
    if (stuRemoved == true) {
        PrintAll(); //If one was removed, print the rest
    }
    else { //Otherwise, 
        std::cout << "The student with the ID: " << studentID << " was not found.\n";
    }
    std::cout << std::endl;
}

void Roster::PrintAll() {//Bubble sort to fix issue with printing out of order after "removing" student
    for (int i = 0; i <= lastIndex; i++) {
        for (int j = 0; j < lastIndex - i; j++) {
            if (classRosterArray[j]->GetID() > classRosterArray[j + 1]->GetID()) {
                Student* temp = classRosterArray[j];
                classRosterArray[j] = classRosterArray[j + 1];
                classRosterArray[j + 1] = temp;
            }
        }
    } //Use each getter to print all info for each student
    for (int i = 0; i <= Roster::lastIndex; i++) {
        classRosterArray[i]->Print();//Frankly embarrassing how much easier this is
        
        //Previous method
        /*std::cout << classRosterArray[i]->GetID(); std::cout << '\t';
        std::cout << classRosterArray[i]->GetFirstName(); std::cout << '\t';
        std::cout << classRosterArray[i]->GetLastName(); std::cout << '\t';
        std::cout << classRosterArray[i]->GetEmail(); std::cout << '\t';
        std::cout << classRosterArray[i]->GetAge(); std::cout << "\t{";
        //Used commas in between the days instead of a tab to group them together
        std::cout << classRosterArray[i]->GetDaysToComplete()[0]; std::cout << ',';
        std::cout << classRosterArray[i]->GetDaysToComplete()[1]; std::cout << ',';
        std::cout << classRosterArray[i]->GetDaysToComplete()[2]; std::cout << "}\t";
        std::cout << degreePrograms[classRosterArray[i]->GetDegreeProgram()]; std::cout << std::endl;*/
    }
}

void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram) {
    //Pretty simple, if the degree program getter matches the one in the parameter it spits out that student's info
    std::cout << "\n";
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (Roster::classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
            classRosterArray[i]->Print();
        }
    }
    std::cout << std::endl;
}

void Roster::PrintAverageDaysInCourse(std::string studentID) {
    //loops through students looking for the matching studentID
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (classRosterArray[i]->GetID() == studentID) {
            std::cout << "Student ID: ";
            std::cout << classRosterArray[i]->GetID() << ", average days in a course is: ";
            std::cout << FIXED_FLOAT((classRosterArray[i]->GetDaysToComplete()[0] + classRosterArray[i]->GetDaysToComplete()[1]
                + classRosterArray[i]->GetDaysToComplete()[2]) / 3.0);
            //getting days to complete course, adding them, dividing by 3.0 because it's an average
            //dividing by just 3 would yield an integer which wouldn't be accurate
        }
    }
    std::cout << std::endl;
}

void Roster::PrintInvalidEmails() {
    std::cout << "Displaying invalid emails:\n\n";
    bool invalid = false;
    for (int i = 0; i <= Roster::lastIndex; i++) {
        std::string email = classRosterArray[i]->GetEmail();
        //might be an easier way to do this, but npos is shown if find goes through string without finding a match
        if (email.find(' ') != std::string::npos //if there is a space
            || (email.find('@') == std::string::npos && email.find('.') == std::string::npos) //or both @ and . are missing
            || (email.find('@') != std::string::npos && email.find('.') == std::string::npos) //or one or the other are missing
            || (email.find('@') == std::string::npos && email.find('.') != std::string::npos)) {
            invalid = true; //invalid pops true and the offending email is printed
            std::cout << email << " - is invalid" << "\n";
        }
    } //regex is better and more accurate to determine a correct email address format, but I don't know it very well atm
    std::cout << std::endl;
}

Roster::~Roster() {//afaik doesn't need to be manually called except in fringe cases
    for (int i = 0; i < numStudents; i++) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
