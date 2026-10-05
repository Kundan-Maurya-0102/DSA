#include<string>
#include<iostream>
#define SIZE 10
using namespace std;
class stack{
    private:
        string arr[SIZE];
        int top=-1;
    public:
        void push(string data);
        void pop();
        void display();
};

void stack::push(string data){
    if(top==SIZE-1){
        cout << "not enought RAM to open new tab "<<endl;
        return ;
    }
    arr[++top] = data;
}
void stack::pop(){
    if(top==-1){
        cout << "No pages visited "<<endl;
        return;
    }
    // cout << endl << "Removed " << arr[top] << endl;
    top--;

}
void stack::display(){
    for(int i=0; i<=top ; i++)
        cout << arr[i] << endl;
}
int main(){
    stack s1;
    s1.push("Google");
    s1.push("Youtube");
    // s1.push("Instagram");
    // s1.pop();
    s1.display();
    return 0;
}