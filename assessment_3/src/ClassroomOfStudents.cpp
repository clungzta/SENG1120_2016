/**

SENG1120 Assignment 3
Created by Alex McClung, 3256853
Semester 2 2016

**/

#include <string>
#include <iostream>
#include <cstdlib>
#include <list>
#include "ClassroomOfStudents.h"

namespace alex_m
{

  ClassroomOfStudents::ClassroomOfStudents(std::list<std::string>& student_names)
  {  
    std::list<std::string> names = shuffle_names(student_names);

    btree = new BTree<Student>();

    //Create a binary tree by iterating over the (shuffled) list of students
    std::list<std::string>::const_iterator student_name_iterator;
    for (student_name_iterator = names.begin(); student_name_iterator != names.end(); ++student_name_iterator)
    {
      btree->tree_insert(Student(*student_name_iterator, float(rand() % 101)));
    }

    btree->goto_root();
  }

  //Destructor
  ClassroomOfStudents::~ClassroomOfStudents()
  {
    delete btree;
  }

  std::list<std::string> ClassroomOfStudents::shuffle_names(std::list<std::string> names)
  {
  // Yates Shuffle Algorithm (From assignment 1)
  // Adapted to use std::list
  // -- To shuffle an array a of n elements (indices 0..n-1):
  // for i from n−1 downto 1 do
  //  j ← random integer such that 0 ≤ j ≤ i
  //  exchange a[j] and a[i]

    //Move the list "cursor" to the head of the list
    //Use if statement to avoid dereferencing a NULL ptr in an empty list
    if (!names.empty())
    {
      // for i from n−1 downto 1 do
      for (int i = names.size()-1; i>0; i--)
      {
        //  j ← random integer such that 0 ≤ j ≤ i
        uint j = (rand() % (i+1));

        // exchange a[j] and a[i]
        std::list<std::string>::iterator it;
        it = names.begin();
        auto i_ptr = std::next(it, i);
        it = names.begin();
        auto j_ptr = std::next(it, j);
        // Maybe using std::vector would've been a better idea for this...

        std::iter_swap(i_ptr, j_ptr);
      }
    }
    return names;
  }

  float ClassroomOfStudents::get_average_grade() const
  {
    return btree->average();
  }

  int ClassroomOfStudents::countHDs() const
  {
    return btree->countInRange(85,100);  
  }

  std::string ClassroomOfStudents::value() const
  {
    return btree->inOrder();
  }

  // function passed in as a predicate, for recursive remove from tree
  bool is_failed(Student s) // Non class member!
  {
    return s.is_grade_in_range(0,50);
  }

  void ClassroomOfStudents::remove_failed() const
  {
    btree->removeif(is_failed); // Predicate function as argument
  }

  std::ostream& operator<<(std::ostream& out, const ClassroomOfStudents& classroom)
  {
    out << classroom.value();
    return out;
  }
}