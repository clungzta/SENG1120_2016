#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include <string>
#include "LinkedList.h"

class DeckOfCards
{
  public:
    //Constructor
    DeckOfCards();
    //Destructor
    ~DeckOfCards();

    bool empty();
    bool remove(std::string str);

    int length();
    int position(std::string str);

    void shuffle();

    std::string value() const;
  
  private:
    void swap_cards(const uint a, const uint b);
    LinkedList* linked_list;
};
  
#endif