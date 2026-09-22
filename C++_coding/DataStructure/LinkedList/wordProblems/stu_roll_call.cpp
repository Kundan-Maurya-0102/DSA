#include<string>
#include<iostream>
using namespace std;

struct studentRollCall{
    string name;
    int roll;
    studentRollCall *next;
}*head = NULL;
void insert(){
    string name;
    int roll;
    cout << "Roll:";
    cin>>roll;
    cout<<"Name:";
    cin>>name;
    studentRollCall *temp = new studentRollCall();
    temp->name = name;
    temp->roll = roll;
    temp->next = NULL;
    if(head==NULL){
        head = temp;
    }
    else{
        studentRollCall *current = head;
        while(current->next!=NULL)
            current = current->next;
        current->next = temp;
    }

}

void print(){
    studentRollCall *temp = head;
    while(temp!=NULL){
        cout << temp->roll<<"->"<<temp->name << endl;
        temp = temp->next;
    }
}

int main(){
    insert();
    insert();
    insert();
    print();
    return 0;
}