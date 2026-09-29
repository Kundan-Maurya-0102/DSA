#ifndef DATABASE_HPP
#define DATABASE_HPP
#include<mysql_driver.h>
#include<mysql_connection.h>
#include<cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include<string>
using namespace std;
class Database{
    private:
        sql::mysql::MySQL_Driver * driver;
        sql::Connection * connection;
    public:
        Database();
        bool connect();
        void createDatabase(const string&DB);
        void createTables(const string &DB,const string &Tname);
        void insertData(const string &DB,const string &Tname,const string &name, int age);
        void showData(const string&DB, const string&Tname);
        ~Database();
};

#endif