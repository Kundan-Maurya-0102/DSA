#include<iostream>
using namespace std;
class Account{
    private:
        int balance;
    public:
        void getBal(int bal){
            this->balance = bal;
        }
        void display(){
            cout << this->balance<<endl;
        }
        friend void swaped(Account & a, Account & b);
};
void swaped(Account &a,Account &b){
    a.balance = a.balance^b.balance;
    b.balance = a.balance^b.balance;
    a.balance = a.balance^b.balance;
}

int main(){
    Account a1;
    Account a2;
    a1.getBal(5000);
    a2.getBal(8000);
    a1.display();
    a2.display();
    swaped(a1,a2);
    a1.display();
    a2.display();
    return 0;
}