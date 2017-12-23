/* CS 368 Programming Assignment 3
 * Semester: 2016 Spring
 * Auther: Jieru Hu
 * Email: jhu76@wisc.edu
 * CS Login: jieru
 */

using namespace std;

// constructor
SortedList :: SortedList(){
	head = NULL;
}

// If a student with the same ID is not already in the list, inserts 
// the given student into the list in the appropriate place and returns
// true.  If there is already a student in the list with the same ID
// then the list is not changed and false is returned.
bool SortedList :: insert(Student *s){
    int id = *s.getID();
    //the list is empty
	if ( head == NULL){
		Listnode newnode;
		newnode -> student = s;
		newnode -> next = NULL;
        
		head = newnode;
        return True;
	}
    
    
    Listnode *curr = head;
    //compare with the first node
    int firstid = *(curr->student).getID();
    if(id == firstid){
        return false;
    }
    if(id < firstid){
        Listnode newnode;
        newnode -> student = s;
        newnode -> next = curr;
        head = newnode;
    }
    
	//compare with nodes after the first one
	do{
        int currid = *(curr->student).getID();
        if (currid == id){
            return false;
        }
        
        //if there is no nodes after the curr, insert it in the end
        if (curr -> next == NULL){
            Listnode newnode;
            newnode -> student = s;
            newnode -> next = NULL;
            curr -> next = newnode;
            
        }else{
            int nextid = *((curr->next)->student).getID();
            //case to insert the node after the curr
            if(id < nextid){
                Listnode newnode;
                newnode -> student = s;
                newnode -> next = curr->next;
                curr ->next = newnode;
            }
        }
    }while (true)
        
}

// Searches the list for a student with the given student ID.  If the
// student is found, it is returned; if it is not found, NULL is returned.
Student *Student :: find(int studentID){
    if (head == NULL){
        return NULL
    }
    Listnode *curr = head;
    do{
        int tempid = *(curr->student).getID();
        if (tempid == studentID){
            return curr;
        }
        if(curr->next != NULL){
            curr = curr->next;
        }else{
            break;
        }
        
    }while(true);
    
    return NULL
	
}

// Searches the list for a student with the given student ID.  If the 
// student is found, the student is removed from the list and returned;
// if no student is found with the given ID, NULL is returned.
// Note that the Student is NOT deleted - it is returned - however,
// the removed list node should be deleted.
Student *Student :: remove(int studentID){
    if (head == NULL){
        return NULL；
    }
    Listnode *curr = head;
    while (curr ->next != null){
        Listnode *n = curr -> next;
        int id = *(n->student).getID();
        if(id = studentID){
            curr->next = n->next；
            return n
        }
        
        
    }
    return NULL;
    
	
}


// Prints out the list of students to standard output.  The students are
// printed in order of student ID (from smallest to largest), one per line
void Student :: print() const{
    Listnode *curr = head;
    if (curr == NULL){
        
    }else{
        do{
            *(curr->student).print();
            if（curr->next != NULL）{
                curr = curr->next;
            }else{
                break;
            }
            
        }while(true)
        
    }
    
}

