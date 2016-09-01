#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <string>


	class LinkedList
	{
		public:

		LinkedList();
		
		Node getHead();
		void setHead(Node back);

    Node getTail();
    void setTail(Node back);

    Node* get_head_ptr();  //DELET THIS!!!

		size_t list_length();

    Node getCurrent();
    void setCurrent(const Node&);
    void removeCurrent();

    Node removeFromHead();
    Node removeFromTail();

    bool removeFirstOccurance(const Node back);
    bool removeAllOccurances(const Node back);

    bool gotoPos(uint n);
    bool gotoHead();
    bool gotoTail();
    bool forward();
    bool back();

//////////////////////////RENAME THESE!////////////////////////////////////
    void list_head_insert(const Node::value_type& entry);
    void list_tail_insert(const Node::value_type& entry);
    void list_insert(const Node::value_type& entry);

    bool list_search(const Node::value_type& target);
    bool list_remove(const Node::value_type& target);

    void list_head_remove();
    void list_clear();
///////////////////////////////////////////////////////////////////////////
		
		private:
			Node* head_ptr;
			Node* tail_ptr;
			Node* current_ptr;
      size_t list_len;
	};
	
	
#endif