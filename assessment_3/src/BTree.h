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
         * @brief      { function_description }
         */
        BTree();

        // Destructor
        /**
         * @brief      Destroys the object.
         */
        ~BTree();


        /**
         * @brief      { function_description }
         *
         * @return     { description_of_the_return_value }
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
         * @brief      Sets the current.
         *
         * @param[in]  entry  The entry
         */
        void set_current(const Object& entry);


        // Insert
        /**
         * @brief      { function_description }
         *
         * @param[in]  entry  The entry
         */
        void tree_insert(const Object& entry);



        // Remove
        /**
         * @brief      { function_description }
         *
         * @param      node_to_remove  The node to remove
         *
         * @return     { description_of_the_return_value }
         */
        bool remove(BTNode<Object>* node_to_remove);


        
        // Tree Navigation

        /**
         * @brief [brief description]
         * @details [long description]
         * @return [description]
         */
        bool goto_root();
        
        /**
         * @brief [brief description]
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
         * @return [description]
         */
        bool empty() const;

        /**
         * @brief      { function_description }
         */
        void tree_clear(); // TO-DO: fix this function!

        /**
         * @brief      { function_description }
         *
         * @return     { description_of_the_return_value }
         */
        std::string inOrder(); // Make generic with function ptr?
        
        /**
         * @brief      Returns a string representation of the object.
         *
         * @return     String representation of the object.
         */
        std::string toString();


        // These should be moved to ClassroomOfStudents to make a generic tree class...
        
        /**
         * @brief      Counts the number of in range.
         *
         * @param[in]  low   The low
         * @param[in]  high  The high
         *
         * @return     Number of in range.
         */
        size_t countInRange(int low, int high);

        /**
         * @brief      { function_description }
         *
         * @return     { description_of_the_return_value }
         */
        float average();

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

        //Helper Functions

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
         * @brief      { function_description }
         *
         * @param      node  The node
         * @param[in]  it    The iterator
         */
        void add(BTNode<Object>* node, Object it);
        
        /**
         * @brief      { function_description }
         *
         * @param      node  The node
         *
         * @return     { description_of_the_return_value }
         */
        BTNode<Object>* find_min(BTNode<Object>* node); 
        
        /**
         * @brief      { function_description }
         *
         * @param      node   The node
         * @param[in]  level  The level
         *
         * @return     { description_of_the_return_value }
         */
        std::string toString(BTNode<Object>* node, size_t level);
        
        /**
         * @brief      { function_description }
         *
         * @param      node  The node
         *
         * @return     { description_of_the_return_value }
         */
        std::string inOrder(BTNode<Object>* node);

        // The below functions should be moved to ClassroomOfStudents to make a generic tree class... 
        /**
         * @brief      { function_description }
         *
         * @param      node  The node
         *
         * @return     { description_of_the_return_value }
         */
        float average(BTNode<Object>* node);
        
        /**
         * @brief      Counts the number of in range.
         *
         * @param      node  The node
         * @param[in]  low   The low
         * @param[in]  high  The high
         *
         * @return     Number of in range.
         */
        size_t countInRange(BTNode<Object>* node, int low, int high);
	};
}	
#include "BTree.template"
#endif