/**

SENG1120 Assignment 1
Created by Alex McClung
Semester 2 2016

**/

#ifndef HANDOFCARDS_H
#define HANDOFCARDS_H

#include <string>
#include "LinkedList.h"
#include "Card.h"

namespace alex_m
{
  class HandOfCards
  {
    public:

      //Constructor
      // Precondition: None
      // Postcondition: A full deck of cards is generated.
      // The card names are stored in a LinkedList of string data.
      // Numbers are 2 to 10, plus J, Q, K, A. 
      // There are four cards of each suit, i.e. “S” = spades, “H” for hearts, “C” for clubs, “D” for diamonds
      HandOfCards();

      //Destructor
      // Precondition: A DeckOfClass object is instansiated.
      // Postcondition: The list pointer (member variable) is deleted.
      // This frees the memory used by the list from the heap.
      ~HandOfCards();

      // counts the value of the hand stored in the list (but only the
      // cards facing up). Each card 2-10 have their face value. J, Q and K are worth
      // 10 points each. A is worth 11 points (this is a simplification of the
      // traditional Blackjack rules).
      int count();

      // counts the value of the hand stored in the list (all cards
      // facing both up and down).
      // string value() returns a string displaying the sequence of cards
      // stored in HandOfCards. Face-down cards must be displayed with “?-?”
      // symbol.
      int countAll();
      
      // makes all cards face-up.
      // Overloaded output operator (i.e. ‘<<’) outputs the content of the
      // HandOfCards in a form suitable for printing. Hint: This method should
      // use string value() in its implementation.
      void faceUp();

      // takes a single Card and a boolean
      // arguments and adds the card in HandOfCards, either facing-up (true) or
      // down (false).
      void add(Card back, bool face_up);

      // Precondition: None
      // Postcondition: A string is returned displaying the sequence of cards in the deck
      std::string value() const;
    
    private:
      //Linked List to contain the card names
      LinkedList<Card>* list;
  };

  //Overloading the cout operator for a HandOfCards object
  std::ostream& operator<<(std::ostream& out, const HandOfCards& hand);
}  
#endif