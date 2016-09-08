/**

SENG1120 Assignment 1
Created by Alex McClung
Semester 2 2016

**/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <string>

namespace alex_m
{
	class LinkedList
	{
		public:

		LinkedList();

    ~LinkedList();

		size_t list_length() const;

    Node get_current() const;


    void set_current(const Node::value_type& entry);
    
    bool remove();

    // Precondition: None
    // Postcondition: 'current_ptr' points to the the node
    // stored at the n'th position on the list when traversing from head to tail
    // @param n The position on the list to traverse to
    // Function returns false if this pointer is NULL, otherwise returns true
    bool goto_pos(const uint n);

    // Precondition: None
    // Postcondition: 'current_ptr' points to the head of the list.
    // Function returns false if head pointer is NULL, otherwise returns true
    bool goto_head();

    // Precondition: None
    // Postcondition: 'current_ptr' points to the tail of the list.
    // Function returns false if tail pointer is NULL, otherwise returns true
    bool goto_tail();

    // Precondition: None
    // Postcondition: 'current_ptr' points to the next item in the list.
    // Function returns false if the new value assigned to 'current_ptr' is NULL, otherwise returns true
    bool forward();
    
    // Precondition: None
    // Postcondition: 'current_ptr' points to the previous item in the list.
    // Function returns false if the new value assigned to 'current_ptr' is NULL, otherwise returns true
    bool back();

    // Precondition: None
    // Postcondition: Boolean returns true if list is Empty
    bool empty() const;

    // Precondition: current points to the node just before
    // the insertion position.
    // Postcondition: A new node is containing entry is
    // inserted after the node pointed to by current;
    // current points to the new node
    void list_insert(const Node::value_type& entry);

    // Preconditions: None
    // Postconditions: Current points to the
    // first node storing the target, and true is
    // returned.
    // If not present, current is NULL and false is returned.
    // Uses cstdlib
    bool list_search(const Node::value_type& target);

    // Precondition: None
    // Postcondition: the list is empty and
    // head_ptr and tail_prt are both NULL
    void list_clear();
		

		private:
			Node* head_ptr;
			Node* tail_ptr;
			Node* current_ptr;
      size_t list_len;
	};
}	
	
#endif