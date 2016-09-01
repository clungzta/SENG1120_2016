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
      // std::cout << " " << std::endl;
      // std::cout << i << ", " << j << std::endl;
      if (j >10)
      {
        card_name = special_cards[j-11] + "-" + suits[i];
      }
      else
      {
        card_name = std::to_string(j) + "-" + suits[i];
      }     
      linked_list->list_insert(card_name);
    }
  }
}

void DeckOfCards::shuffle()
{
// -- To shuffle an array a of n elements (indices 0..n-1):
// for i from n−1 downto 1 do
//  j ← random integer such that 0 ≤ j ≤ i
//  exchange a[j] and a[i]

  int blah[10] = {0,1,2,3,4,5,6,7,8,9};
  int n = (sizeof(blah)/sizeof(*blah));

  //linked_list->current_position();
  //int n = linked_list->length();

  if (linked_list->gotoHead())
  {
    for (int i = linked_list->list_length()-1; i>1; i--)
    {
      int j = (rand() % (int)(i + 1));

      // //Perform a swap, TO-DO: TIDY UP THIS SECTION!!
      // linked_list->gotoPos(j);
      // Node::value_type old_j_val = linked_list->current_ptr.data();

      // linked_list->gotoPos(i);
      // Node::value_type old_i_val = linked_list->current_ptr.data();

      // linked_list->gotoPos(j);
      // linked_list->current_ptr.set_data(old_i_val);

      // linked_list->gotoPos(i);
      // linked_list->current_ptr.set_data(old_j_val);
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