#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include <string>

#include "LinkedList.h"

class DeckOfCards
{
  public:

    DeckOfCards();

    bool empty();
    bool remove(std::string str);

    int length();
    int position(std::string str);

    void shuffle();

    std::string value() const;
  
  private:
    LinkedList* linked_list;
};
  
#endif