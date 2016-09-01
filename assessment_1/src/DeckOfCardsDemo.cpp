#include <iostream> // for cout and endl
#include <cstdlib>  // for srand, rand and atoi
#include <ctime>    // for time
#include "DeckOfCards.h"

/**
 * This is an example program that shows how to seed a random number generator
 * using a number provided from the command line and then access those random numbers.
 *
 * It will use a number provided on the command line (e.g. test_random.exe 12321) if one exists
 * otherwise it will seed the random nmber using the current time in seconds
 *
 * @param argc the number of arguments provided to the main function (this includes the program name itself)
 * @param argv an array of strings containing each of the arguments
 *
 * @author Trent Houliston
 */
int main(int argc, char* argv[]) {

    // Make sure we have at least two arguments
    // The first argument will be the program name e.g. myCode.exe
    // The second argument will be the seed for the random number generator
    if (argc >= 2) {
        // Use atoi (ascii to integer) to convert our argument to a number
        // note that if the user enters an invalid number this will be 0
        int seed = atoi(argv[1]);

        // Use that number to seed the random number generator
        srand(seed);
    }
    // If we don't have at least two arguments seed the random number generator using the current time
    else {
        // Get the current time as an integer
        int seed = time(NULL);

        // Use that number to seed the random number generator
        srand(seed);
    }

  DeckOfCards* deck = new DeckOfCards();
  std::cout << deck->length() << std::endl;
  std::cout << deck->value() << std::endl;

  deck->shuffle();
  
  std::cout << deck->value() << std::endl;
  std::cout << deck << std::endl;
  deck->shuffle();

  // for (int i=0;i<100;i++)
  // {
  //  string str = std::to_string(l1->list_length());
  //  l1->list_insert(str);
  //  cout << str << " stored at: " << l1->list_length()-1 << endl;
  // }

  // cout << "done!" << endl;

  // if (l1->list_search("69")) {cout << "found 69!!!" << endl;}

  // l1->list_clear();

  //cout << "Zesty dek of cardz" << endl;
}
