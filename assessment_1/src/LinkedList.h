#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <string>


	class LinkedList
	{
		public:

		LinkedList();
		
		Node getHead();
		Node setHead(Node back);

    Node* get_head_ptr();

		size_t list_length();

    void list_head_insert(const Node::value_type& entry);
    void list_tail_insert(const Node::value_type& entry);
    void list_insert(const Node::value_type& entry);

    bool list_search(const Node::value_type& target);
    bool list_remove(const Node::value_type& target);

    void list_head_remove();
    void list_clear();
		
		private:
			Node* head_ptr;
			Node* tail_ptr;
			Node* current_ptr;
      size_t list_len;
	};
	
	
#endif