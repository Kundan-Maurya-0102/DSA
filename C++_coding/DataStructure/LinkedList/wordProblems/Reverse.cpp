// #include<string>
#include<iostream>
#include<stack>
using namespace std;
struct Node{
    int data;
    Node *next;
}*head = nullptr;
void add(int data){
    Node *temp = new Node();
    temp->data = data;
    temp->next = nullptr;
    if(head==nullptr){
        head = temp;
    }
    else{
        Node *current = head;
        while(current->next!=nullptr)
            current = current->next;
        current->next = temp;
    }
}
void print(){
    Node *temp = head;
    while(temp!=nullptr){
        cout << temp->data << " " ;
        temp = temp->next;
    }
    cout << endl;
}
void reverse(){
    stack<int>s;
    Node *temp = head;
    while(temp!=nullptr){
        s.push(temp->data);
        temp = temp->next;
    }
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl; 
}

int main(){
    add(10);
    add(20);
    add(30);
    add(40);
    add(50);
    print();
    reverse();
    return 0;
}