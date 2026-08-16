#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int count=0;
    int n=10;
    for(int i=2 ; i<=sqrt(n); i++){
        if(n%i==0){
            cout << "Prime " << endl;
            count++;
            break;
        }
    }
    if(count==0){
        cout << "Not Prime " << endl;
    }
    return 0;
}