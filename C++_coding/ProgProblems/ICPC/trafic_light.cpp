#include<iostream>
using namespace std;
int main(){
    while(1){
        char choice;
        cin>>choice;
        switch(choice){
            case 'B':
                cout << "Y"<<endl;
            break;
            case 'Y':
                cout << "R"<<endl;
            break;
            case 'R':
                cout << "B"<<endl;
            break;
        }
    }
}