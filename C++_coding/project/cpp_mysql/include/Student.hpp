#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>

class Student
{
private:
    int id;
    std::string name;
    int age;

public:
    Student(int id, std::string name, int age);

    int getId();
    std::string getName();
    int getAge();

    void display();
};

#endif