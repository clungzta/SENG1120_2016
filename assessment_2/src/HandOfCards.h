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

      // Precondition: None
      // Postcondition: counts then returns the value of the hand (but only the
      // cards facing up). Counts according to blackjack rules.
      int count() const;

      // Precondition: None
      // Postcondition: returns the value of the hand (counts all cards
      // facing both up and down). Counts according to blackjack rules.
      int countAll() const;
      
      // Precondition: None
      // Postcondition: All cards in the hand are face up.
      void faceUp();

      // Precondition: None
      // Postcondition: A new card is added to the hand.
      // param @back is the card
      // param @face_up sets whether the card is to face up or down in the hand
      void add(Card back, bool face_up);

      // Precondition: None
      // Postcondition: A string is returned displaying the sequence of cards in the hand
      std::string value() const;
    
    private:
      //Linked List to contain the card names
      LinkedList<Card>* list;
  };

  //Overloading the cout operator for a HandOfCards object
  std::ostream& operator<<(std::ostream& out, const HandOfCards& hand);
}  
#endif