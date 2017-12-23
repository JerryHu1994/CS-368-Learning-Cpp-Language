/* CS368 Programming Assignment 1
 * Semester: 2016 Spring
 * Author: Jieru Hu
 * Email: jhu76@wisc.edu
 * CS Login: jieru
 */
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <cstdio>
using namespace std;

int num;//the length of the array
double array[100];//the array to store the values
int low;//the low range of the random numbers
int up;//the high range of the random numbers

/* The function returns the minimum number of the elements
 * in the array.
 */
double findMin(){
  double min = array[0];
  for(int i = 1; i < num; i++){
    if(array[i] < min){
      min = array[i];
    }
  }
  return min;
}

/* The function returns the maximum number of the elements
 * in the array.
 */
double findMax(){
  double max = array[0];
    for(int i = 1; i < num; i++){
    if(array[i] > max){
      max = array[i];
    }
  }
  return max;
}

/* The function returns a random double between low and up
 */
double generateRand(double low, double up){
  double f = (double)rand()/RAND_MAX;
  return low + f * (up - low);
}

/* The function lists the elements in the array in the increasing order;
 */
void sort(){
  int min_elem_index;
  for(int i = 0; i < num; i++){
    min_elem_index = i;
    for(int j =  i+1; j < num; j++){
      if(array[j] < array[min_elem_index]){
	  //swap
	  double temp = array[min_elem_index];
	  array[min_elem_index] = array[j];
	  array[j] = temp;
	}
    }
  }
}

/* The function returns the average number of the elements
 * in the array.
 */
double calAverage(){

  double total;
  for(int i = 0; i < num; i++){
    total += array[i];
  }
  return total/num;

}


/* The function prints the numbers in the array one by one*/
void printarray(){
  std::cout << "The elements of the array are: ";
  for (int i = 0; i < num; i++){
      printf("%.3lf ", array[i]);
  }
  std::cout << endl;
}



/* This is the main method of the program. The program displays the 
 * following prompt and let user input the choice. If the user makes
 * a valid choice, the program does the corresponding operation on an
 * array of numbers. 
 */
int main(int argc, char* argv[]){

  cout << "Welcome!"<< endl;
  int x;

  srand(1000);
  
  while(true){
    std::cout <<"1) Feed array input" << endl;
    std::cout <<"2) Determine the minimum element in the array" << endl;
    std::cout <<"3) Determine the maximum element in the array" << endl;
    std::cout <<"4) Sort the array of integers" << endl;
    std::cout <<"5) Determine the average of the elements in the array" << endl;
    std::cout <<"6) Randomly generate array elements within a specific range" << endl;
    std::cout <<"7) Print the elements of the array" << endl;
    std::cout <<"8) Exit program" << endl;
    std::cout <<"Enter your choice: ";
    
    cin >> x;
    switch(x){
    case 1:
            std::cout << "Enter the number of elements in the array: ";
            cin >> num;
            cout << "Enter the elements of the array: ";
            for(int j = 0; j < num; j++){
                cin >> array[j];
            }
            break;

    case 2:
            if(num == 0){
                printf("There must be at least one element in the array.\n");
            }else{
                printf("Minimum element in array: %.3lf\n", findMin());
            }
            break;

    case 3:
            if(num == 0){
                printf("There must be at least one element in the array.\n");
            }else{
                printf("Maximum element in array: %.3lf\n", findMax());
            }
            break;

    case 4:
            if(num == 0){
                printf("There must be at least one element in the array.\n");
            }else{
                sort();
                printarray();
            }
            break;
            
    case 5:
            if(num == 0){
                printf("There must be at least one element in the array.\n");
            }else{
                printf("The average of the elements are: %.3lf\n", calAverage());
            }
            break;
            
    case 6:
            std::cout << "Enter the number of elements in the array: ";
            cin >> num;
            if(num < 0){
                printf("There must be at least one element in the array.\n");
                break;
            }
            std::cout << "Enter the lower range for the elements: ";
            cin >> low;
            std::cout << "Enter the upper range for the elements: ";
            cin >> up;
            for(int i = 0; i < num; i++){
                array[i] = generateRand(low, up);
            }
            printarray();
            break;
            
    case 7:
            if(num == 0){
                printf("There must be at least one element in the array.\n");
            }else{
                printarray();
            }
            break;
            
    case 8:
            std::cout << "Exiting the program!\nThank you!" << endl;
            exit(1);
            break;
      
    default:
        break;

    }

  }
        return 1;
}
