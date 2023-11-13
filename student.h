#pragma once
#include "degree.h"
#include <iostream>
#include <string>

class Student {
private:

    // Defining the private variables
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string email;
    int age;
    int daysInCourse[3];
    DegreeProgram degreeProgram;

/*


D.  For the Student class, do the following:
1.  Create the class Student  in the files student.h and student.cpp, which includes each of the following variables:
2.  Create each of the following functions in the Student class:
a.  an accessor (i.e., getter) for each instance variable from part D1
b.  a mutator (i.e., setter) for each instance variable from part D1
c.  All external access and changes to any instance variables of the Student class must be done using accessor and mutator functions.
d.  constructor using all of the input parameters provided in the table
e.  print() to print specific student data

*/

// defining the public getters/setters/constructers/destructers

public:
    // Default Constructer
    Student();
    // Parameterized Constructer
    Student(std::string studentID, std::string firstName, std::string lastName, std::string email, int age, int course1, int course2, int course3, DegreeProgram degreeProgram);
    // Destructer
    ~Student();

    // Getters
    std::string getStudentID() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getEmail () const;
    int getAge() const; 
    // Pointer to constant DaysInCourse[]
    const int* getDaysInCourse() const;
    // Value at particular index within the DaysInCourse[]
    int getDaysInCourse(int index) const;
    DegreeProgram getDegreeProgram() const; 
    int getSize() const;


    // Setters
    void setStudentID(std::string studentID);
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setEmail(std::string email);
    void setAge(int age);
    void setDaysInCourse(int num0, int num1, int num2);
    void setDegreeProgram(DegreeProgram degree);


    // Print Function
    void print() const;
};