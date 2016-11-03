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
         */
        BTree();

        // Destructor
        /**
         * @brief      Destroys the binary tree object.
         */
        ~BTree();


        /**
         * @brief      Function returning the number of nodes stored in the tree
         *
         * @return     The number of nodes stored in the tree
         */
        size_t tree_count() const;


        // Get or set data

        /**
         * @brief      Gets the current.
         *
         * @return     The current.
         */
        Object get_current() const;
        
        /**
         * @brief      Sets the Object stored at current.
         *
         * @param[in]  entry  The entry to set current to
         */
        void set_current(const Object& entry) const;


        // Insert
        /**
         * @brief      Insert an entry into the tree
         *
         * @param[in]  entry  The entry to insert into the tree
         */
        void tree_insert(const Object& entry);



        // Remove
        /**
         * @brief      Remove an node from the tree
         *
         * @param      node_to_remove  Pointer to the node to remove which will removed
         *
         * @return     True if this node was successfully removed from the tree
         */
        bool remove(BTNode<Object>* node_to_remove);

        /**
         * @brief Moves the cursor to the root node
         * @return True if the root node is not NULL
         */
        bool goto_root();
        
        /**
         * @brief Moves the cursor to the left child node
         * @details [long description]
         * @return [description]
         */
        bool goto_left();
        
        /**
         * @brief [brief description]
         * @details [long description]
         * @return [description]
         */
        bool goto_right();
        
        /**
         * @brief [brief description]
         * @details [long description]
         * @return [description]
         */
        bool goto_parent();
        
        /**
         * @brief [brief description]
         * @details [long description]
         * @return true if the tree is empty
         */
        bool empty() const;

        /**
         * @brief      { function_description }
         */
        void remove_all();

        /**
         * @brief      { function_description }
         *
         * @return     { description_of_the_return_value }
         */
        std::string inOrder() const; // Make generic with function ptr?
        
        /**
         * @brief      Returns a string representation of the object.
         *
         * @return     String representation of the object.
         */
        std::string toString() const;


        // Functions below should be moved to ClassroomOfStudents to make a generic tree class...
        // Nevermind... Marking criteria allows us to use tree class
        
        /**
         * @brief      Counts the number of in range.
         *
         * @param[in]  low   The low
         * @param[in]  high  The high
         *
         * @return     Number of in range.
         */
        size_t countInRange(int low, int high) const;

        /**
         * @brief      { function_description }
         *
         * @return     { description_of_the_return_value }
         */
        float average() const;

        /**
         * @brief      { function_description }
         *
         * @param[in]  p          { parameter_description }
         *
         * @tparam     Predicate  { description }
         */
        template <typename Predicate> // Template for removeif function
        void removeif(Predicate p);

	private:
        // Private member varibles
        
        /**
         * { item_description }
         */
        BTNode<Object>* root_;
        
        /**
         * { item_description }
         */
        BTNode<Object>* current_ptr;
        
        /**
         * { item_description }
         */
        size_t size;

        /**
         * @brief      { function_description }
         *
         * @param      node       The node
         * @param[in]  p          { parameter_description }
         *
         * @tparam     Predicate  { description }
         */
        template <typename Predicate> //Template for removeif function
        void removeif(BTNode<Object>* node, Predicate p);

        /**
         * @brief      Removes all.
         *
         * @param      node  The node
         */
        void remove_all(BTNode<Object>* node);        

        /**
         * @brief      { function_description }
         *
         * @param      node  The node
         * @param[in]  it    The iterator
         */
        void add(BTNode<Object>* node, Object it) const;
        
        /**
         * @brief      { function_description }
         *
         * @param      node  The node
         *
         * @return     { description_of_the_return_value }
         */
        BTNode<Object>* find_min(BTNode<Object>* node) const; 
        
        /**
         * @brief      { function_description }
         *
         * @param      node   The node
         * @param[in]  level  The level
         *
         * @return     { description_of_the_return_value }
         */
        std::string toString(BTNode<Object>* node, size_t level) const;
        
        /**
         * @brief      { function_description }
         *
         * @param      node  The node
         *
         * @return     { description_of_the_return_value }
         */
        std::string inOrder(BTNode<Object>* node) const;

        // The below functions should be moved to ClassroomOfStudents to make a generic tree class... 
        /**
         * @brief      { function_description }
         *
         * @param      node  The node
         *
         * @return     { description_of_the_return_value }
         */
        float average(BTNode<Object>* node) const;
        
        /**
         * @brief      Counts the number of in range.
         *
         * @param      node  The node
         * @param[in]  low   The low
         * @param[in]  high  The high
         *
         * @return     Number of in range.
         */
        size_t countInRange(BTNode<Object>* node, int low, int high) const;
    };
}   
#include "BTree.template"
#endif