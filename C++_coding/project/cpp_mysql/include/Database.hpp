#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <mysql_driver.h>
#include <mysql_connection.h>

class Database
{
private:
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* connection;

public:
    Database();
    ~Database();

    bool connect();
    void disconnect();

    sql::Connection* getConnection();
};

#endif