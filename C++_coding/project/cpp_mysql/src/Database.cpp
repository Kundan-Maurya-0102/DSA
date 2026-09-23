#include "../include/Database.hpp"

#include <iostream>

Database::Database()
{
    driver = nullptr;
    connection = nullptr;
}

Database::~Database()
{
    disconnect();
}

bool Database::connect()
{
    try
    {
        driver = sql::mysql::get_mysql_driver_instance();

        connection = driver->connect(
            "tcp://127.0.0.1:3306",
            "cppuser",
            "Cpp@12345"
        );

        connection->setSchema("cpp_demo");

        std::cout << "MySQL Connected Successfully!" << std::endl;

        return true;
    }
    catch (sql::SQLException& e)
    {
        std::cout << "MySQL Connection Failed!" << std::endl;
        std::cout << "Error: " << e.what() << std::endl;

        return false;
    }
}

void Database::disconnect()
{
    if (connection != nullptr)
    {
        delete connection;
        connection = nullptr;
    }
}

sql::Connection* Database::getConnection()
{
    return connection;
}