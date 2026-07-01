#include<iostream>
using namespace std;

int factorial(int n){
    if(n==0)
        return 1;
    else
        return factorial(n-1)*n;
}

int main(){
    int fact = 1, n=5;
    while(n!=1){
        fact*=n;
        n--;
    }
    cout << fact ;

    int fact2  = factorial(6);
    cout << endl << fact2 << endl;
    return 0;
}