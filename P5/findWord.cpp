/* CS 368 Programming Assignment 5
 * Semester: 2016 spring
 * Auther: Jieru Hu
 * Email:jhu76@wisc.edu
 * CS login:jieru
 */
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>

 
using namespace std;

int main(int argc, char* argv[]){
	
    //check te command line argument
    if(argc != 3){
        cout<<"Proper usage: findWord <word> <file>"<<endl;
        cout<<"where\n  <word> is a sequence of non-whitespace characters"<<endl;
        cout<<"  <file> is the file in which to search for the word"<<endl;
        cout<<"example: findWord the test.txt"<<endl;
        exit(0);
	}
    
    //open the file
    ifstream inFile(argv[2]);
    if (!inFile) {
        cerr << "File '" <<argv[2]<<"' could not be opened"<< endl;
        return 1;
    }
    
    
    int total = 0;
    string word = argv[1];
    int wordlength = word.length();
    
    cout<<"Searching for '"<<word<<"' in file '"<<argv[2]<<"'"<<endl;
    string line;
    int linenum = 0;
    
    // read next line
    while(!getline(inFile,line).eof()){
        linenum++;
        int printed = 0;
        int linesize = line.length();
        for(int i = 0;i<linesize;i++){
            string temp = line.substr(i,wordlength);
            if(word.compare(temp) == 0){
                //if they are equal
                total++;
                //check if the sentence is printed
                if (!printed){
                    cout<<linenum<<" : "<<line<<endl;
                    printed = 1;
                }
            }
        }
        
    }
    
    
    cout << "# occurrences of '" << word << "' = "<< total<<endl;
    
    //close the file
    inFile.close();
    
    
    return 0;

}

