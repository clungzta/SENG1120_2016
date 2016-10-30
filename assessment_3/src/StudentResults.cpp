/**

SENG1120 Assignment 1
Created by Alex McClung
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

    std::list<std::string> student_names = { "Adam", "Adrian", "Alexander", "Andrew", "Ashley", "Benjamin", "Bradley", "Brobie", "Callan",
     "Callum", "Cameron", "Chris", "Damian", "David", "Dillon", "Dylan", "Ethan", "Frederik", "Hong", "Hugh", "Jackson",
     "Jacob", "James", "Jared", "Jodi", "Jonathan", "Joshua", "Julius", "Kelly", "Kenias", "KiSoon", "Lance", "Liam",
     "Madison", "Magdalena", "Marcus", "Mark", "Melanie", "Min", "Mitchell", "Nicholas", "Ryan", "Sang", "Shane", "Simon",
     "Thomas", "Timothy", "Trent", "Troy", "Zaanif" };

    ClassroomOfStudents* classroom = new ClassroomOfStudents(student_names);
    cout << "Average: " << classroom->get_average_grade() << endl;

    return 0;
}