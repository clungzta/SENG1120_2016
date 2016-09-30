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
    Card::Card(const std::string& initial_face, const int& initial_value, const bool& initially_face_up)
    {
    	face = initial_face;
    	value = initial_value;
    	face_up = initially_face_up;
    }

    Card::~Card()
    {
    	
    }

    void Card::set_face(const std::string new_face)
    {
    	face = new_face;	
    }

    void Card::set_value(const int new_value)
    {
    	value = new_value;
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

    void Card::set_face_up()
    {
		face_up = true;
    }

    void Card::set_face_down()
    {
    	face_up = false;
    }

  	//Override the cout operator
  	std::ostream& operator<<(std::ostream& out, const Card& card)
  	{
	   out << card.get_face();
	   return out;
  	}
}