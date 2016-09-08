#include "Node.h"
#include "LinkedList.h"
#include <string>
#include <iostream>

using namespace std;

// Constructor
LinkedList::LinkedList()
{
  head_ptr = NULL;
  tail_ptr = NULL;
  current_ptr = NULL;
  list_len = 0;
}

// Destructor
LinkedList::~LinkedList()
{
  goto_head();
  while (remove());
}

size_t LinkedList::list_length()
{
  return list_len;
}

Node LinkedList::get_current()
{
  return *current_ptr;
}

void LinkedList::set_current(const Node::value_type& entry)
{
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
    //Removing from head
    head_ptr = current_ptr->next_link();
    head_ptr->set_prev_link(NULL);
  } 
  else if (current_ptr == tail_ptr)
  {
    //Removing from tail
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

bool LinkedList::goto_pos(const uint n)
{
  //List length should = 51 for full deck
  //Avoid out of bounds error
  if (n > list_length()-1) {return false;}

  goto_head();

  for (int i=0; i<n; i++) { forward(); }
  return true;
}

bool LinkedList::goto_head()
{
  if (head_ptr != NULL) { current_ptr = head_ptr; return true; }
  else { return false; }
}

bool LinkedList::goto_tail()
{
  if (tail_ptr != NULL) { current_ptr = tail_ptr; return true; }
  else { return false; }
}

bool LinkedList::forward()
{
  if (current_ptr->next_link() != NULL)
  {
    current_ptr = current_ptr->next_link();
    return true;
  }
  else
  {
    return false;
  }
}

bool LinkedList::back()
{
  if (current_ptr->prev_link() != NULL)
  {
    current_ptr = current_ptr->prev_link();
    return true;
  }
  else
  {
    return false;
  }
}

void LinkedList::list_insert(const Node::value_type& entry)
{
  Node* add_ptr = new Node;

  add_ptr->set_data(entry);

  if (head_ptr == NULL)
  {
    head_ptr = add_ptr;
  }
  else
  {
    add_ptr->set_prev_link(current_ptr);
    add_ptr->set_next_link(current_ptr->next_link());
    current_ptr->set_next_link(add_ptr);
  }

  if (current_ptr == tail_ptr) { tail_ptr = add_ptr; }

  current_ptr = add_ptr;
  list_len++;
}

bool LinkedList::empty()
{
  return (list_length() > 0);
}

bool LinkedList::list_search(const Node::value_type& target)
{
  for (current_ptr = head_ptr; current_ptr != NULL; current_ptr = current_ptr->next_link())
  {
    if (target == current_ptr->data()) return true;
  }

  return false;
}

void LinkedList::list_clear()
{
  while (head_ptr != NULL)
  {
    goto_head();
    remove();
  }
  list_len = 0;
}