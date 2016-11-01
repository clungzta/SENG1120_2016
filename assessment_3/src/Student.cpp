/**

SENG1120 Assignment 3
Created by Alex McClung, 3256853
Semester 2 2016

**/

#include "Student.h"
#include <iostream>
#include <string>

namespace alex_m
{
Student::Student(const std::string& student_name = std::string(), const float& student_grade = 0)
{
    name = student_name;
    grade = student_grade;
}

Student::Student(const Student& s)
{
    name = s.name.c_str();
    grade = s.grade;
}

Student::Student()
{

}

Student::~Student()
{

}

void Student::set_name(const std::string new_name)
{
    name = new_name;
}

void Student::set_grade(const float new_grade)
{
    grade = new_grade;
}

std::string Student::get_name() const
{
    return name;
}

float Student::get_grade() const
{
    return grade;
}

bool Student::is_grade_in_range(float low_threshold, float high_threshold)
{
    return (grade > low_threshold && grade < high_threshold);
}

int Student::compare_to(const Student& another_student) const
{
    int output = 0;
    if (name < another_student.get_name()) {output = -1;}
    else if (name > another_student.get_name()) {output = 1;}
    return (output);
}

//Override the cout operator
std::ostream& operator<<(std::ostream& out, const Student& student)
{
    out << student.get_name() << " " << student.get_grade();
    return out;
}

std::string operator + (const std::string& other, const Student& student)
{
    return other + " (" + student.get_name() + ", " + std::to_string(student.get_grade()) + ")";
}

float operator + (const float& other, const Student& student)
{
    return other + student.get_grade();
}

// bool operator < (const Student& student1, const Student& student2)
// {
//     return student1.get_name() < student2.get_name();
// }

// bool operator > (const Student& student1, const Student& student2)
// {
//     return student1.get_name() > student2.get_name();
// }

// bool operator == (const Student& student1, const Student& student2)
// {
//     return student1.get_name() == student2.get_name();
// }
}