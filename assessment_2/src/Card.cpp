/**

SENG1120 Assignment 1
Created by Alex McClung
Semester 2 2016

**/

#include "Node.h"
#include <iostream>
#include <string>

namespace alex_m
{
    // Constructor
    // Precondition: None
    // Postcondition: A new Card instance is created
    // @initial_data: Initial data to be stored in the Card. Default Empty Object
    // @initial_prev_link: Initial pointer to the previous Card in the list. Default NULL
    // @initial_next_link: Initial pointer to the next Card in the list. Default NULL
    Card::Card(const std::string& initial_face, const int& initial_value, const bool& initially_face_up)
    {
    	face = initial_face;
    	value = initial_value;
    	face_up = initially_face_up;
    }

    // Card::Card()
    // {

    // }

    // Destructor
    // Precondition: None
    // Postcondition: The Card instance is deleted
    Card::~Card()
    {
    	
    }

    // Precondition: None
    // Postcondition: The data stored within the Card is set to @param new_data
    void Card::set_face(const std::string new_face)
    {
    	face = new_face;	
    }

    // Precondition: None
    // Postcondition: The data stored within the Card is set to @param new_data
    void Card::set_value(const int new_value)
    {
    	
    }

    std::string Card::get_face() const
    {
    	return face;
    }

    bool Card::is_face_up() const
    {
    	return face_up;
    }

    int Card::get_value() const
    {
    	return value;
    }

    // Precondition: None
    // Postcondition: Faceup is toggled
    bool Card::flip()
    {
    	face_up = !face_up;
    	return face_up;
    }

  	//Override the cout operator
  	std::ostream& operator<<(std::ostream& out, const Card& card)
  	{
	   out << card.get_face();
	   return out;
  	}
}