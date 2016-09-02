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
// -- To shuffle an array a of n elements (indices 0..n-1):
// for i from n−1 downto 1 do
//  j ← random integer such that 0 ≤ j ≤ i
//  exchange a[j] and a[i]

  //linked_list->gotoPos(linked_list->list_length()-1);
  //std::cout << linked_list->getCurrent().data() << std::endl;

  if (linked_list->gotoHead())
  {
    for (int i = linked_list->list_length()-1; i>0; i--)
    {
      int j = (rand() % (i+1));

      //std::cout << i << " ";
      //std::cout << "Everyday I'm shuffling!" << "     List Length: " << linked_list->list_length() << " i: "<< i << " j: " << j << std::endl;

      //Perform a swap, TO-DO: TIDY UP THIS SECTION!!
      linked_list->gotoPos(j);
      Node::value_type old_j_val = linked_list->getCurrent().data();
      //std::cout << "Got old_j_val!: " << old_j_val << std::endl;

      linked_list->gotoPos(i);
      Node::value_type old_i_val = linked_list->getCurrent().data();
      //std::cout << "Got old_i_val!: " << old_i_val << std::endl;

      std::cout << "Before Swap:" << std::endl << "i: a[" << i << "] = " << old_i_val << std::endl << "j: a[" << j << "] = " << old_j_val << std::endl;

      linked_list->gotoPos(j);
      linked_list->updateCurrent(old_i_val);

      linked_list->gotoPos(i);
      linked_list->updateCurrent(old_j_val);

      //FOR DEBUGGING/////////////////////////////////////////////////
      linked_list->gotoPos(j);
      Node::value_type new_j_val = linked_list->getCurrent().data();

      linked_list->gotoPos(i);
      Node::value_type new_i_val = linked_list->getCurrent().data();

      std::cout << "After Swap:" << std::endl << "i: a[" << i << "] = " << new_i_val << std::endl << "j: a[" << j << "] = " << new_j_val << std::endl << std::endl;
      ////////////////////////////////////////////////////////////////
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