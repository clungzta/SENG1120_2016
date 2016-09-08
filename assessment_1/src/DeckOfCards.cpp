#include <string>
#include <iostream>
#include "DeckOfCards.h"

DeckOfCards::DeckOfCards()
{
  linked_list = new LinkedList();

  std::string suits[4] = {"S", "H", "C", "D"};
  std::string special_cards[4] = {"J", "Q", "K", "A"};
  std::string card_name;

  // Generate the deck of cards
  for (int i=0; i<4; i++)
  {
    for (int j=2; j<15; j++)
    {
      card_name = (j > 10 ? special_cards[j-11] : std::to_string(j)) + "-" + suits[i];
      linked_list->list_insert(card_name);
    }
  }
}

//Destructor
DeckOfCards::~DeckOfCards()
{
  //linked_list();
}

void DeckOfCards::shuffle()
{
// Yates Shuffle Algorithm
// -- To shuffle an array a of n elements (indices 0..n-1):
// for i from n−1 downto 1 do
//  j ← random integer such that 0 ≤ j ≤ i
//  exchange a[j] and a[i]

  //Move the linked_list "cursor" to the head of the list
  //Use if statement to avoid dereferencing a NULL ptr in an empty list
  if (linked_list->goto_head())
  {
    for (int i = linked_list->list_length()-1; i>0; i--)
    {
      uint j = (rand() % (i+1));
      swap_cards(i, j);
    }
  }
}

int DeckOfCards::length()
{
  return int(linked_list->list_length());
}

bool DeckOfCards::empty()
{
  return (linked_list->list_length() > 0);
}

int DeckOfCards::position(std::string str)
{
  for (int i=0; i < linked_list->list_length(); i++)
  {
    linked_list->goto_pos(i);
    //If item is found in list, return its location
    if (linked_list->get_current().data() == str) { return i; }
  }
  //Otherwise return -1
  return -1;
}

bool DeckOfCards::remove(std::string str)
{
  int pos = position(str);

  //std::cout << "removing " << str << " at position " << pos << std::endl;

  linked_list->goto_pos(pos);
  linked_list->remove();
}

void DeckOfCards::swap_cards(const uint a_pos, const uint b_pos)
{
    linked_list->goto_pos(b_pos);
    Node::value_type old_b_val = linked_list->get_current().data();

    linked_list->goto_pos(a_pos);
    Node::value_type old_a_val = linked_list->get_current().data();

    linked_list->goto_pos(a_pos);
    linked_list->set_current(old_b_val);

    linked_list->goto_pos(b_pos);
    linked_list->set_current(old_a_val);
}
      
std::string DeckOfCards::value() const
{
  std::string output;

  //If there is something stored in the head
  if (linked_list->goto_head())
  {
    do {
      output += linked_list->get_current().data() + " ";
    } while (linked_list->forward());
  }

  return output;
}

std::ostream& operator<<(std::ostream& out, const DeckOfCards& deck)
{
 out << deck.value();
 return out;
}