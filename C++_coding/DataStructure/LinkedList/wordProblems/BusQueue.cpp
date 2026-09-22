#include<string>
#include<iostream>
using namespace std;

struct BusQueue{
    string passengers;
    BusQueue *next;
}*head = NULL;

void add(string psg){
    BusQueue * temp = new BusQueue();
    temp->passengers = psg;
    temp->next = NULL;

    if(head==NULL){
        head = temp;
    }
    else{
        BusQueue *current = head;
        while(current->next!=NULL)
            current = current->next;
        current->next = temp;
    }

};
void Remove(){
    BusQueue *temp = head;
    cout << endl << "Removed " << temp->passengers << endl;
    head = head->next;
    delete temp;

}
void print(){
    BusQueue *temp = head;
    cout << endl;
    cout << "Waiting passengers:" <<endl;
    while(temp!=NULL){
        cout << temp->passengers << " " ;
        temp = temp->next;
    }
    cout << endl << endl;
}

int main(){
    add("Person1");
    add("Person2");
    add("Person3");

    Remove(); // first person 
    add("Person4");
    print();


    return 0;
}