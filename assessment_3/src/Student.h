/**

SENG1120 Assignment 1
Created by Alex McClung
Semester 2 2016

**/

#ifndef Student_H
#define Student_H

#include <string>

namespace alex_m
{
    class Student
    {
    public:
        // Constructor
        // Precondition: None
        // Postcondition: A new Student instance is created
        // @initial_name: Initial name of the Student. Default: Empty String
        // @initial_grade: Initial floateger grade of the card. Default Empty String
        // @initially_name_up: Is the card initially name up? Default False
        //const Object& initial_data = Object(), BTNode* initial_prev_link = NULL, BTNode* initial_next_link = NULL
        Student();

        Student(const std::string& student_name, const float& student_grade);

        Student(const Student& s);

        // Destructor
        // Precondition: None
        // Postcondition: The Student instance is deleted
        ~Student();

        // Precondition: None
        // Postcondition: The data stored within the Student is set to @param new_data
        void set_name(const std::string new_name);

        // Precondition: None
        // Postcondition: The data stored within the Student is set to @param new_data
        void set_grade(const float new_grade);

        // Precondition: None
        // Postcondition: The floateger grade of the card is returned
        float get_grade() const;

        int compare_to(const Student& another_student) const;

        // Precondition: None
        // Postcondition: The string grade of the card is returned
        std::string get_name() const;

    private:
        std::string name;
        float grade;
    };
   //Overloading the cout operator for a Student
  std::ostream& operator << (std::ostream& out, const Student& student);
  std::string operator + (const std::string& other, const Student& student);
  float operator + (const float& other, const Student& student);
  bool operator < (const Student& student1, const Student& student2);
  bool operator > (const Student& student1, const Student& student2);
  bool operator == (const Student& student1, const Student& student2);

  // //Overloading the comparison operator for s
  // std::ostream& operator<<(std::ostream& out, const Student& student);
}
#endif