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
  // std::srand(std::time(nullptr));

 //    std::vector<int> elements { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

 //    std::cout << "Before: ";
 //    std::copy(elements.cbegin(), elements.cend(),
 //        std::ostream_iterator<int>(std::cout, " "));

 //    auto currentIndexCounter = elements.size();

 //    for (auto iter = elements.rbegin(); iter != elements.rend();
 //        iter++, --currentIndexCounter)
 //    {
 //        int randomIndex = std::rand() % currentIndexCounter;

 //        if (*iter != elements.at(randomIndex))
 //        {
 //            std::swap(elements.at(randomIndex), *iter);
 //        }
 //    }
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

  for (Node* current_ptr = linked_list->get_head_ptr(); current_ptr != NULL; current_ptr = current_ptr->get_next_link())
  {
    output += current_ptr->get_data() + " ";
  }

  return output;
}

std::ostream& operator<<(std::ostream& out, const DeckOfCards& deck)
{
 std::cout << deck.value() << std::endl;
}