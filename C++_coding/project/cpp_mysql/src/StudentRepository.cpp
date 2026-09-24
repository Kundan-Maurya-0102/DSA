#include "../include/StudentRepository.hpp"

#include <iostream>
#include <cppconn/statement.h>

StudentRepository::StudentRepository(Database& db)
    : database(db)
{
}

void StudentRepository::createTable()
{
    sql::Statement* stmt =
        database.getConnection()->createStatement();

    stmt->execute(
        "CREATE TABLE IF NOT EXISTS students ("
        "id INT PRIMARY KEY,"
        "name VARCHAR(100),"
        "age INT,"
        "email VARCHAR(100)"
        ")"
    );

    delete stmt;

    std::cout << "Table created successfully!\n";
}

void StudentRepository::save(Student& student)
{
    sql::Statement* stmt =
        database.getConnection()->createStatement();

    std::string query =
        "INSERT INTO students (id, name, age, email) VALUES (" +
        std::to_string(student.getId()) +
        ", '" +
        student.getName() +
        "', " +
        std::to_string(student.getAge()) +
        ", '" +
        student.getEmail() +
        "')";

    stmt->execute(query);

    delete stmt;

    std::cout << "Student saved to database!\n";
}