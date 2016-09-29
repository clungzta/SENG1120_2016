/**

SENG1120 Assignment 1
Created by Alex McClung
Semester 2 2016

**/

#include "Node.h"
#include "LinkedList.h"
#include <string>
#include <iostream>

using namespace std;
namespace alex_m
{

  // Constructor
  LinkedList::LinkedList()
  {
    //Initialise member variables
    head_ptr = NULL;
    tail_ptr = NULL;
    current_ptr = NULL;
    list_len = 0;
  }

  // Destructor
  LinkedList::~LinkedList()
  {
    //Clear the entire list
    list_clear();
  }

  size_t LinkedList::list_length() const
  {
    return list_len;
  }

  Object LinkedList::get_current() const
  {
    //Derefrerence and return the current ptr
    return current_ptr->data();
  }

  void LinkedList::set_current(const Object& entry)
  {
    //Set the value of the current ptr
    current_ptr->set_data(entry);
  }

  bool LinkedList::remove()
  {
    if (current_ptr == NULL)
    { 
      return false; //Avoid dereferencing a NULL ptr
    }
    else if (current_ptr == head_ptr) 
    { 
      //Removing from the head of the list
      head_ptr = current_ptr->next_link();
      if (head_ptr != NULL) { head_ptr->set_prev_link(NULL); }
    } 
    else if (current_ptr == tail_ptr)
    {
      //Removing from the tail of the list
      tail_ptr = current_ptr->prev_link();
      tail_ptr->set_next_link(NULL);
    }
    else 
    {
      //Removing from somewhere in the middle of the list
      current_ptr->prev_link()->set_next_link(current_ptr->next_link());
      current_ptr->next_link()->set_prev_link(current_ptr->prev_link());
    }

    Node* temp_ptr = current_ptr->next_link();

    delete current_ptr; // Free the memory used by the current Node Object
    current_ptr = temp_ptr; // Move the current pointer to the next item in the list
    list_len--;
    return true;
  }

  bool LinkedList::goto_pos(const int n)
  {
    //Avoid out of bounds error
    if (n > list_length()-1) {return false;}

    goto_head();

    //Traverse the list from head to tail param @n times
    for (int i=0; i<n; i++) { forward(); }
    return true;
  }

  bool LinkedList::goto_head()
  {
    //Set the current ptr to the head of the list
    if (head_ptr != NULL) { current_ptr = head_ptr; return true; }
    else { return false; }
  }

  bool LinkedList::goto_tail()
  {
    //Set the current ptr to the tail of the list
    if (tail_ptr != NULL) { current_ptr = tail_ptr; return true; }
    else { return false; }
  }

  bool LinkedList::forward()
  {
    //If the next link isn't NULL, move current_ptr "forward" (head to tail) by one link
    if (current_ptr->next_link() != NULL)
    {
      current_ptr = current_ptr->next_link();
      return true;
    }
    else
    {
      return false; //Next link is null, return false
    }
  }

  bool LinkedList::back()
  {
    //If the previous link isn't NULL, move current_ptr "back" by one link
    if (current_ptr->prev_link() != NULL)
    {
      current_ptr = current_ptr->prev_link();
      return true;
    }
    else
    {
      return false; //Previous link is null, return false
    }
  }

  void LinkedList::list_insert(const Object& entry)
  {
    Node* add_ptr = new Node(entry, NULL, NULL);

    if (head_ptr == NULL)
    {
      //Nothing at the head, so insert at the head of the list
      head_ptr = add_ptr;
    }
    else
    {
      //Otherwise insert just after current_ptr
      add_ptr->set_prev_link(current_ptr);
      add_ptr->set_next_link(current_ptr->next_link());
      current_ptr->set_next_link(add_ptr);
    }

    //Update the tail_ptr if necessary
    if (current_ptr == tail_ptr) { tail_ptr = add_ptr; }

    current_ptr = add_ptr;
    list_len++;

    cout << "inserted" << (*)add_ptr << endl;
  }

  bool LinkedList::empty() const
  {
    //Returns true if the list is empty
    return (list_length() > 0);
  }

  bool LinkedList::list_search(const Object& target)
  {
    //Searches the list for a node containing data param @target
    for (current_ptr = head_ptr; current_ptr != NULL; current_ptr = current_ptr->next_link())
    {
      if (target == current_ptr->data()) return true;
    }

    return false;
  }

  void LinkedList::list_clear()
  {
    //Delete all nodes in the list by traversing the entire list
    while (head_ptr != NULL)
    {
      goto_head();
      remove();
    }
    list_len = 0;
  }
}