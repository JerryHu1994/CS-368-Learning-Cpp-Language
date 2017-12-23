#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Student.h"
#include "SortedList.h"

using namespace std;
int main(int argc, char*argv[]){

	Student* s1 = new Student();
	Student* s2 = new Student(1);
	Student* s3 = new Student(2, 10, 3.5);
    Student* s4 = new Student(4, 30, 3.0);
    Student* s5 = new Student(5, 20, 3.75);
    Student* duplicate = new Student(2,5,3.1);
    
	
	SortedList list;
	 
	list.insert(s1);
	list.insert(s2);
    list.insert(s3);
    list.insert(s4);
    list.insert(s5);
    //Should print the student is already in the list
    cout << ">The list should print student already in the list:"<<endl;
    list.insert(duplicate);
    Student* found = list.find(4);
    //should print student info with ID equal to 2
    cout << ">The list should print student info with ID equal to 4:"<<endl;
    found->print();
    cout <<endl;

    //the list should contain five students now
    cout << ">The list should print total five students:" <<endl;
    list.print();
    cout <<endl;
    
	list.remove(0);
	list.remove(4);
	list.remove(2);
    
    //the list should contain two student now
    cout << ">The list should print two students:" <<endl;
    list.print();
    cout <<endl;
    list.remove(1);
    list.remove(5);
    
    //the list should be empty now
    cout << ">The list should be empty" <<endl;
    list.print();
	
	return 0;
}
