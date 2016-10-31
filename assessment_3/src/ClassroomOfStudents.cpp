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
  ClassroomOfStudents::ClassroomOfStudents(std::list<std::string>& student_names)
  {  
    names = student_names;
    shuffle_names();

    btree = new BTree<Student>();

    std::list<std::string>::const_iterator student_name_iterator;
    for (student_name_iterator = names.begin(); student_name_iterator != names.end(); ++student_name_iterator)
    {
      float grade = float(rand() % 101);

      Student* a_student = new Student();
      a_student->set_grade(grade);
      a_student->set_name(*student_name_iterator);
      btree->tree_insert(*a_student);
    }

    btree->goto_root();

    cout << btree->toString();

    cout << btree->goto_root();
    cout << " root node: " << btree->get_current() << endl;

    cout << btree->goto_left() << " left of root node: ";
    cout << btree->get_current() << endl;

    cout << btree->goto_root() << " root node: ";
    cout << btree->get_current() << endl;

    cout << btree->goto_right() << endl;
    cout << " right of root node: " << btree->get_current() << endl;

    cout << btree->goto_root();
    cout << " root node: " << btree->get_current() << endl;

    cout << btree->goto_right() << endl;
    cout << " right of root node: " << btree->get_current() << endl;

    cout << btree->goto_parent();
    cout << " back to root node (using goto_parent()): " << btree->get_current() << endl;
    
    // cout << btree->goto_parent() << " abcdefg! " << btree->get_current() << endl;

    btree->get_current();



    cout << btree->inOrder() << endl;

    Student* new_student = new Student();
    new_student->set_name("Hugh");
    // btree->remove(*new_student);
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
}