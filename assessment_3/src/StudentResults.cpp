/**

SENG1120 Assignment 3
Created by Alex McClung, 3256853
Semester 2 2016

**/

#include <iostream> // for cout and endl
#include <cstdlib>  // for srand, rand and atoi
#include <ctime>    // for time
#include "ClassroomOfStudents.h"

using namespace std;
using namespace alex_m;

int main(int argc, char* argv[]) {
        
    if (argc >= 2) {
        //Initialise the random number generator by inputing a seed value as an argument 
        int seed = atoi(argv[1]);
        srand(seed);
    }
    else {
        //No argument input, use the current time as a seed 
        int seed = time(NULL);
        srand(seed);
    }

    cout.precision(2);

    std::list<std::string> student_names = { "Adam", "Adrian", "Alexander", "Andrew", "Ashley", "Benjamin", "Bradley", "Brobie", "Callan",
     "Callum", "Cameron", "Chris", "Damian", "David", "Dillon", "Dylan", "Ethan", "Frederik", "Hong", "Hugh", "Jackson",
     "Jacob", "James", "Jared", "Jodi", "Jonathan", "Joshua", "Julius", "Kelly", "Kenias", "KiSoon", "Lance", "Liam",
     "Madison", "Magdalena", "Marcus", "Mark", "Melanie", "Min", "Mitchell", "Nicholas", "Ryan", "Sang", "Shane", "Simon",
     "Thomas", "Timothy", "Trent", "Troy", "Zaanif" };


    ClassroomOfStudents* classroom = new ClassroomOfStudents(student_names);

    //Step 3 - Print out all names and grades using the inorder traversal
    cout << *classroom << endl;    
    
    //Step 4 - Print out how many students had a grade ≥ 85, by recursively traversing the tree
    cout << endl << "HDs: " << classroom->countHDs() << endl;
    
    //Step 5 - Print out the average of the class, by recursively traversing the tree
    cout << "Average: " << classroom->get_average_grade() << endl;
    
    //Step 6 - Delete all students who had a grade < 50
    classroom->remove_failed();

    //Step 7 - Redo steps 3, 4 and 5 with the new tree
    cout << endl << *classroom << endl;
    cout << endl << "HDs: " << classroom->countHDs() << endl;
    cout << "Average: " << classroom->get_average_grade() << endl;

    delete classroom;
    return 0;
}