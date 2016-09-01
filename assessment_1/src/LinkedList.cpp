#include "Node.h"
#include "LinkedList.h"
#include <string>
#include <iostream>

using namespace std;

// Constructor Function
LinkedList::LinkedList()
{
  head_ptr = NULL;
  tail_ptr = NULL;
  current_ptr = NULL;
}

size_t LinkedList::list_length()
{
  return list_len;
}

void LinkedList::list_head_insert(const Node::value_type& entry)
// Precondition: None
// Postcondition: A new node storing the
// supplied entry is created and linked in to be
// the new head of the linked list
{
  head_ptr = new Node(entry);
  // The following is required if a tail pointer is
  // used. It deals with adding to an empty list
  if (tail_ptr == NULL) tail_ptr = head_ptr;
  list_len++;
}

void LinkedList::list_tail_insert(const Node::value_type& entry)
// Precondition: None
// Postcondition: A new node storing the
// supplied entry is created and linked in to be
// the new tail of the linked list
{
  Node* entry_ptr = new Node(entry);
  if (tail_ptr != NULL) tail_ptr->set_next_link(entry_ptr);
  
  tail_ptr = entry_ptr;
  list_len++;
}

void LinkedList::list_insert(const Node::value_type& entry)
// Precondition: current points to the node just before
// the insertion position
// Postcondition: A new node is containing entry is
// inserted after the node pointed to by current;
// current points to the new node
{
  if (head_ptr == NULL)
  {
    //If there is nothing in the linked list
    //Add the entry to the list head 
    list_head_insert(entry);
    current_ptr = head_ptr;
    tail_ptr = current_ptr->get_next_link();
  }

  else
  {
    //Otherwise insert after node pointed to by current
    Node* add_ptr = new Node();
    add_ptr->set_data(entry);
    add_ptr->set_next_link(current_ptr->get_next_link());
    current_ptr->set_next_link(add_ptr);
    tail_ptr = current_ptr->get_next_link();
  }

  list_len++;
}

Node LinkedList::setHead(Node new_head)
{
  head_ptr = &new_head;
  list_len; //= ?
}

Node LinkedList::getHead()
{
  return *head_ptr;
}

Node* LinkedList::get_head_ptr()
{
  return head_ptr;
}

bool LinkedList::list_search(const Node::value_type& target)
// Preconditions: None
// Postconditions: Current points to the
// first node storing the target, and true is
// returned.
// If not present, current is NULL and false is returned.
// Uses cstdlib
{
  for (current_ptr = head_ptr; current_ptr != NULL; current_ptr = current_ptr->get_next_link())
  {
    if (target == current_ptr->get_data()) return true;
  }

  return false;
}

void LinkedList::list_head_remove()
// Precondition: the list is not empty
// Postcondition: The first Node is removed and
// returned to the heap
{
  Node* temp_ptr;
  temp_ptr = head_ptr;
  head_ptr = head_ptr->get_next_link();
  if (head_ptr != NULL) {head_ptr->set_next_link(NULL);}
  else {tail_ptr = NULL;} // list is empty, update tail
  delete temp_ptr; // Free the Node’s space
  list_len--;
}

void LinkedList::list_clear()
{
  // Precondition: None
  // Postcondition: the list is empty and
  // head_ptr and tail_prt are both NULL
  while (head_ptr != NULL) list_head_remove();
  list_len = 0;
}