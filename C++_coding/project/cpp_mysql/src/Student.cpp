#include "../include/Student.hpp"

#include <iostream>

Student::Student(int id, std::string name, int age)
{
    this->id = id;
    this->name = name;
    this->age = age;
}

int Student::getId()
{
    return id;
}

std::string Student::getName()
{
    return name;
}

int Student::getAge()
{
    return age;
}

void Student::display()
{
    std::cout << "ID   : " << id << std::endl;
    std::cout << "Name : " << name << std::endl;
    std::cout << "Age  : " << age << std::endl;
}