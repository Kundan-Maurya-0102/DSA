#include "Database.hpp"
#include<iostream>
using namespace std;
Database::Database(){
    driver = nullptr;
    connection = nullptr;
}
bool Database::connect(){
    try{
        driver = sql::mysql::get_mysql_driver_instance();

        connection = driver->connect(
            "tcp://127.0.0.1:3306",
            "cppuser",
            "Cpp@12345"
        );

        std::cout << "MySQL connected" << std::endl;
        return true;
    }
    catch(sql::SQLException &e){
        std::cout 
            << "Connection Failed "
            << e.what()
            << std::endl;
        return false;
    }
}
void Database::createDatabase(const string &DB){
    sql::Statement *stm = connection->createStatement();
    stm->execute(
        "CREATE DATABASE IF NOT EXISTS "+DB+""
    );
    delete stm;

    std::cout << "Database Created Successfullly"<<std::endl;
}
void Database::createTables(const string &DB, const string&Tname){
    connection->setSchema(DB);
    sql::Statement *stm = connection->createStatement();
    stm->execute(
        "CREATE TABLE IF NOT EXISTS "+Tname+"("
        "id int PRIMARY KEY AUTO_INCREMENT,"
        "name VARCHAR(100),"
        "age int "
        ")"
    );
    delete stm;

    std::cout << "Table Created Succussfully"<<std::endl;
}
void Database::insertData(const string &DB ,const string &Tname, const string &name, int age){
    connection->setSchema(DB);

    sql::PreparedStatement *pstm = 
        connection->prepareStatement(
            "INSERT INTO "+Tname+" (name, age) VALUES (?, ?)"
        );
    pstm->setString(1,name);
    pstm->setInt(2,age);
    pstm->execute();
    delete pstm;
    std::cout<<"Data Inserted Successfullly"<<std::endl;
}
void Database::showData(const string &DB,const string&Tname){
    connection->setSchema(DB);
    sql::Statement *stm = connection->createStatement();
    sql::ResultSet * result =
        stm->executeQuery(
            "SELECT * FROM "+Tname+""
        );
        while(result->next()){
            cout << "ID: " << result->getInt("id") << endl;
            cout << "Name: " << result->getString("name")<<endl;
            cout << "Age: "<<result->getInt("age")<<endl;
        }
        delete result;
        delete stm;
}
Database::~Database(){
    if(connection!=nullptr)
        delete connection;
}