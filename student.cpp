#include "student.h"
#include "degree.h"

// Constructor
Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string email, int age, int course1, int course2, int course3, DegreeProgram degreeProgram) {
    // Initialize the student member variables
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    this->degreeProgram = degreeProgram;
    this->setDaysInCourse(course1, course2, course3);
}

// Destructer
Student::~Student () {

}

// Getters
std::string Student::getStudentID() const { return studentID; }
std::string Student::getFirstName() const { return firstName; }
std::string Student::getLastName() const { return lastName; }
std::string Student::getEmail() const { return email; }
int Student::getAge() const { return age; }
const int* Student::getDaysInCourse() const {
    return daysInCourse;
}

int Student::getDaysInCourse(int index) const {
    if (index >= 0 && index < 3) { 
        return daysInCourse[index];
    }
}

DegreeProgram Student::getDegreeProgram() const { return degreeProgram; }

// Setters
void Student::setStudentID(std::string studentID) { this->studentID = studentID; }
void Student::setFirstName(std::string firstName) { this->firstName = firstName; }
void Student::setLastName(std::string lastName) { this->lastName = lastName; }
void Student::setEmail(std::string email) { this->email = email; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysInCourse(int num0, int num1, int num2) {
    this->daysInCourse[0] = num0;
    this->daysInCourse[1] = num1;
    this->daysInCourse[2] = num2;
}
void Student::setDegreeProgram(DegreeProgram degree) { this->degreeProgram = degree; }

// Print Function using the getters to print in a cout statement
// Later used in Roster class for student objects
void Student::print() const {
    std::cout << getStudentID() << "\t";
    std::cout << "First Name: " << getFirstName() << "\t";
    std::cout << "Last Name: " << getLastName() << "\t";
    std::cout << "Age: " << getAge() << "\t";
    std::cout << "Days In Course: {" << getDaysInCourse(0) << ", ";
    std::cout << getDaysInCourse(1) << ", ";
    std::cout << getDaysInCourse(2) << "} ";
    std::cout << "Degree Program: " << degreeAsString[getDegreeProgram()] << std::endl;
}