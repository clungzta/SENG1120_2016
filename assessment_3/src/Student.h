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
         * @brief      { function_description }
         */
        Student();

        /**
         * @brief      { function_description }
         *
         * @param[in]  student_name   The student name
         * @param[in]  student_grade  The student grade
         */
        Student(const std::string& student_name, const float& student_grade);

        /**
         * @brief      { function_description }
         *
         * @param[in]  s     { parameter_description }
         */
        Student(const Student& s);

        /**
         * @brief      Destroys the object.
         */
        ~Student();
        
        /**
         * @brief      Sets the name.
         *
         * @param[in]  new_name  The new name
         */
        void set_name(const std::string new_name);

        /**
         * @brief      Sets the grade.
         *
         * @param[in]  new_grade  The new grade
         */
        void set_grade(const float new_grade);

        /**
         * @brief      Gets the grade.
         *
         * @return     The grade.
         */
        float get_grade() const;

        /**
         * @brief      Determines if grade in range.
         *
         * @param[in]  low_threshold   The low threshold
         * @param[in]  high_threshold  The high threshold
         *
         * @return     True if grade in range, False otherwise.
         */
        bool is_grade_in_range(float low_threshold, float high_threshold) const;

        /**
         * @brief      { function_description }
         *
         * @param[in]  another_student  Another student
         *
         * @return     { description_of_the_return_value }
         */
        int compare_to(const Student& another_student) const;

        /**
         * @brief      Gets the name.
         *
         * @return     The name.
         */
        std::string get_name() const;

    private:
        /**
         * { item_description }
         */
        std::string name;
        
        /**
         * { item_description }
         */
        float grade;
    };

  /**
   * @brief      { operator_description }
   *
   * @param      out      The out
   * @param[in]  student  The student
   *
   * @return     { description_of_the_return_value }
   */
  std::ostream& operator << (std::ostream& out, const Student& student);
  
  /**
   * @brief      { operator_description }
   *
   * @param[in]  other    The other
   * @param[in]  student  The student
   *
   * @return     { description_of_the_return_value }
   */
  std::string operator + (const std::string& other, const Student& student);
  
  /**
   * @brief      { operator_description }
   *
   * @param[in]  other    The other
   * @param[in]  student  The student
   *
   * @return     { description_of_the_return_value }
   */
  float operator + (const float& other, const Student& student);
  
  /**
   * @brief      { operator_description }
   *
   * @param[in]  student1  The student 1
   * @param[in]  student2  The student 2
   *
   * @return     { description_of_the_return_value }
   */
  bool operator < (const Student& student1, const Student& student2);
  
  /**
   * { item_description }
   */
  bool operator > (const Student& student1, const Student& student2);
  
  /**
   * @brief      { operator_description }
   *
   * @param[in]  student1  The student 1
   * @param[in]  student2  The student 2
   *
   * @return     { description_of_the_return_value }
   */
  bool operator == (const Student& student1, const Student& student2);
}
#endif