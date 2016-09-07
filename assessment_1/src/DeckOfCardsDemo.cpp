#include <iostream> // for cout and endl
#include <cstdlib>  // for srand, rand and atoi
#include <ctime>    // for time
#include "DeckOfCards.h"

int main(int argc, char* argv[]) {

    if (argc >= 2) {
        int seed = atoi(argv[1]);
        srand(seed);
    }
    else {
        int seed = time(NULL);
        srand(seed);
    }

  DeckOfCards* deck = new DeckOfCards();
  
  std::cout << deck->value() << std::endl;
  
  deck->shuffle();
  
  std::cout << deck << std::endl;

  std::cout << deck->position("4-H") << " " << deck->position("10-S") << " " << deck->position("Q-C") << " " << deck->position("A-D") << " " << std::endl;

  deck->remove("4-H");
  deck->remove("10-S");

  std::cout << deck->value() << std::endl;

  std::cout << deck->position("4-H") << " " << deck->position("10-S") << " " << deck->position("Q-C") << " " << deck->position("A-D") << " " << std::endl;
  
  std::cout << deck->length() << std::endl;
  
}
