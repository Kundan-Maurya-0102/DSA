#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
}*start = NULL;

class SLL{
    private:
    int count=0;
    Node *traverse;

    public:
        SLL(int data){
            start = new Node;
            start->next = NULL;
            start->data = data;
            traverse = start;
        }
        ~SLL(){
            cout << endl << "Object deleted " << endl;
            delete start;
        }
    
    void getData(){
            cout << "For start " << start->next << endl << start->data << endl;
            cout << endl << "For Traverse " << traverse->next << endl << traverse->data << endl;
    }
    void insertAtlast(int data){
        traverse->next = new Node;
        traverse = traverse->next;
        traverse->next = NULL;
        traverse->data = data;
    }

    void ShowAllData(){
        Node *printx;
        printx = start;
        cout << endl << "OUTPUT" << endl;
        while(printx !=NULL){
            cout << printx->data << " " ;
            printx = printx->next;
        }
        // cout << traverse->data << endl;
    }
    void InsertAtBeginning(int data){
        Node *temp = new Node;
        temp->data = data;
        temp->next = start;
        start = temp;
    }
void InsertAfterNode(int nodeValue, int data) {
    Node* temp = start;

    // Find the node after which we want to insert
    while (temp != NULL && temp->data != nodeValue) {
        temp = temp->next;
    }

    // Node not found
    if (temp == NULL) {
        cout << "Node not found!" << endl;
        return;
    }

    // Create new node
    Node* newNode = new Node;
    newNode->data = data;

    // Connect new node to the next node
    newNode->next = temp->next;

    // Connect target node to new node
    temp->next = newNode;
}
    bool isPresentNode(int nodeValue){
        Node *temp = new Node;
        temp = start;
        while(temp!=NULL){
            if(nodeValue==temp->data){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

};

int main(){
    SLL sl(5);
    sl.getData();
    sl.insertAtlast(10);
    sl.insertAtlast(15);
    sl.InsertAtBeginning(20);
    sl.ShowAllData();
    sl.InsertAfterNode(20,25);
    sl.InsertAtBeginning(0);
    sl.ShowAllData();

    // sl.insertAtLast(40);
    // sl.insertAfterNode(4,30);
}