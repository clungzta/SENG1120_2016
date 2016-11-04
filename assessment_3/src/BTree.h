/**

SENG1120 Assignment 3
Created by Alex McClung, 3256853
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
        /**
         * @brief      Constructor for binary tree.
         * @details
         * Precondition: None
         * Postcondition: Binary tree object initialized
         */
        BTree();

        // Destructor
        /**
         * @brief      Destroys the binary tree object.
         * Precondition: Binary tree object initialized
         * Postcondition: Binary tree object destroyed
         */
        ~BTree();


        /**
         * @brief      Function returning the number of nodes stored in the tree
         * 
         * @details
         * Precondition: None
         * Postcondition: The number of nodes stored in the tree is returned
         *
         * @return     The number of nodes stored in the tree
         */
        size_t tree_count() const;

        /**
         * @brief      Gets the node being pointed to by the cursor.
         * 
         * @details
         * Precondition: There is a node being pointed to by the cursor
         * Postcondition: The node being pointed to by the cursor is returned
         *
         * @return     The node being pointed to by the cursor
         */
        Object get_current() const;
        
        /**
         * @brief      Sets the Object stored at the cursor position.
         * 
         * @details
         * Precondition: There is a node being pointed to by the cursor
         * Postcondition: The value of this node is set to entry
         * 
         * @param[in]  entry  The entry to set the node at the cursor to
         */
        void set_current(const Object& entry) const;

        /**
         * @brief      Insert an entry into the binary tree
         *
         * @details
         * Precondition: None
         * Postcondition: An object is inserted into the binary tree 
         * at an appropriate position
         *
         * @param[in]  entry  The entry to insert into the binary tree
         */
        void tree_insert(const Object& entry);

        /**
         * @brief      Remove an node from the binary tree
         *
         * @param      node_to_remove  Pointer to the node to remove which will removed
         *
         * @return     true if this node was successfully removed from the tree
         */
        bool remove(BTNode<Object>* node_to_remove);

        /**
         * @brief Moves the cursor to the root node
         * 
         * @details
         * Precondition: None
         * Postcondition: The cursor is moved to the root node
         * 
         * @return true if the root node is not NULL
         */
        bool goto_root();
        
        /**
         * @brief Moves the cursor to the left child node
         * @details
         * Precondition: None
         * Postcondition: The cursor is moved to the left child node
         * 
         * @return true if the left child node is not NULL
         */
        bool goto_left();
        
        /**
         * @brief Moves the cursor to the right child node
         * 
         * @details
         * Precondition: None
         * Postcondition: The cursor is moved to the right child node
         * 
         * @return true if the right child node is not NULL
         */
        bool goto_right();
        
        /**
         * @brief Moves the cursor to the parent node
         * 
         * @details
         * Precondition: None
         * Postcondition: The cursor is moved to the parent node
         * 
         * @return true if the parent node is not NULL
         */
        bool goto_parent();
        
        /**
         * @brief Returns true if the tree is empty
         * @return true if the tree is empty
         */
        bool empty() const;

        /**
         * @brief      All Nodes are removed from the tree
         * 
         * @details
         * Precondition: None
         * Postcondition: The tree is emptied
         */
        void remove_all();

        /**
         * @brief      An inorder traversal of the tree, returning overloaded
         * string output of Objects in the tree.
         *
         * @return     A string containing all Objects in the tree.
         */
        std::string inOrder() const; 
        
        /**
         * @brief      Returns a string representation of the tree.
         *
         * @return     String representation of the tree.
         */
        std::string toString() const;


        // Functions below should be moved to ClassroomOfStudents to make a generic tree class...
        
        /**
         * @brief      Counts the number nodes in the tree which values lie in range [low, high].
         *
         * @param[in]  low   The low threshold
         * @param[in]  high  The high threshold
         *
         * @return     Number the number nodes in the tree which values lie in range [low, high]
         */
        size_t countInRange(int low, int high) const;

        /**
         * @brief      Gets the average value of all items in the tree
         *
         * @return     The average value of all items in the tree
         */
        float average() const;

        /**
         * @brief      Removes all nodes in the tree whose value meets the Predicate condition
         *
         * @param[in]  p    a predicate function, passed in to evaluate whether to remove a node from the tree
         *
         * @details
         * Precondition: None
         * Postcondition: Any object in the tree, whose value meets the predicate condition: is removed from the tree
         *
         * @tparam     Predicate  A function evaluated on all node values in the tree
         */
        template <typename Predicate> 
        void removeif(Predicate p);

	private:
        
        /**
         * ptr to the root node of the tree
         */
        BTNode<Object>* root_;
        
        /**
         * cursor, ptr to the node at the cursor position
         */
        BTNode<Object>* current_ptr;
        
        /**
         * the size of the tree in elements
         */
        size_t size;

        /**
         * @brief      Removes node from the tree if its value meets the Predicate condition
         *
         * @param      node       The node to evaluate
         * @param[in]  p          Predicate funtion to evaluate the node value with
         *
         * @tparam     Predicate  A function evaluated on node value
         */
        template <typename Predicate> 
        void removeif(BTNode<Object>* node, Predicate p);

        /**
         * @brief      Removes all nodes in the subtree with node as the root
         *
         * @param      node  The root node of the subtree to remove
         */
        void remove_all(BTNode<Object>* node);        

        /**
         * @brief      Adds a node to the tree
         * 
         * @details
         * Precondition: None
         * Postcondition: Item is added to the tree at or below node,
         * depending on the value
         *
         * @param      node  The node position where item will be added
         * @param[in]  it    The item to add to the tree
         */
        void add(BTNode<Object>* node, Object it) const;
        
        /**
         * @brief      Return node pointing to the rightmost item in the subtree
         *
         * @param      node  The node to start with
         *
         * @return     the node pointing to the rightmost item in the subtree
         */
        BTNode<Object>* find_min(BTNode<Object>* node) const; 
        
        /**
         * @brief      Returns a human-readable string output of the tree
         *
         * @param      node   The root node of the subtree
         * @param[in]  level  The current level of the tree
         *
         * @return     human-readable string output of the tree
         */
        std::string toString(BTNode<Object>* node, size_t level) const;
        
        /**
         * @brief      An inorder traversal of a subtree, returning overloaded
         * string output of Objects in the tree.
         * 
         * @param[in]  node   The root node of the subtree
         *
         * @return     A string containing all Objects in the subtree.
         */
        std::string inOrder(BTNode<Object>* node) const;

        /**
         * @brief      Returns the average value of items in the subtree
         *
         * @param      node  The root node of the subtree
         *
         * @return     The average value of items in the subtree
         */
        float average(BTNode<Object>* node) const;

        /**
         * @brief      Counts the number nodes in the subtree which values lie in range [low, high].
         *
         * @param      node  The root node of the subtree
         * @param[in]  low   The low threshold
         * @param[in]  high  The high threshold
         *
         * @return     Number the number nodes in the subtree which values lie in range [low, high]
         */
        size_t countInRange(BTNode<Object>* node, int low, int high) const;
    };
}   
#include "BTree.template"
#endif