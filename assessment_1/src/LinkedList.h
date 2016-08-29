#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <string>


	class LinkedList
	{
		public:
		typedef std::string value_type;
		
		
		LinkedList();
		
		
		/*
		Node getHead();
		Node setHead(Node back);
		*/
		
		
		private:
		Node* head;
		Node* tail;
		Node* new_node;
		
	};
	
	
#endif