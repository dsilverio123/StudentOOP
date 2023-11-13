#pragma once
//If degree is not defined
#ifndef DEGREE_H
//Define Degree
#define DEGREE_H 
// Include string for degreeAsString
#include <string>

//C.  Define an enumerated data type DegreeProgram for the degree programs containing the data type values SECURITY, NETWORK, and SOFTWARE.
//Note: This information should be included in the degree.h file.


// Gives numeration to each of the values
enum DegreeProgram { SECURITY, NETWORK, SOFTWARE };

// Gives string value to DegreeProgram
static const std::string degreeAsString[] = { "Security", "Network", "Software"};

// End Statement

#endif
