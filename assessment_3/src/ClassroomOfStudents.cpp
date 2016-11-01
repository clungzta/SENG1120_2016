/**

SENG1120 Assignment 1
Created by Alex McClung
Semester 2 2016

**/

#include <string>
#include <iostream>
#include <cstdlib>
#include <list>
#include "ClassroomOfStudents.h"

namespace alex_m
{
  bool is_failed(Student s)
  {
    return (s.get_grade() < 50);
  }

  ClassroomOfStudents::ClassroomOfStudents(std::list<std::string>& student_names)
  {  
    names = student_names;
    shuffle_names();

    btree = new BTree<Student>();

    std::list<std::string>::const_iterator student_name_iterator;
    for (student_name_iterator = names.begin(); student_name_iterator != names.end(); ++student_name_iterator)
    {
      btree->tree_insert(Student(*student_name_iterator, float(rand() % 101)));
    }

    btree->goto_root();

    // cout << btree->toString() << endl;
  

    btree->goto_root();
    //cout << btree->toString() << endl << btree->tree_count() << endl;
  }

  //Destructor
  ClassroomOfStudents::~ClassroomOfStudents()
  {
    delete btree;
  }

  void ClassroomOfStudents::shuffle_names()
  {
  // Yates Shuffle Algorithm
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

        std::iter_swap(i_ptr, j_ptr);
      }
    }
  }

  float ClassroomOfStudents::get_average_grade()
  {
    return btree->average();
  }

  int ClassroomOfStudents::countHDs()
  {
    return btree->countInRange(85,100);  
  }

  void ClassroomOfStudents::remove_failed()
  {
    btree->removeif(is_failed);
  }

  std::string ClassroomOfStudents::value() const
  {
    return btree->inOrder();
  }

  std::ostream& operator<<(std::ostream& out, const ClassroomOfStudents& classroom)
  {
    out << classroom.value();
    return out;
  }
}