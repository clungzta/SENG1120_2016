/**

SENG1120 Assignment 1
Created by Alex McClung
Semester 2 2016

**/

#include <iostream> // for cout and endl
#include <cstdlib>  // for srand, rand and atoi
#include <ctime>    // for time
#include "DeckOfCards.h"
#include "HandOfCards.h"

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
  
    //Step 1: create a new instance of DeckOfCards storing a full deck of cards, shuffle
    DeckOfCards deck;
    deck.shuffle();
    
    //Step 2: Create two instances of HandOfCards, named player1 and dealer.
    HandOfCards player1;
    HandOfCards dealer;

    //Step 3: Looping through the player and the dealer, give them one card each, facing up.
    for (int i=0;i<2;i++)
    {
      Card card = deck.pop(); //Pop a card from the top of the deck

      //Is this card going to the dealer or player (use modulo with two, to alternate with whether i is odd or even)
      if (i%2 == 0)
      {
        //Give Player the card from the top of the deck
        player1.add(card, true);
      }
      else
      {
        //Give Dealer a card from the top of the deck
        dealer.add(card, true);
      }
    }

    //Then, give one card to player 1, facing up.
    player1.add(deck.pop(), true);

    //Then, give one card to the dealer, facing down.
    dealer.add(deck.pop(), false);

    //Step 4: Display each hand’s content - for player and the dealer
    step_4:
      cout << "Player: " << player1 << "(" << player1.count() << " points)" << endl;
      cout << "Dealer: " << dealer << "(" << dealer.count() << " points)" << endl;

      //Step 5: Check if the player or the dealer have a count of 21
      if (player1.count() == 21 && dealer.countAll() == 21)
      {
        cout << "Tie! There are no winners." << endl;
        return 0;
      }
      else if (player1.count() == 21)
      {
        cout << "The player is the winner!" << endl;
        return 0;
      }
      else if (dealer.countAll() == 21 || player1.count() > 21)
      {
        cout << "The dealer is the winner!" << endl;
        return 0;
      }

      //Step 6: Ask “Player, do you want to Hit (1) or Stand (2)?” If the answer is 1, then give the
      // player another card from the deck, face-up, and go back to step (4). If the answer is 2,
      // continue to step (7). 
      cout << "Player, do you want to Hit (1) or Stand (2)?" << endl;

      // Accept cin input
      int input;
      cin >> input;

      // Prevent input of invalid characters, which will break the program (cause an infinite loop)
      // Just ignore any invalid (non integer) input
      if(cin.fail()) { cin.clear(); cin.ignore(); }

      //If the answer is 1, then give the player another card from the deck, face-up, and go back to step (4).
      if (input == 1)
      {
        player1.add(deck.pop(), true);

        // Go back to Step 4: Display each hand’s content - for player and the dealer
        goto step_4;
      }

      else if (input == 2)
      {
        //Step 7: Player is Stood, time to do the dealers play
        while (dealer.countAll() < 17) { dealer.add(deck.pop(), true); }
      }

      //Step 8: Make all cards in the dealer’s hand face-up, and display the contents of both hands using
      //the overloaded cout << operator, along with the count for each hand.
      dealer.faceUp();
      cout << "Player: " << player1 << "(" << player1.count() << " points)" << endl;
      cout << "Dealer: " << dealer << "(" << dealer.count() << " points)" << endl;

      //Step 9: Check who has the highest count among the two hands (but not over 21), and
      // print “The player/dealer is the winner.” and exit. If both got exactly 21, then print
      // “Tie! There are no winners.” 
      if (player1.count() > 21)
      {
        cout << "The dealer is the winner!" << endl;
      }
      else if (dealer.count() > 21)
      {
        cout << "The player is the winner!" << endl;
      }
      else if (player1.count() > dealer.count())
      {
        cout << "The player is the winner!" << endl;    
      }
      else if (player1.count() == dealer.count())
      {
        cout << "Tie! There are no winners" << endl;    
      }
      else if (dealer.count() > player1.count())
      {
        cout << "The dealer is the winner!" << endl;    
      }
      
      return 0;
}