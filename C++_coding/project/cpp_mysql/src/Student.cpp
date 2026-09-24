#include "../include/Student.hpp"

#include <iostream>
using namespace stdd;
Student::Student(int id, std::string name, int age, std::string email)
{
    this->id = id;
    this->name = name;
    this->age = age;
    this->email = email;
}

int Student::getId()
{
    return id;
}
std::string Student::getEmail(){
    return email;
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
    std::cout << "Email : " << email << std::endl;
}

// How