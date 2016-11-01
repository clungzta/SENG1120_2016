/**

SENG1120 Assignment 3
Created by Alex McClung, 3256853
Semester 2 2016

**/

#ifndef Node_H
#define Node_H

#include "Student.h"
#include <string>

namespace alex_m
{
    template <typename Object>
    class BTNode //For a doubly linked tree
    {
    public:

        /**
         * @brief      { function_description }
         *
         * @param[in]  initial_data  The initial data
         */
        BTNode(const Object& initial_data = Object());

        /**
         * @brief      Destroys the object.
         */
        ~BTNode();        

        /**
         * @brief      
         *  Precondition: None
         *  Postcondition: The data stored within the node is set
         *
         * @param[in]  new_data  The new data
         */
        void set_data(const Object& new_data);
    
        /**
         * @brief      
         *  Precondition: None
         *  Postcondition: The pointer to the right child is set
         *
         * @param      new_link  The new link
         */
        void set_left(BTNode* new_link);

        /**
         * @brief      Sets the right.
         *
         * @param      new_link  The new link
         */
        void set_right(BTNode* new_link);

        /**
         * @brief      Sets the parent.
         *
         * @param      new_link  The new link
         */
        void set_parent(BTNode* new_link);

        /**
         * @brief      { function_description }
         *
         * @return     Data stored in the node
         */
        Object data() const;

        /**
         * @brief      { function_description }
         *
         * @return     The left child node in the tree
         */
        BTNode* left() const;

        /**
         * @brief      { function_description }
         *
         * @return     The left child node in the tree
         */
        BTNode* right() const;

        /**
         * @brief      { function_description }
         *
         * @return     The parent node in the tree
         */
        BTNode* parent() const;

        /**
         * @brief      Determines if leaf.
         *
         * @return     True if leaf, False otherwise.
         */
        bool is_leaf() const;
        
        /**
         * @brief      Determines if it has single child.
         *
         * @return     True if has single child, False otherwise.
         */
        bool has_single_child() const;
        
        /**
         * @brief      Determines if left child.
         *
         * @return     True if left child, False otherwise.
         */
        bool is_left_child() const;
        
        /**
         * @brief      Determines if right child.
         *
         * @return     True if right child, False otherwise.
         */
        bool is_right_child() const;

    private:
        
        /**
         * { item_description }
         */
        Object d;

        /**
         * { item_description }
         */
        BTNode* left_;
        
        /**
         * { item_description }
         */
        BTNode* right_;
        
        /**
         * { item_description }
         */
        BTNode* parent_;
    };
}
#include "BTNode.template"
#endif