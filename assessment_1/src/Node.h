/**

SENG1120 Assignment 1
Created by Alex McClung
Semester 2 2016

**/

#ifndef Node_H
#define Node_H

#include <string>

namespace alex_m
{
    class Node //For a doubly linked list
    {
    public:
        typedef std::string value_type;

        // Constructor
        // Precondition: None
        // Postcondition: A new node instance is created
        // @initial_data: Initial data to be stored in the node
        // @initial_prev_link: Initial pointer to the previous node in the list
        // @initial_next_link: Initial pointer to the next node in the list
        Node(const value_type& initial_data = value_type(), Node* initial_prev_link = NULL, Node* initial_next_link = NULL);

        // Destructor
        // Precondition: None
        // Postcondition: The node instance is deleted
        ~Node();

        // Precondition: None
        // Postcondition: The data stored within the node is set to @param new_data
        void set_data(const value_type& new_data);

        // Precondition: None
        // Postcondition: The next_link pointer is set to @param new_link
        void set_next_link(Node* new_link);

        // Precondition: None
        // Postcondition: The prev_link pointer is set to @param new_link
        void set_prev_link(Node* new_link);

        //Data stored in the node
        value_type data() const;

        //Points to the next node in the list
        Node* next_link() const;

        //Points to the previous node in the list
        Node* prev_link() const;

    private:
        value_type d;
        Node* prev;    
        Node* next;
    };
}
#endif