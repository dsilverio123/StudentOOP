#pragma once
#include "degree.h"
#include "student.h"
#include <iostream>
#include <string>

// defining the private data variables

class Roster {
private:
    // Array of pointers classRosterArray
    Student* classRosterArray[5];
    // Size of array since we are using array (limited size unlike a vector)
    int size; 

// defining the public getters/setters/constructers/destructers

public:
    // Constructor
    Roster();

    // Destructor
    ~Roster();

    // Functions
    
    void parseAndAddStudent(const std::string& studentData);
    void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(std::string studentID);
    void printAll();
    void printAverageDaysInCourse(std::string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);

    // Getters
    
    int getSize() const;
    std::string getStudentID(int index) const;

};