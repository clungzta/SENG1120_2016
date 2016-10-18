/**

SENG1120 Assignment 1
Created by Alex McClung
Semester 2 2016

**/

#ifndef BTree_H
#define BTree_H

#include "BTNode.h"
#include <string>

namespace alex_m
{
  template <typename Object>
	class BTree
	{
	public:

    // Constructor
    BTree();

    // Destructor
    ~BTree();

    size_t tree_count() const;

    Object get_current() const;
    void set_current(const Object& entry);
    bool remove();
    bool goto_root();
    bool goto_left();
    bool goto_right();
    bool goto_parent();
    void tree_insert(const Object& entry);
    bool empty() const;
    bool tree_search(const Object& target);
    void tree_clear();

	private:
    // Private member varibles
    BTNode<Object>* root;
    BTNode<Object>* current_ptr;
    void add(BTNode<Object> node, Object it); // Helper function
    size_t size;
	};
}	
#include "BTree.template"
#endif