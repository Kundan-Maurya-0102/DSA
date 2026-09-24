#ifndef STUDENT_REPOSITORY_HPP
#define STUDENT_REPOSITORY_HPP

#include "Database.hpp"
#include "Student.hpp"
using namespace stdd;
class StudentRepository
{
private:
    Database& database;

public:
    StudentRepository(Database& db);

    void createTable();
    void save(Student& student);
};

#endif