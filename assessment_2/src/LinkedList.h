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
    template <typename Object>
	class LinkedList
	{
	public:

        // Constructor
        // Precondition: None
        // Postcondition: Linked list object is instantiated
    	LinkedList();

        // Destructor
        // Precondition: Linked linked instance exists
        // Postcondition: Linked list object is deleted from memory
        ~LinkedList();

        // Precondition: current points to a node
        // Postcondition: Returns the number of elements in (length of) this linked list
    	size_t list_length() const;

        // Precondition: None
        // Postcondition: Returns the data stored at current
        Object get_current() const;

        // Precondition: current points to a node
        // Postcondition: The data stored in entry will be copied into this node data
        // param @entry 
        void set_current(const Object& entry);
        
        // Precondition: current points to a node to be removed from the list
        // Postcondition: This node is removed from the list with its memory freed;
        // current points to the next item in the list 
        bool remove();

        // Precondition: None
        // Postcondition: current points to the the node
        // stored at the n'th position on the list when traversing from head to tail
        // @param n The position on the list to traverse to
        // Function returns false if this pointer is NULL;
        // otherwise returns true
        bool goto_pos(const int n);

        // Precondition: None
        // Postcondition: current points to the head of the list.
        // Function returns false if head pointer is NULL;
        // otherwise returns true
        bool goto_head();

        // Precondition: None
        // Postcondition: current points to the tail of the list.
        // Function returns false if tail pointer is NULL;
        // otherwise returns true
        bool goto_tail();

        // Precondition: None
        // Postcondition: current points to the next item in the list.
        // Function returns false if the next link is NULL;
        // otherwise returns true
        bool forward();
        
        // Precondition: None
        // Postcondition: current points to the previous item in the list.
        // Function returns false if the previous link is NULL;
        // otherwise returns true
        bool back();

        // Precondition: None
        // Postcondition: Boolean returns true if list is Empty
        bool empty() const;

        // Precondition: current points to the node just before
        // the insertion position.
        // Postcondition: A new node containing entry is
        // inserted after the node pointed to by current;
        // current points to the new node
        void list_insert(const Object& entry);

        // Preconditions: None
        // Postconditions: Current points to the
        // first node storing the target, and true is
        // returned.
        // If not present, current is NULL and false is returned.
        // Uses cstdlib
        bool list_search(const Object& target);

        // Precondition: None
        // Postcondition: the list is emptied of all nodes;
        // (node memory is freed)
        void list_clear();
		

	private:
        // Private member varibles
        Node<Object>* head_ptr;
        Node<Object>* tail_ptr;
        Node<Object>* current_ptr;
        size_t list_len;
	};
}	
#include "LinkedList.template"
#endif