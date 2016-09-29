/**

SENG1120 Assignment 1
Created by Alex McClung
Semester 2 2016

**/

#ifndef Card_H
#define Card_H

#include <string>

namespace alex_m
{
    class Card
    {
    public:
        // Constructor
        // Precondition: None
        // Postcondition: A new Card instance is created
        // @initial_data: Initial data to be stored in the Card. Default Empty Object
        // @initial_prev_link: Initial pointer to the previous Card in the list. Default NULL
        // @initial_next_link: Initial pointer to the next Card in the list. Default NULL
            //const Object& initial_data = Object(), Node* initial_prev_link = NULL, Node* initial_next_link = NULL
        Card(const std::string& initial_face = std::string(), const int& initial_value = 0, const bool& initially_face_up = NULL);

        //Card();

        // Destructor
        // Precondition: None
        // Postcondition: The Card instance is deleted
        ~Card();

        // Precondition: None
        // Postcondition: The data stored within the Card is set to @param new_data
        void set_face(const std::string new_face);

        // Precondition: None
        // Postcondition: The data stored within the Card is set to @param new_data
        void set_value(const int new_value);

        int get_value() const;

        std::string get_face() const;

        bool is_face_up() const;

        // Precondition: None
        // Postcondition: The next_link pointer is set to @param new_link
        bool flip();

    private:
        std::string face;
        int value;
        bool face_up;
    };
   //Overloading the cout operator for a Card
  std::ostream& operator<<(std::ostream& out, const Card& card);
}
#endif