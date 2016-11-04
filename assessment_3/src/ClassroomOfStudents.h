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
       * @brief      ClassroomOfStudents constructor
       * 
       * Precondition: List of student name strings exists
       * Postcondition: Binary Search Tree is created from the list of student names,
       * With each student given a random grade
       *
       * @param      student_names  List of student names to add to the tree
       */
      ClassroomOfStudents(std::list<std::string>& student_names);


      /**
       * @brief      Destroys the ClassroomOfStudents object.
       * Precondition: ClassroomOfStudents object is instantiated.
       * Postcondition: ClassroomOfStudents object is destroyed.
       */
      ~ClassroomOfStudents();

      /**
       * @brief      A string of all students in classroom with their respective grades
       * 
       * @details
       * Precondition: Student objects are stored in the tree.
       * Postcondition: The students and their grades are printed in the format:
       * "(name1, grade1) (name2, grade2) … (nameN, gradeN)"
       *
       * @return     A string of all students in classroom with their respective grades
       */
      std::string value() const;

      /**
       * @brief      Gets the average grade of the classroom.
       * 
       * @details    
       * Precondition: Students are stored in the tree
       * Postcondition: The average grade of the classroom is returned
       *
       * @return     The average grade of the classroom.
       */
      float get_average_grade() const;

      /**
       * @brief      Removes all failed grades from the classroom.
       * 
       * @details
       * Precondition: Students are stored in the tree.
       * Postcondition: Failed students (grade < 50) are deleted from the tree.
       */
      void remove_failed() const;

      /**
       * @brief      Counts the number of High Distinction Grades.
       *
       * @details
       * Precondition: Students are stored in the tree.
       * Postcondition: The number of High Distinction grades are counted
       *
       * @return     The number of High Distinction Grades in the classroom.
       */
      int countHDs() const;
    
    private:
      
      /**
       * @brief Shuffles a std::list of student names
       * 
       * @details
       * Precondition: Unshuffled list of student name strings is passed as a parameter
       * Postcondition: The positions of these cards are randomized using the yates shuffle algorithm
       * 
       * @param[in]  names  Unshuffled linkedlist of student names.
       * @return     Shuffled linkedlist of student names.
       */
      std::list<std::string> shuffle_names(std::list<std::string> names);
      
      /**
       * Binary search tree (BST), to store Students objects ordered by name
       */
      BTree<Student>* btree;
  };

  /**
   * @brief      Overload the cout operator for ClassroomOfStudents
   *
   * @param      out        The cout output stream object
   * @param[in]  classroom  The ClassroomOfStudents Object to be serialized
   *
   * @return     Output stream
   */
  std::ostream& operator<<(std::ostream& out, const ClassroomOfStudents& classroom);
}
#endif