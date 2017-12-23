#include <iostream>
#include "Student.h"
#include "Database.h"
#include <vector>
#include <string>
#include <fstream>
#include <ctype.h>
#include <stdio.h>
#include <sstream>


using namespace std;



int main(int argc, char* argv[])
{
    if(argc != 2){
        std:out << "One argument should be passed!" << endl;
    }
    ifstream infile(argv[1]);
    if(!infile.is_open()){
        std::cout << "File is not opened! "<<endl;
    }
    infile >> num;
    Database database(num);
    int id;
    int numofcourse;
    while(infile >> id >> numofcourse){
        Student newstudent(id,numofcourse);
        int course;
        int credit;
        string grade;
        for(int i =0);i<numofcourse;i++){
            infile >> course >> credit >> grade;
            if(isupper(grade)){
                grade = tolower(grade);
            }
            newstudent.addStudentCourseInfo(course,credit,grade);
        }
       
    }
  
    infile.close();
    while(true){
        string in;
        getline(cin,in)
        stringstream converter;
        converter << lin;
        char option;
        int value;
        converter >> option;
        if(!converter >> value){
            num = 0;
        }
        /*check if input is valid */
        if(option == "c"){
            if(value <0 || value >1000){
                std::cout << "Invalid Command. Need help?" << endl;
                option = "h";
            }
        }
        if(option == "g"){
            if(value < 10000 || value > 99999){
                std:cout <<"Invalid Command. Need help?" << endl;
                option = "h";
            }
        }
        if(option == "p"){
            if(value < 0 || value >4){
                std:cout <<"Invalid Command. Need help?" << endl;
                option = "h";
            }
        }
        
        
        database.dataProcess(option,value);
        
    }
    
    
    
    return 0;
}