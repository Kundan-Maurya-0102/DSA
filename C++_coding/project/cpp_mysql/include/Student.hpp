#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
namespace stdd{

class Student
{
private:
    int id;
    std::string name;
    int age;
    std::string email;

public:
    Student(int id, std::string name, int age, std::string email);

    int getId();
    std::string getName();
    int getAge();
    std::string getEmail();
    void display();
};
}
#endif


// What 