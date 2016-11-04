/**

SENG1120 Assignment 3
Created by Alex McClung, 3256853
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

        /**
         * @brief      Student constructor
         * 
         * @details
         * Precondition: None
         * Postcondition: Student object is initialised
         */
        Student();

        /**
         * @brief      Alternate Student constructor (with name and grade parameters)
         *
         * @details
         * Precondition: None
         * Postcondition: Student object is initialised
         *
         * @param[in]  student_name   The name of the student
         * @param[in]  student_grade  The grade attained by the student
         */
        Student(const std::string& student_name, const float& student_grade);

        /**
         * @brief      Student Constructor (copy of another student)
         *
         * @details
         * Precondition: A student object is initialised
         * Postcondition: A copy of this Student object is initialised
         *
         * @param[in]  s     A student object to be copied
         */
        Student(const Student& s);

        /**
         * @brief      Destroys the Student object.
         * 
         * @details
         * Precondition: None
         * Postcondition: This student object is destroyed
         * 
         */
        ~Student();
        
        /**
         * @brief      Sets the name of the student.
         * 
         * @details
         * Precondition: None
         * Postcondition: Student name is set to new_name
         *
         * @param[in]  new_name  The new name of the student
         */
        void set_name(const std::string new_name);

        /**
         * @brief      Sets the grade of the Student.
         * 
         * @details
         * Precondition: None
         * Postcondition: Student grade is set to new_grade
         *
         * @param[in]  new_grade  The new grade of the student
         */
        void set_grade(const float new_grade);

        /**
         * @brief      Gets the grade.
         *
         * @return     The grade.
         */
        float get_grade() const;

        /**
         * @brief      Determines if the Student's grade falls within the range [low,high].
         *
         * @param[in]  low   The low threshold
         * @param[in]  high  The high threshold
         *
         * @return     True if grade in range [low, high], False otherwise.
         */
        bool is_grade_in_range(float low, float high) const;

        /**
         * @brief      Compares this Student object with another Student object
         * 
         * @details
         * Precondition: Another Student Object is initialised
         * Postcondition: This Student Object is compared the other student Object
         *
         * @param[in]  another_student  Student to compare with.
         *
         * @return     -1: if this student's name comes before another_students name alphabetically, 
         * 0: if the names are the same, 
         * 1: if another_student name comes before this students name alpabetically
         */
        int compare_to(const Student& another_student) const;

        /**
         * @brief      Gets the name of the Student.
         *
         * @return     Returns the name of the Student.
         */
        std::string get_name() const;

    private:
        /**
         * The name of the student
         */
        std::string name;
        
        /**
         * The grade attained by the student
         */
        float grade;
    };

  /**
   * @brief      Overloaded cout operator for Student object
   */
  std::ostream& operator << (std::ostream& out, const Student& student);
  
  /**
   * @brief      Overloaded plus operator for Student object with another Student
   */
  std::string operator + (const std::string& other, const Student& student);
  
  /**
   * @brief      Overloaded plus operator for Student object with a float grade
   */
  float operator + (const float& other_grade, const Student& student);
}
#endif