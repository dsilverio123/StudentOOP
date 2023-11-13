#include "roster.h"
#include <iostream>
#include <sstream>

/*
Create a Roster class (roster.cpp) by doing the following:
1.  Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”
2.  Create a student object for each student in the data table and populate classRosterArray.
a.  Parse each set of data identified in the “studentData Table.”
b.  Add each student object to classRosterArray.
3.  Define the following functions:
a.  public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)  that sets the instance variables from part D1 and updates the roster.
b.  public void remove(string studentID)  that removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.
c. public void printAll() that prints a complete tab-separated list of student data in the provided format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll() function should loop through all the students in classRosterArray and call the print() function for each student.
d.  public void printAverageDaysInCourse(string studentID)  that correctly prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.
e.  public void printInvalidEmails() that verifies student email addresses and displays all invalid email addresses to the user.
*/

// Constructor
Roster::Roster() : size(0) {
    for (int i = 0; i < 5; ++i) {
        classRosterArray[i] = nullptr;
    }
}

// Destructor
Roster::~Roster() {
    for (int i = 0; i < size; ++i) {
        delete classRosterArray[i];
        std::cout << "Student object has been deleted from Roster." << std::endl;
    }
        std::cout << "Roster class has been destructed." << std::endl;

}

// parses And Add Student Object to classRosterArray by using studentData string parameter
void Roster::parseAndAddStudent(const std::string& studentData) {

    std::istringstream ss(studentData);
    std::string token;

    // Initialize string variables 
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    // Initialize variable integer to 0
    int age = 0;
    int daysInCourse1 = 0;
    int daysInCourse2 = 0;
    int daysInCourse3 = 0;
    DegreeProgram degreeProgram = DegreeProgram::SOFTWARE; // Sets default value, but changes as we parse

    int tokenCount = 0;
    // Loops extracts information one token at a time each correlating with information in the classRosterArray
    while (std::getline(ss, token, ',')) { // Note that loop reads from the string stream until it meets a "," marking the end of the token
        switch (tokenCount) {
            case 0:
                studentID = token;
                break;
            case 1:
                firstName = token;
                break;
            case 2:
                lastName = token;
                break;
            case 3:
                emailAddress = token;
                break;
            case 4:
                age = std::stoi(token);
                break;
            case 5:
                daysInCourse1 = std::stoi(token);
                break;
            case 6:
                daysInCourse2 = std::stoi(token);
                break;
            case 7:
                daysInCourse3 = std::stoi(token);
                break;
                // Parses and selects the correct DegreeProgram after default was selected
            case 8:
                if (token == "SECURITY") {
                    degreeProgram = DegreeProgram::SECURITY;
                } else if (token == "NETWORK") {
                    degreeProgram = DegreeProgram::NETWORK;
                } else if (token == "SOFTWARE") {
                    degreeProgram = DegreeProgram::SOFTWARE;
                }
                break;
        }
        tokenCount++;
        // After one token is read, the tokenCount switches to the next case
        // tokenCount++ works to walk through each token until loop is complete

    }

    // After parsing the tpkens and reaching the end of the tokens, add Student Object to classRosterArray
    add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}




// Add a new student to the classRosterArray
// If Roster is full, error message

void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    if (size < 5) {
        classRosterArray[size] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
        size++;
    } else {
        std::cout << "Roster is full. Cannot add more students to the Roster class." << std::endl;
    }
}

// Removes student object from classRosterArray by using getStudentID
// Error statement if student does not exist

void Roster::remove(std::string studentID) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            delete classRosterArray[i];
            for (int j = i; j < size - 1; ++j) {
                classRosterArray[j] = classRosterArray[j + 1];
            }
            classRosterArray[size - 1] = nullptr;
            size--;
            found = true;
            std::cout << "Student with ID " << studentID << " has been removed from the roster." << std::endl;
            break;
        }
    }
    if (!found) {
        std::cout << "Student with ID " << studentID << " not found in the roster." << std::endl;
    }
}

void Roster::printAll() {
    for (int i = 0; i < size; ++i) {
        classRosterArray[i]->print(); // Call the print function from the Student class
    }
}

// Used in the loop to loop through Average Days -- gets size of array
// Returns number of students in classRosterArray
int Roster::getSize() const {
    return size;
}

// Implement getStudentID function -- Used in the loop Student Objects through Average Days 
// Returns the studentID one by one in Roster Array
std::string Roster::getStudentID(int index) const {
    if (index >= 0 && index < size) {
        return classRosterArray[index]->getStudentID();
    }
    return ""; 
}

// Prints average day of student by using studentID parameter 
void Roster::printAverageDaysInCourse(std::string studentID) {
    for (int i = 0; i < size; ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            const int* days = classRosterArray[i]->getDaysInCourse();
            double avgDays = static_cast<double>(days[0] + days[1] + days[2]) / 3.0; 
            std::cout << "Average days in course for student " << studentID << ": " << avgDays << std::endl;
            return;
        }
    }
    std::cout << "Student with ID " << studentID << " not found in the roster." << std::endl;
}

// Print invalid email addresses by looping through to identify inconsistent values in Email and using getEmail
// Uses .find to find specific strings that are needed in emails or incorrectly inputted    
void Roster::printInvalidEmails() {
    for (int i = 0; i < size; ++i) {
        std::string email = classRosterArray[i]->getEmail();
        if (email.find('@') == std::string::npos || email.find('.') == std::string::npos || email.find(' ') != std::string::npos) {
            std::cout << "Invalid Email Address found for Student ID " << classRosterArray[i]->getStudentID() << ": " << email << std::endl;
        }
    }
}

// Loops through classRosterArray
// To Print student information using a specific degree program parameter
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    std::cout << "Printing By Degree Program: " << degreeAsString[degreeProgram] << std::endl; // Converts from number to string
    for (int i = 0; i < size; ++i) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}
