/**

SENG1120 Assignment 1
Created by Alex McClung
Semester 2 2016

**/

#include "Node.h"
#include <string>
//Constructor

namespace alex_m
{
	//Constructor has default arguments, these are specified in the header definition
	Node::Node(const value_type& initial_data /*=value_type()*/, Node* initial_prev_link /*=NULL*/, Node* initial_next_link /*=NULL*/)
	{
		d = initial_data;
		prev = initial_prev_link;	
		next = initial_next_link;
	}

	Node::~Node()
	{
		next = NULL;
		prev = NULL;
	}

	void Node::set_data(const value_type& new_data)
	{
		d = new_data;
	}

	void Node::set_next_link(Node* new_link)
	{
		next = new_link;
	}

	void Node::set_prev_link(Node* new_link)
	{
		prev = new_link;
	}

	Node::value_type Node::data() const
	{
		return d;
	}

	Node* Node::prev_link() const
	{
		return prev;
	}

	Node* Node::next_link() const
	{
		return next;
	}
}