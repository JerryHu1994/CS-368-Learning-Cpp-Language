#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "SortedList.h"
#include "Student.h"

using namespace std;
	SortedList::SortedList(){
		head = NULL;
	}

	
	/*
	//copy constructor
    SortedList::SortedList(const SortedList &S){
		head = NULL;
		Listnode *curr = S.head;
		Listnode *last = NULL;
		
		while(curr != NULL){
			Listnode* n = new ListNode();
			n->student = curr->student;
			 
			if(last != NULL){
				last -> next = n;
			}else{
				head = n;
			}
		last = n;
		curr = curr->next;
		}
	}              
	
	//destructor
    SortedList::~SortedList(){
		freeList(head);
		}
		
	//assignment	                               
    SortedList & SortedList::operator=(const SortedList &S){
        //first free the memory
		freeList(head);
        //then copy the info
		copyList(S);
	}  
*/
		
	// If a student with the same ID is not already in the list, inserts 
    // the given student into the list in the appropriate place and returns
    // true.  If there is already a student in the list with the same ID
    // then the list is not changed and false is returned.
    bool SortedList::insert(Student *s){
		Listnode *temp = head;
		Listnode *new_node = new Listnode();
		int ID = s->getID();
        
        //check null head
		if(head == NULL){
			new_node -> student = s;
			head = new_node;
            return true;
        }
		//check same ID
		while(temp != NULL){
			if((temp->student)->getID() == ID){
				cout<<"The student is already in the list"<<endl;
				return false;
			}
			temp = temp->next;
		}
        temp = head;
        
        //compare with the first node
        int firstid = temp->student->getID();
        if(ID < firstid){
            new_node->student = s;
            new_node->next = temp;
            head = new_node;
            return true;
        }
        
        //compare with the id after first node
        do{
            //int currid = temp->student->getID();
            if(temp -> next == NULL){
                new_node->student = s;
                new_node->next = NULL;
                temp -> next = new_node;
                return true;
            }else{
                int nextid = temp->next->student->getID();
                if(ID < nextid){
                    new_node->student = s;
                    new_node->next = temp->next;
                    temp->next = new_node;
                    return true;
                }
            }
            temp = temp -> next;
        }while(true);
        
	
}
		

		
    
    // Searches the list for a student with the given student ID.  If the
    // student is found, it is returned; if it is not found, NULL is returned.
    Student* SortedList:: find(int studentID){
		Listnode * temp = head;
		if(head == NULL){
            return NULL;
			}
		while(temp != NULL){
			if(temp->student->getID() == studentID){
				return temp->student;
			}
			temp = temp->next;
        }
			return NULL;
		}

    // Searches the list for a student with the given student ID.  If the 
    // student is found, the student is removed from the list and returned;
    // if no student is found with the given ID, NULL is returned.
    // Note that the Student is NOT deleted - it is returned - however,
    // the removed list node should be deleted.
    Student* SortedList::remove(int studentID){
			Listnode * temp = head;
			if(head == NULL){
				cout<<"The list is empty"<<endl;
				return NULL;
				}
			if(head->student->getID() == studentID)
			{ 	Student* s = head->student;
				head = head->next; 
				return s;
			}
			while(temp->next != NULL){
				//int thisID = temp->student.getID();
				Listnode *next = temp->next;
				if(next->student->getID() == studentID){	
					//delete the temp
					temp->next = next->next;
					return temp->student;}
				temp = temp->next;		
					
				}
				return NULL;	
			}
		
 
   // Prints out the list of students to standard output.  The students are
    // printed in order of student ID (from smallest to largest), one per line
    void SortedList::print() const{
		Listnode * temp  = head;
        if(temp == NULL){
            cout << "The list is empty" <<endl;
        }else{
            while (temp != NULL){
                temp->student->print();
                temp = temp->next;
            }
		}
	}
 
    // Since Listnodes will only be used within the SortedList class,
    // we make it private.
   // removes all nodes from this list. Be sure to free all memory
     void     SortedList:: freeList (Listnode *L){
		Listnode *current = L;
		while(current != NULL){
			Listnode *next = current ->next;
			delete current;
			current = next;
		}
		L = NULL;
     } 
    // returns a pointer to the first node of a list with a 
    // copy of all nodes of the sorted list
    SortedList::Listnode* SortedList::copyList (Listnode *L){
		Listnode *curr = L;
        Listnode *head;
		Listnode *last = NULL;
	
		while(curr != NULL){
			Listnode* n = new Listnode();
			n->student = curr->student;
			 
			if(last != NULL){
				last -> next = n;
			}else{
				head = n;
			}
		last = n;
		curr = curr->next;
		}
        return head;
		
	}
	
