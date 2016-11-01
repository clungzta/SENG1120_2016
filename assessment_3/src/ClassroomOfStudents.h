/**

SENG1120 Assignment 1
Created by Alex McClung
Semester 2 2016

**/

#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include <string>
#include <list>
#include "Student.h"
#include "BTree.h"

namespace alex_m
{
  class ClassroomOfStudents
  {
    public:

      // Constructor
      // Precondition: None
      // Postcondition: A full deck of cards is generated.
      // The card names are stored in a LinkedList of string data.
      // Numbers are 2 to 10, plus J, Q, K, A. 
      // There are four cards of each suit, i.e. “S” = spades, “H” for hearts, “C” for clubs, “D” for diamonds
      ClassroomOfStudents(std::list<std::string>& student_names);

      // Destructor
      // Precondition: A DeckOfClass object is instansiated.
      // Postcondition: The list pointer (member variable) is deleted.
      // This frees the memory used by the list from the heap.
      ~ClassroomOfStudents();

      std::string value() const;

      float get_average_grade();

      void remove_failed();

      int countHDs();
    
    private:
      // Precondition: There are cards stored in the deck
      // Postcondition: The positions of these cards are randomized
      // using the yates shuffle algorithm
      void shuffle_names();

      //Std List to contain the student names prior to placing in tree
      std::list<std::string> names;

      //Std List to contain the student names prior to placing in tree
      BTree<Student>* btree;
  };

  //Override the cout operator
  std::ostream& operator<<(std::ostream& out, const ClassroomOfStudents& classroom);
}
#endif