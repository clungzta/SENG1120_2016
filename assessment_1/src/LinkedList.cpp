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

Node LinkedList::getCurrent()
{
  return *current_ptr;
}

void LinkedList::setCurrent(const Node&)
{

}

void LinkedList::updateCurrent(const Node::value_type& entry)
{
  current_ptr->set_data(entry);
}

void LinkedList::removeCurrent()
{

}

Node LinkedList::removeFromHead()
{

}

Node LinkedList::removeFromTail()
{

}

bool LinkedList::removeFirstOccurance(const Node back)
{
 
}

bool LinkedList::removeAllOccurances(const Node back)
{

}

bool LinkedList::gotoPos(uint n)
// Precondition: None
// Postcondition: 'current_ptr' points to the the node stored at the @nth position on the list
// Function returns false if this pointer is NULL, otherwise returns true
{
  //If head is not null, go to head
  if (gotoHead()) {
    for (int i=0; i<n; i++)
    {
      current_ptr = current_ptr->next_link();
    }
    return true;
  }

  else {
    return false;
  }
}

bool LinkedList::gotoHead()
// Precondition: None
// Postcondition: 'current_ptr' points to the head of the list.
// Function returns false if head pointer is NULL, otherwise returns true
{
  if (head_ptr != NULL) { current_ptr = head_ptr; return true; }
  else { return false; }
}

bool LinkedList::gotoTail()
// Precondition: None
// Postcondition: 'current_ptr' points to the tail of the list.
// Function returns false if tail pointer is NULL, otherwise returns true
{
  if (tail_ptr != NULL) { current_ptr = tail_ptr; return true; }
  else { return false; }
}

bool LinkedList::forward()
// Precondition: None
// Postcondition: 'current_ptr' points to the successive item in the list.
// Function returns false if next_link pointer is NULL, otherwise returns true
{
  Node* next_link = current_ptr->next_link();

  if (next_link != NULL) { current_ptr = next_link; return true; }
  else { return false; }
}

bool LinkedList::back()
// Precondition: None
// Postcondition: 'current_ptr' points to the preceding item in the list.
// Function returns false if prev_link pointer is NULL, otherwise returns true
{
  Node* prev_link = current_ptr->prev_link();

  if (prev_link != NULL) { current_ptr = prev_link; return true; }
  else { return false; }
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
  Node* add_ptr = new Node;
  add_ptr->set_data(entry);
  add_ptr->set_next_link(current_ptr->next_link());
  current_ptr->set_next_link(add_ptr);
  if (current_ptr == tail_ptr) {tail_ptr = current_ptr->next_link();}
  current_ptr = current_ptr->next_link();
  list_len++;
}

void LinkedList::setHead(Node new_head)
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
  for (current_ptr = head_ptr; current_ptr != NULL; current_ptr = current_ptr->next_link())
  {
    if (target == current_ptr->data()) return true;
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
  head_ptr = head_ptr->next_link();
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