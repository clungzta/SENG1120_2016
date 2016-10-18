/**

SENG1120 Assignment 1
Created by Alex McClung
Semester 2 2016

**/

#ifndef Node_H
#define Node_H

#include "Student.h"
#include <string>

namespace alex_m
{
    template <typename Object>
    class BTNode //For a doubly linked list
    {
    public:

        // Constructor
        // Precondition: None
        // Postcondition: A new node instance is created
        // @initial_data: Initial data to be stored in the node. Default Empty Object
        // @initial_prev_link: Initial pointer to the previous node in the list. Default NULL
        // @initial_next_link: Initial pointer to the next node in the list. Default NULL
        BTNode();
        // BTNode(const Object& initial_data = Object(), BTNode* initial_prev_link = NULL, BTNode* initial_next_link = NULL);

        // Destructor
        // Precondition: None
        // Postcondition: The node instance is deleted
        ~BTNode();

        // Precondition: None
        // Postcondition: The data stored within the node is set to @param new_data
        void set_data(const Object& new_data);

        // Precondition: None
        // Postcondition: The next_link pointer is set to @param new_link
        void set_next_link(BTNode* new_link);

        // Precondition: None
        // Postcondition: The prev_link pointer is set to @param new_link
        void set_prev_link(BTNode* new_link);

        //Data stored in the node
        Object data() const;

        //Points to the next node in the list
        BTNode* next_link() const;

        //Points to the previous node in the list
        BTNode* prev_link() const;

    private:
        Object d;
        BTNode* prev;    
        BTNode* next;
    };
}
#include "BTNode.template"
#endif