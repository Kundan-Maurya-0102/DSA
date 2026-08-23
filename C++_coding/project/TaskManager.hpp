#ifndef TaskManager
#define TaskManager
#include <iostream>
#include <vector>
using namespace std;
class Task
{
private:
    vector<string> Title;
    vector<string> Description;

public:
    
    void PutTitle()
    {
        string title;
        cout << endl
             << "Enter Title : ";
        cin >> title;
        Title.push_back(title);
    }
    void PutDescription()
    {
        string des;
        cout << endl
             << "Enter Title : ";
        cin >> des;
        Description.push_back(des);
    }
    void showTask(){
        for(int i=0 ; i<Title.size() ; i++){
            cout << i << " " << endl << Title.at(i) << endl << Description.at(i) << endl;
        }
    }
    void deleteTask(int id){
        if(id<Title.size() && id>=0){
            Title.erase(Title.begin()+id);
            Description.erase(Description.begin()+id);
        }
    }   

};
class User
{
    Task *obj;
    int id=0;


public:
    User()
    {
        obj = new Task();
    }

    void createTask(){
        
        obj->PutTitle();
        cout << endl
             << "Task Added Successfully : " << endl;
             id++;
    }
    void deleteTask()
    {
        int Tid;
        cout << endl << "Enter Task's Id ";
        cin >> Tid;
        cout << "Task Deleted Successfully : " << endl;
        obj->deleteTask(Tid);
    }
    void showTask(){
        obj->showTask();
    }
};


#endif
