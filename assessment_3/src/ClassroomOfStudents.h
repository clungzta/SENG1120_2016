/**

SENG1120 Assignment 3
Created by Alex McClung, 3256853
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

      /**
       * @brief      { function_description }
       *
       * @param      student_names  The student names
       */
      ClassroomOfStudents(std::list<std::string>& student_names);


      /**
       * @brief      Destroys the object.
       */
      ~ClassroomOfStudents();

      /**
       * @brief      { function_description }
       *
       * @return     { description_of_the_return_value }
       */
      std::string value() const;

      /**
       * @brief      Gets the average grade.
       *
       * @return     The average grade.
       */
      float get_average_grade() const;

      /**
       * @brief      Removes a failed.
       */
      void remove_failed() const;

      /**
       * @brief      Counts the number of High Distinction Grades.
       *
       * @return     Number of High Distinction Grades.
       */
      int countHDs() const;
    
    private:
      
      /**
       * @brief 
       *  Precondition: There are cards stored in the deck
       *  Postcondition: The positions of these cards are randomized using the yates shuffle algorithm
       */
      void shuffle_names();
      
      /**
       * Std List to contain the student names prior to placing in tree
       */
      std::list<std::string> names;
      
      /**
       * Binary search tree (BST), to store Students objects ordered by name
       */
      BTree<Student>* btree;
  };

  /**
   * @brief      Overload the cout operator
   *
   * @param      out        The out
   * @param[in]  classroom  The classroom
   *
   * @return     { description_of_the_return_value }
   */
  std::ostream& operator<<(std::ostream& out, const ClassroomOfStudents& classroom);
}
#endif