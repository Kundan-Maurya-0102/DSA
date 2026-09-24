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

    Student student(5, "Rishi", 19, "kumak63@gmail.com");
    repository.save(student);
    
    return 0;
}


/*

g++ main.cpp src/Database.cpp src/Student.cpp src/StudentRepository.cpp -Iinclude -lmysqlcppconn -o build/app

.hpp → WHAT
.cpp → HOW
*/