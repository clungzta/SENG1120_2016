/*
Assignment 1 - Created by Alex McClung for SENG1120
Semester 2 2016
*/

#include "Node.h"
#include <string>
//Constructor

Node::Node(const value_type& initial_data /*=value_type()*/, Node* initial_prev_link /*=NULL*/, Node* initial_next_link /*=NULL*/)
//Node::Node()
{
	data = initial_data;
	prev = initial_prev_link;	
	next = initial_next_link;
}

void Node::set_data(const value_type& new_data)
{
	data = new_data;
}

void Node::set_next_link(Node* new_link)
{
	next = new_link;
}

Node::value_type Node::get_data() const
{
	return data;
}

Node* Node::get_prev_link() const
{
	return prev;
}

Node* Node::get_next_link() const
{
	return next;
}

// ostream& operator<<(ostream& out, const data& d, const prev& p, const data& n)
// {
// 	cout << "Data stored within node: " << d << endl;
// 	cout << "Previous link: " << p << " Next "
// }