#include<iostream>
using namespace std;

//insertAtBeginning()
//insertAtLast()
//display()

struct Node{
    int data;
    Node *next;
}*head = nullptr;

void Ib( int d){
    Node * temp  = new Node();
        temp->data = d;
        temp->next = head;
        head = temp;
    
}
void display(){
    Node * temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next ;
    } 
    cout << endl;
}

void Il(int data){
    Node *ptr = head;
    Node *temp = new Node();

    temp->data = data;
    temp->next = NULL;

    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next = temp;

}

int main(){
    
    Ib(45);
    Ib(78);
    display();
    Il(20);
    Il(30);
    display();
    return 0;
};