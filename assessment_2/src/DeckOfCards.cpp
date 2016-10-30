/**

SENG1120 Assignment 1
Created by Alex McClung
Semester 2 2016

**/

#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include "DeckOfCards.h"

namespace alex_m
{
  DeckOfCards::DeckOfCards()
  {

    list = new LinkedList<Card>();

    std::string suits[4] = {"S", "H", "C", "D"};
    std::string special_cards[4] = {"J", "Q", "K", "A"};
    std::string card_face;
    int card_value;

    // Generate the deck of cards
    for (int i=0; i<4; i++)
    {
      for (int j=2; j<15; j++)
      {
        //If we have a special card (J, Q, K, A)
        if (j > 10)
        {
          //A has value 11.
          //J, Q, K all have value 10.
          card_value = (j == 14 ? 11 : 10);
          card_face = special_cards[j-11];
        }
        else
        {
          std::stringstream ss;
          ss << j;
          card_face = ss.str();
          card_value = j;
        }

        //Concatenate the suit to the card face
        card_face += "-" + suits[i];
        Card new_card(card_face, card_value, false);

        push(new_card);
      }
    }
    //Shuffle in DeckOfCards constructor
    //As per assignment specifications
    shuffle();
  }

  //Destructor
  DeckOfCards::~DeckOfCards()
  {
    delete list;
  }

  void DeckOfCards::push(Card back)
  {
    list->goto_head();
    list->list_insert(back);

    // cout << list->get_current().get_face() << endl;
  }

  Card DeckOfCards::pop()
  { 
    list->goto_head();
    Card output = list->get_current();
    list->remove();
    return output;
  }

  void DeckOfCards::shuffle()
  {
  // Yates Shuffle Algorithm
  // -- To shuffle an array a of n elements (indices 0..n-1):
  // for i from n−1 downto 1 do
  //  j ← random integer such that 0 ≤ j ≤ i
  //  exchange a[j] and a[i]

    //Move the list "cursor" to the head of the list
    //Use if statement to avoid dereferencing a NULL ptr in an empty list
    if (list->goto_head())
    {
      // for i from n−1 downto 1 do
      for (int i = list->list_length()-1; i>0; i--)
      {
        //  j ← random integer such that 0 ≤ j ≤ i
        int j = (rand() % (i+1));
        // exchange a[j] and a[i]
        swap_cards(i, j);
      }
    }
  }

  int DeckOfCards::length() const
  {
    return int(list->list_length());
  }

  bool DeckOfCards::empty() const
  {
    return (list->list_length() > 0);
  }

  int DeckOfCards::position(std::string str) const
  {
    for (int i=0; i < (int)list->list_length(); i++)
    {
      list->goto_pos(i);
      //If item is found in list, return its location
      if (list->get_current().get_face() == str) { return i; }
    }
    //Otherwise return -1
    return -1;
  }

  bool DeckOfCards::remove(std::string str) const
  {
    int pos = position(str);

    if (pos > -1){ //If the card is in the list: remove it
      list->goto_pos(pos);
      list->remove();
    }
    return true;
  }

  void DeckOfCards::swap_cards(const int a_pos, const int b_pos)
  {
      //Get the data at position b
      list->goto_pos(b_pos);
      Card old_b_obj = list->get_current();

      //Get the data at position a
      list->goto_pos(a_pos);
      Card old_a_obj = list->get_current();

      //Give a the old b value
      list->goto_pos(a_pos);
      list->set_current(old_b_obj);

      //Give b the old a value
      list->goto_pos(b_pos);
      list->set_current(old_a_obj);
  }
        
  std::string DeckOfCards::value() const
  {
    std::string output;

    //If there is something stored in the head
    if (list->goto_head())
    {
      do {
        //Iterate through the entire deck
        //Append each card name to output string, separated by a space
        output += list->get_current().get_face() + " ";
        // std::cout << list->get_current().get_face() << endl;
      } while (list->forward());
    }

    return output;
  }

  //Override the cout operator
  std::ostream& operator<<(std::ostream& out, const DeckOfCards& deck)
  {
   out << deck.value();
   return out;
  }
}