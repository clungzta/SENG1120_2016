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
        // @initial_face: Initial face of the Card. Default: Empty String
        // @initial_value: Initial integer value of the card. Default Empty String
        // @initially_face_up: Is the card initially face up? Default False
        //const Object& initial_data = Object(), Node* initial_prev_link = NULL, Node* initial_next_link = NULL
        Card(const std::string& initial_face = std::string(), const int& initial_value = 0, const bool& initially_face_up = false);

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

        // Precondition: None
        // Postcondition: The integer value of the card is returned
        int get_value() const;

        // Precondition: None
        // Postcondition: The string value of the card is returned
        std::string get_face() const;

        // Precondtion: None
        // Postcondition: A boolean is returned: true if the card is face up, otherwise false
        bool is_face_up() const;

        // Precondition: None
        // Postcondition: Card is set to face up
        void set_face_up();

        // Precondition: None
        // Postcondition: Card is set to face down
        void set_face_down();

    private:
        std::string face;
        int value;
        bool face_up;
    };
   //Overloading the cout operator for a Card
  std::ostream& operator<<(std::ostream& out, const Card& card);
}
#endif