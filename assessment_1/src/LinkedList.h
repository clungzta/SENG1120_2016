#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <string>


	class LinkedList
	{
		public:
		typedef std::string value_type;
		
		
		LinkedList();
		
		Node getHead();
		Node setHead(Node back);

		size_t list_length();

    void list_head_insert(const Node::value_type& entry);
    void list_insert(const Node::value_type& entry);

    bool list_search(const Node::value_type& target);
    void list_head_remove();
    void list_clear();
		
		
		private:
			Node* head_ptr;
			Node* tail_ptr;
			Node* current_ptr;
      size_t list_len;
	};
	
	
#endif