#include "degree.h"
#include "student.h"
#include "roster.h"
#include <iostream>

/*F.  Demonstrate the program’s required functionality by adding a main() function in main.cpp, which will contain the required function calls to achieve the following results:
1.  Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.
2.  Create an instance of the Roster class called classRoster.
3.  Add each student to classRoster.
4.  Convert the following pseudo code to complete the rest of the  main() function:
classRoster.printAll();
classRoster.printInvalidEmails();
//loop through classRosterArray and for each element:
classRoster.printAverageDaysInCourse(/*current_object's student id
classRoster.printByDegreeProgram(SOFTWARE);
classRoster.remove("A3");
classRoster.printAll();
classRoster.remove("A3");
5.  Implement the destructor to release the memory that was allocated dynamically in Roster.
 */

int main() {

    // WGU Student Information
    std::cout << "Course: Scripting and Programming - Applications - C867" << std::endl;
	std::cout << "Coding Language: C++" << std::endl;
	std::cout << "WGU ID: 010987822" << std::endl;
	std::cout << "Name: Daniel Silverio" << std::endl;

    // Initalizing Roster Class as classRoster
    Roster classRoster;
    
    // studentData string
    std::string studentData[] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
    "A5,Daniel,Silverio,dsil127@wgu.edu,22,20,14,23,SOFTWARE"
    };

    // Parse and add each student from the studentData array using a loop
    for (const std::string& data : studentData) {
        classRoster.parseAndAddStudent(data);
    }

    std::cout << "Printing All Student Objects in Roster Class." << std::endl;
    std::cout << "-------------------------------------------------------------------" << std::endl;
    
    classRoster.printAll();

    std::cout << "Printing Invalid Emails for each Student Object in Roster Class:" << std::endl;
    std::cout << "-------------------------------------------------------------------" << std::endl;

    classRoster.printInvalidEmails();
    
    std::cout << "Printing Average Days in Course per each Student Object in Roster Class:" << std::endl;
    std::cout << "-------------------------------------------------------------------" << std::endl;

    // Loops through classRoster and printAverageDaysInCourse for each student object in the roster 
    for (int i = 0; i < classRoster.getSize(); ++i) {
        std::string studentID = classRoster.getStudentID(i);
        classRoster.printAverageDaysInCourse(studentID);
    }

    // Printing by Software Degree Program
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
    
    classRoster.remove("A3");

    std::cout << "Printing All Student Objects in Roster Class:" << std::endl;
    std::cout << "-------------------------------------------------------------------" << std::endl;

    classRoster.printAll();
    classRoster.remove("A3");

}