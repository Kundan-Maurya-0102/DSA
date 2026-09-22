#include<iostream>
#include<stack>
using namespace std;
#define SIZE 5
class Stack{
    private:
        int arr[SIZE];
        int top = -1;

    public:
        void push(int );
        void display();
        void pop();
};
void Stack::push(int data){
    if(top==SIZE-1){
        cout << endl << "Overflow / Full "<<endl;
    }
    else{
        arr[++top] = data;
    }
}
void Stack::display(){
    for(int i=0 ; i<SIZE ; i++){
        cout << arr[i] << endl;
    }
    cout << endl;
}
void Stack::pop(){
    if(top==-1){
        cout << endl << "underflow / Empty" <<endl;
    }
}
int main(){
    stack<int>s;
    Stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.display();
    s1.pop();
    s1.push(65);
    s1.display();
    return 0;
}