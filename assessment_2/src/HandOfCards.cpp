/**

SENG1120 Assignment 1
Created by Alex McClung
Semester 2 2016

**/

#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include "HandOfCards.h"

namespace alex_m
{
  HandOfCards::HandOfCards()
  {
    list = new LinkedList<Card>();
  }

  //Destructor
  HandOfCards::~HandOfCards()
  {
    delete list;
  }

  // counts the value of the hand stored in the list (all cards
  // facing both up and down).
  // string value() returns a string displaying the sequence of cards
  // stored in HandOfCards. Face-down cards must be displayed with “?-?”
  // symbol.
  int HandOfCards::countAll()
  {
    int count = 0;
    if (list->goto_head())
    {
      //Iterate through the entire deck
      do {
        count += list->get_current().get_value();
      } while (list->forward());
    }
    return count;
  }

  // counts the value of the hand stored in the list (but only the
  // cards facing up). Each card 2-10 have their face value. J, Q and K are worth
  // 10 points each. A is worth 11 points (this is a simplification of the
  // traditional Blackjack rules).
  int HandOfCards::count()
  {
    int count = 0;
    if (list->goto_head())
    {
      //Iterate through the entire deck
      do
      {
        if (list->get_current().is_face_up()) { count += list->get_current().get_value(); }
      } while (list->forward());
    }
    return count;
  }
  
  // makes all cards face-up.
  // Overloaded output operator (i.e. ‘<<’) outputs the content of the
  // HandOfCards in a form suitable for printing. Hint: This method should
  // use string value() in its implementation.
  void HandOfCards::faceUp()
  {
    //If there is something stored in the head (avoids dereferencing NULL ptr)
    if (list->goto_head())
    {
      //Iterate through the entire deck, setting all cards face up
      do {
        //TO-DO: FIX THIS!, shouldnt need to copy twice to flip a card!
        Card temp = list->get_current();
        temp.set_face_up();
        list->set_current(temp);
      } while (list->forward());
    }
  }

  // takes a single Card and a boolean
  // arguments and adds the card in HandOfCards, either facing-up (true) or
  // down (false).
  void HandOfCards::add(Card back, bool face_up) //TO-DO: Fix Face up/down!
  {
    if (face_up) { back.set_face_up(); }
    else { back.set_face_down(); }
    list->list_insert(back);
  }

  std::string HandOfCards::value() const
  {
    std::string output;

    //If there is something stored in the head
    if (list->goto_head())
    {
      do {
        //Iterate through the entire deck
        //Append each card name to output string, separated by a space
        if (list->get_current().is_face_up())
        {
          output += list->get_current().get_face() + " ";
        }
        else
        {
          output += "?-? ";
        }
      } while (list->forward());
    }
    return output;
  }

  //Override the cout operator
  std::ostream& operator<<(std::ostream& out, const HandOfCards& hand)
  {
   out << hand.value();
   return out;
  }
}