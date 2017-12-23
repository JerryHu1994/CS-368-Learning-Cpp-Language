#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "SortedList.h"
#include "Student.h"
using namespace std;	
	//Field
	
	//Constructor
	/*
	int studentID;
    int credits;
    double GPA;
	*/
	Student::Student(){
		studentID = 0;
		credits = 0;
		GPA = 0.0;
		}
    // Constructs a default student with an ID of 0, 0 credits, and 0.0 GPA.

    Student::Student(int ID){
		studentID = ID;
		credits = 0;
		GPA = 0.0;
		}
    // Constructs a student with the given ID, 0 credits, and 0.0 GPA.

    Student::Student(int ID, int cr, double grPtAv){
		studentID = ID;
		credits = cr;
		GPA = grPtAv;
		}
    // Constructs a student with the given ID, number of credits, and GPA.
	
	/*	
	// copy constructor
	Student::Student(const Student &S) :              
		studentID(S.studentID), credits(S.credits),GPA(S.GPA)
	{}
	
	//destructor
    Student::~Student()
    {	delete studentID;
		delete credits;
		delete GPA;
	}           
*/

/*	
	//assignment                  
    Student & Student::operator=(const Student &S)
    {
		if(this != &s){
			studentID = S.studentID;
			credits = S.credits;
			GPA = S.GPA;
		}
		return *this;
	}  
	*/
	
	
  // Accessors
    int Student::getID() const{
		return studentID;
		}      // returns the student ID
    int Student::getCredits() const{
		return credits;
		}  // returns the number of credits
    double Student::getGPA() const{
		return GPA;
		}   // returns the GPA
    
    // Other methods

    void Student::update(char grade, int cr){
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
    	
        double gradeValue = 0.0;
 	
        switch(grade){
            case 'a': gradeValue = 4.0; break;
            case 'b': gradeValue = 3.0; break;
            case 'c': gradeValue = 2.0; break;
            case 'd': gradeValue = 1.0; break;
            case 'f':	break;
        }
        double tempGPA = GPA;
        GPA = (tempGPA * credits) + (gradeValue * cr);
        GPA = GPA / credits;
	}
    void Student::print() const{ 
    // Prints out the student to standard output in the format:
    //   ID,credits,GPA
        cout << "ID: " << studentID << " Credits: " << credits << " GPA: " << GPA <<endl;
	}
