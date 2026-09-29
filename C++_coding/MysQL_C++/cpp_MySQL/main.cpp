#include"Database.hpp"
#include<iostream>
using namespace std;

int main(){
    Database db;
    if(!db.connect()){
        return 1;
    }
    db.createDatabase("student");
    db.createTables("student","students");
    db.insertData("student","students","Kundan",19);
    db.insertData("student", "students", "Khushi",16);
    db.showData("student", "students");

    db.createDatabase("college");
    db.createTables("college","CSE");

    return 0;
}