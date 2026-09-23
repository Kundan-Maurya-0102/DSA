#ifndef STUDENT_REPOSITORY_HPP
#define STUDENT_REPOSITORY_HPP

#include "Database.hpp"
#include "Student.hpp"

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