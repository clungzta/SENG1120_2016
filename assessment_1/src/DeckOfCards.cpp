#include <string>
#include <iostream>
#include "DeckOfCards.h"

DeckOfCards::DeckOfCards()
{
  linked_list = new LinkedList();

  std::string suits[4] = {"S", "H", "C", "D"};
  std::string special_cards[4] = {"J", "Q", "K", "A"};

  std::string card_name;

  bool first_loop = true;

  // Generate the deck of cards
  for (int i=0; i<4; i++)
  {
    for (int j=2; j<15; j++)
    {
      //std::cout << " " << std::endl;
      //std::cout << i << ", " << j << std::endl;
      if (j >10)
      {
        card_name = special_cards[j-11] + "-" + suits[i];
      }
      else
      {
        card_name = std::to_string(j) + "-" + suits[i];
      }

      if (first_loop) {
        linked_list->list_head_insert(card_name);
        first_loop = false;
        linked_list->gotoHead();
        std::cout << "Head inserted!" << std::endl;
      }
      else
      {
        linked_list->list_insert(card_name);
      }
      
      //std::cout << card_name << std::endl;
    }
  }
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
  if (linked_list->gotoHead())
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

}

bool DeckOfCards::remove(std::string str)
{

}

void DeckOfCards::swap_cards(const uint a, const uint b)
{
    linked_list->gotoPos(b);
    Node::value_type old_b_val = linked_list->getCurrent().data();

    linked_list->gotoPos(a);
    Node::value_type old_a_val = linked_list->getCurrent().data();

    //std::cout << "Before Swap:" << std::endl << "i: linked_list[" << a << "] = " << old_a_val << std::endl << "j: linked_list[" << b << "] = " << old_b_val << std::endl;
    linked_list->gotoPos(a);
    linked_list->updateCurrent(old_b_val);

    linked_list->gotoPos(b);
    linked_list->updateCurrent(old_a_val);

    //FOR DEBUGGING/////////////////////////////////////////////////
    linked_list->gotoPos(a);
    Node::value_type new_a_val = linked_list->getCurrent().data();

    linked_list->gotoPos(b);
    Node::value_type new_b_val = linked_list->getCurrent().data();
    //std::cout << "After Swap:" << std::endl << "i: linked_list[" << a << "] = " << new_a_val << std::endl << "j: linked_list[" << b << "] = " << new_b_val << std::endl << std::endl;
    ////////////////////////////////////////////////////////////////
}
      
std::string DeckOfCards::value() const
{
  std::string output;

  //If there is something stored in the head
  if (linked_list->gotoHead())
  {
    do {
      output += linked_list->getCurrent().data() + " ";
    } while (linked_list->forward());
  }

  return output;
}

std::ostream& operator<<(std::ostream& out, const DeckOfCards& deck)
{
 std::cout << deck.value() << std::endl;
}