#include<iostream>
#include"TaskManager.hpp"
#include<vector>
#include<string>

using namespace std;
int main(){
    User u1;
    u1.createTask();
    u1.createTask();
    u1.showTask();
    u1.deleteTask();
    u1.createTask();

    return 0;
}
