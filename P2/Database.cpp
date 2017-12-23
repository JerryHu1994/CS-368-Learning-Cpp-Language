#include <iostream>
#include "Student.h"
#include "Database.h"
#include <vector>
#include <ctype.h>

using namespace std;

Database :: Database(int n)
    :numStudents(n)
{
}

void Database :: addStudent(Student s)
{
    students.push_back(s);
}

int Database :: getNumStudents()
{
    return numStudents;
}

void Database :: dataProcess(char a, int value)
{
    if(isupper(a)){
        a = tolower(a);
    }
    switch (a) {
        case "h":
            std::cout <<"You can enter the following valid commands:" << endl;
            std::cout <<"n: Get number of student in the database" << endl;
            std::cout <<"c num: Get number of students who took course 'num'. Also prints student IDs" << endl;
            std::cout <<"g student_ID: Get GPA of student student_ID" << endl;
            std::cout <<"p num: Get number of students with GPA>num. Also print student IDs" << endl;
            std::cout <<"q: Quit" << endl;
            break;
        case "n":
            std::cout << getNumStudents() + "\n":
            break;
            
        case "c":
            vector <int> idlist ;
            for(int i = 0; i<getNumStudents();i++){
                if(students[i].tookcourse(value)){
                    idlist.push_back(students[i].getId());
                }
            }
            std::out << idlist.size() + "\n";
            for(int i = 0; i<idlist.size();i++){
                std::out << idlist[i] + "\n";
            }
            break;
            
        case "g":
            for(int i = 0; i<getNumStudents();i++){
                if(students[i] == value){
                    std::out << students[i].getGPA();
                }
            }
            
            break;
        case "p":
            vector <int> idlist;
            for(int i = 0;i<getNumStudents;i++){
                if(students[i].getGPA > value){
                    idlist.push_back(students[i].getId);
                }
            }
            std::out << idlist.size() + "\n";
            for(int i = 0; i<idlist.size();i++){
                std::out << idlist[i] + "\n";
            }
            break;
            
        case "q":
            exit(0);
            break;
        default:
            break;
    }
    
    
    
    
    
    
    
}