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
         * @brief      Constructor for BTNode (Binary Tree Node)
         *
         * @param[in]  initial_data  The initial data stored in the node
         */
        BTNode(const Object& initial_data = Object());

        /**
         * @brief      Destroys the BTNode.
         */
        ~BTNode();        

        /**
         * @brief      The data stored within the node is set to new_data
         *  Precondition: None
         *  Postcondition: The data stored within the node is set to new_data
         *
         * @param[in]  new_data  The new data to set the node value to
         */
        void set_data(const Object& new_data);
    
        /**
         * @brief     The left child node ptr is set to new_link
         * 
         * @details
         * Precondition: None
         * Postcondition: The left child node ptr is set to new_link
         *
         * @param      new_link  ptr to the new left child node
         */
        void set_left(BTNode* new_link);

        /**
         * @brief     The parent node ptr is set to new_link
         * 
         * @details
         * Precondition: None
         * Postcondition: The parent node ptr is set to new_link
         *
         * @param      new_link  ptr to the new parent node
         */
        void set_right(BTNode* new_link);

        /**
         * @brief     The right child node ptr is set to new_link
         * 
         * @details
         * Precondition: None
         * Postcondition: The right child node ptr is set to new_link
         *
         * @param      new_link  ptr to the new right child node
         */
        void set_parent(BTNode* new_link);

        /**
         * @brief      Returns the data stored in the node (Object template type)
         *
         * @return     Data stored in the node
         */
        Object data() const;

        /**
         * @return     ptr to the left child node
         */
        BTNode* left() const;

        /**
         * @return     ptr to the right child node
         */
        BTNode* right() const;

        /**
         * @return     ptr to the parent node
         */
        BTNode* parent() const;

        /**
         * @brief      Determines whether the node is a leaf node.
         *
         * @return     True if leaf, False otherwise.
         */
        bool is_leaf() const;
        
        /**
         * @brief      Determines whether the node has a single child.
         *
         * @return     True if has single child, False otherwise.
         */
        bool has_single_child() const;
        
        /**
         * @brief      Determines the node is a left child.
         *
         * @return     True if is a left child, False otherwise.
         */
        bool is_left_child() const;
        
        /**
         * @brief      Determines if the node has a right child.
         *
         * @return     True if the node has a right child, False otherwise.
         */
        bool is_right_child() const;

    private:
        
        /**
         * Data stored in the node
         */
        Object d;

        /**
         * ptr to the left child node
         */
        BTNode* left_;
        
        /**
         * ptr to the right child node
         */
        BTNode* right_;
        
        /**
         * ptr to the parent node
         */
        BTNode* parent_;
    };
}
#include "BTNode.template"
#endif