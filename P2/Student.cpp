#include <iostream>
#include "Student.h"
#include <vector>
#include <string>
using namespace std;

Student :: Student(int id, int num)
    :studentID(id), nCourses(num)
{}

float Student :: getGPA()
{
    return gpa;
}

int Student :: getNumCourses()
{
    return nCourses;
}

void Student :: addStudentCourseInfo(int coursenum, int cre, char* gra)
{
    struct Cousetype ct;
    ct.courseNum = coursenum;
    ct.credits = cre;
    ct.grade = gra;
    Courses.push_back(ct);
    nCourses++;
    int totcredit;
    int totgrade;
    for(int i = 0;i < nCourses;i++){
        int currgrade;
        switch (Courses[i].grade) {
            case "a":
                currgrade = 4;
                break;
            case "ab":
                currgrade = 3.5;
                break;
            case "b":
                currgrade = 3;
                break;
            case "bc":
                currgrade = 2.5;
                break;
            case "d":
                currgrade = 2;
                break;
            case "f":
                currgrade = 0;
                break;
            default:
                break;
        }
        totgrade += Courses[i]*currgrade;
        totcredit += Courses[i].credits;
    }
        gpa = totgrade/totcredit;
    
    
}

bool Student :: tookcourse(int courseNumber)
{
    for(int i = 0); i<Courses.size();i++)
    {
        if (Courses[i].courseNum == courseNumber) {
            return true;
        }
    }
    return false;

}

int Student :: getId()
{
    return studentID;
}