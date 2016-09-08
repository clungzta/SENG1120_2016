/**

SENG1120 Assignment 1
Created by Alex McClung
Semester 2 2016

**/

#include <iostream> // for cout and endl
#include <cstdlib>  // for srand, rand and atoi
#include <ctime>    // for time
#include "DeckOfCards.h"

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
  
  //Step 1: create a new instance of DeckOfCards storing a full deck of cards
  DeckOfCards* deck = new DeckOfCards();

  //Step 2: Print the deck of cards using value().
  cout << deck->value() << endl;
  
  //Step 3: Shuffle the deck of cards using shuffle()
  deck->shuffle();
  
  //Step 4: Print the deck of cards again using overloaded cout << operator
  cout << *deck << endl;

  //Step 5: Print the position of cards “4-H”, “10-S”, “Q-C” and “A-D”, separated by a
  //single blank space.
  cout << deck->position("4-H") << " ";
  cout << deck->position("10-S") << " ";
  cout << deck->position("Q-C") << " ";
  cout << deck->position("A-D") << " " << endl;

  //Step 6: Print the total number of cards in DeckOfCards using length()
  std::cout << deck->length() << std::endl;

  //Step 7: Remove the cards “4-H” and “10-S”
  deck->remove("4-H");
  deck->remove("10-S");

  //Step 8: Print the position of cards “4-H”, “10-S”, “Q-C” and “A-D” again
  cout << deck->position("4-H") << " ";
  cout << deck->position("10-S") << " ";
  cout << deck->position("Q-C") << " ";
  cout << deck->position("A-D") << " " << endl;
  
  //Step 9: Print the total number of cards in DeckOfCards using length()
  std::cout << deck->length() << std::endl;

  //Clear the memory used on the heap by the deck of cards
  delete deck;
}
