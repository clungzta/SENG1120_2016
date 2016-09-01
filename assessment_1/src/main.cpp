/*
Assignment 1 - Created by Alex McClung for SENG1120
Semester 2 2016
*/

#include <iostream>
#include <cstdlib>
#include "DeckOfCards.h"

using namespace std;

int main()
{
  DeckOfCards* deck = new DeckOfCards();
  cout << deck->length() << endl;
  cout << deck << endl;  

  // for (int i=0;i<100;i++)
  // {
  //  string str = std::to_string(l1->list_length());
  //  l1->list_insert(str);
  //  cout << str << " stored at: " << l1->list_length()-1 << endl;
  // }

  // cout << "done!" << endl;

  // if (l1->list_search("69")) {cout << "found 69!!!" << endl;}

  // l1->list_clear();

  //cout << "Zesty dek of cardz" << endl;
}