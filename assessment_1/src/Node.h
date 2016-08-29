/*
Assignment 1 - Created by Alex McClung for SENG1120
Semester 2 2016
*/

#ifndef Node_H
#define Node_H

#include <string>

class Node
{
public:
    typedef std::string value_type;

    //Constructor
    Node(const value_type& initial_data = value_type(), Node* initial_link = NULL);

    void set_data(const value_type& new_data);
    void set_link(Node* new_link);

    value_type get_data() const;
    const Node* get_next_link() const;
    const Node* get_prev_link() const;    
    Node* link();

private:
    value_type data;
    Node* prev;    
    Node* next;
};

#endif