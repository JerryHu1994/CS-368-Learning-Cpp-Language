/* CS 368 Programming Assignment 3
 * Semester: 2016 Spring
 * Auther: Jieru Hu
 * Email: jhu76@wisc.edu
 * CS Login: jieru
 */
#include <iostream>
#include "Student.h"
#include <vector>
#include <string>
#include <map>
using namespace std;

//constructor with no parameter
Student :: Student(){
    studentID = 0;
    credits = 0;
    GPA = 0;
}


//constructor with one parameter ID
Student :: Student(int ID){
    studentID = ID;
    credits = 0;
    GPA = 0;
}

//constructor with ID, credit, gpa
Student :: Student(int ID, int cr, double grPtAv){
    studentID = ID;
    credits = cr;
    GPA = grPtAv;
}

// returns the student ID
int Student :: getID() const{
    return StudentID
}
// returns the number of credits
int Student :: getCredits() const{
    return credits
}
// returns the GPA
double Student :: getGPA() const{
}

 // Updates the total credits and overall GPA to take into account the
 // additions of the given letter grade in a course with the given number
 // of credits.  The update is done by first converting the letter grade
 // into a numeric value (A = 4.0, B = 3.0, etc.).  The new GPA is 
 // calculated using the formula:
 //
 //            (oldGPA * old_total_credits) + (numeric_grade * cr)
 //   newGPA = ---------------------------------------------------
 //                        old_total_credits + cr
 //
 // Finally, the total credits is updated (to old_total_credits + cr)
void Student :: update(char grade, int cr){
    float numeric_grade = 0;
    if(grade == 'a' || grade == 'A'){
        numeric_grade = 4;
    }
    if(grade == 'b' || grade == 'B'){
        numeric_grade = 3;
    }
    if(grade == 'c' || grade == 'C'){
        numeric_grade = 2;
    }
    if(grade == 'd' || grade =='D'){
        numeric_grade = 1;
    }
    if(grade == 'e' || grade == 'E'){
        numeric_grade = 0;
    }
    float newGPA = (GPA*credits+numeric_grade*cr)/(cr+credits);
    GPA = newGPA;
    
} 

// Prints out the student to standard output in the format:
//   ID,credits,GPA
// Note: the end-of-line is NOT printed after the student information 
void Student :: print() const{
    cout << studentID<<","<<credits<<","<<GPA<<endl;
}


