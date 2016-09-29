/**

SENG1120 Assignment 1
Created by Alex McClung
Semester 2 2016

**/

#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include <string>
#include "LinkedList.h"
#include "Card.h"

namespace alex_m
{
  class DeckOfCards
  {
    public:

      //Constructor
      // Precondition: None
      // Postcondition: A full deck of cards is generated.
      // The card names are stored in a LinkedList of string data.
      // Numbers are 2 to 10, plus J, Q, K, A. 
      // There are four cards of each suit, i.e. “S” = spades, “H” for hearts, “C” for clubs, “D” for diamonds
      DeckOfCards();

      //Destructor
      // Precondition: A DeckOfClass object is instansiated.
      // Postcondition: The list pointer (member variable) is deleted.
      // This frees the memory used by the list from the heap.
      ~DeckOfCards();

      // Precondition: None
      // Postcondition: Boolean returns true if there are no cards in the deck, otherwise false.
      bool empty() const;

      // Precondition: There is an card in the deck with name param @str
      // Postcondition: This card is found, then removed from the deck
      bool remove(std::string str);

      // Precondition: None
      // Postcondition: The length of the deck is returned as an integer
      int length() const;

      // Precondition: There is an card in the deck with name param @str
      // Postcondition: The position of this card in the sequence is returned,
      // if there is no card with a matching name, -1 is returned
      int position(std::string str) const;

      // Precondition: There are cards stored in the deck
      // Postcondition: The positions of these cards are randomized
      // using the yates shuffle algorithm
      void shuffle();

      // Precondition: None
      // Postcondition: Card @back is added to the top of the deck
      void push(Card back);

      // Precondition: A card is at the top of the deck
      // Postcondition: This card object is returned, and removed from the top of the deck
      Card pop();

      // Precondition: None
      // Postcondition: A string is returned displaying the sequence of cards in the deck
      std::string value() const;
    
    private:

      // Precondition: The deck contains at least two cards
      // Postcondition: The card name at position (from head to tail) param @a in the sequence
      // is swapped with the card name at position param @b
      void swap_cards(const int a, const int b);

      //Linked List to contain the card names
      LinkedList<Card>* list;
  };

  //Overloading the cout operator for a DeckOfCards object
  std::ostream& operator<<(std::ostream& out, const DeckOfCards& deck);
}  
#endif