#include <iostream>

#include "include/Database.hpp"
#include "include/Student.hpp"
#include "include/StudentRepository.hpp"

int main()
{
    Database db;

    if (!db.connect())
    {
        return 1;
    }

    StudentRepository repository(db);

    repository.createTable();

    // Student student(1, "Kundan", 19);
    // repository.save(student);

    Student student2(4, "Khushi", 16);
    repository.save(student2);

    return 0;
}


/*

g++ main.cpp src/Database.cpp src/Student.cpp src/StudentRepository.cpp -Iinclude -lmysqlcppconn -o build/app

.hpp → WHAT
.cpp → HOW
*/