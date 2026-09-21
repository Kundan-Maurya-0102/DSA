#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class user{
    protected:
        string name = "Kundan Maurya";
        int id = 1;
    public:
        virtual void display() = 0;

};

class Employee: public user{
    private:
        string email = "Kumak6316@gmail.com";
    public:
        void display(){
            cout << setw(8) << "Name "<< setw(20) << "Email " << setw(15) << "Id" <<endl;
            cout << name << "     " <<  email <<  "   " << id << endl;
        }
};

int main(){
    Employee e1;
    e1.display();

    return 0;
}