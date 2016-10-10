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
	// template <typename Object>
	// Node<Object>::Node(const Object& initial_data /*=Object()*/, Node<Object>* initial_prev_link /*=NULL*/, Node<Object>* initial_next_link /*=NULL*/)
	// {
	// 	d = initial_data;
	// 	prev = initial_prev_link;	
	// 	next = initial_next_link;
	// }

	//Constructor has default arguments, these are specified in the header definition
	template <typename Object>
	Node<Object>::Node()
	{

	}

	template <typename Object>
	Node<Object>::~Node()
	{
		next = NULL;
		prev = NULL;
	}

	template <typename Object>
	void Node<Object>::set_data(const Object& new_data)
	{
		d = new_data;
	}

	template <typename Object>
	void Node<Object>::set_next_link(Node* new_link)
	{
		next = new_link;
	}

	template <typename Object>
	void Node<Object>::set_prev_link(Node* new_link)
	{
		prev = new_link;
	}

	template <typename Object>
	Object Node<Object>::data() const
	{
		return d;
	}

	template <typename Object>
	Node<Object>* Node<Object>::prev_link() const
	{
		return prev;
	}

	template <typename Object>
	Node<Object>* Node<Object>::next_link() const
	{
		return next;
	}
}