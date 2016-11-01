/**

SENG1120 Assignment 1
Created by Alex McClung
Semester 2 2016

**/

#ifndef BTree_H
#define BTree_H

#include "BTNode.h"
#include "BTree.h"
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

    bool remove(const Object& entry);
    bool remove(BTNode<Object>* node_to_remove, const Object& entry);
    bool goto_root();
    bool goto_left();
    bool goto_right();
    bool goto_parent();
    void tree_insert(const Object& entry);
    bool empty() const;
    bool tree_search(const Object& target);
    void tree_clear();

    std::string inOrder(); // Make generic with function ptr?
    std::string inOrder(BTNode<Object>* node); // Make generic with function ptr?

    std::string toString();
    std::string toString(BTNode<Object>* node, size_t level);

    size_t countInRange(BTNode<Object>* node, int low, int high);
    size_t countInRange(int low, int high);

    float average();

    template <typename Predicate>
    void removeif(Predicate p);
	private:
    // Private member varibles
    BTNode<Object>* root_;
    BTNode<Object>* current_ptr;

    template <typename Predicate>
    void removeif(BTNode<Object>* node, Predicate p);

    BTNode<Object>* find_min(BTNode<Object>* node);
    float average(BTNode<Object>* node); // Move to Classroom of students

    void add(BTNode<Object>* node, Object it); // Helper function
    size_t size;
	};
}	
#include "BTree.template"
#endif