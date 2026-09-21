#include<iostream>
using namespace std;
//power exponential function 
double power(double m, int n=2){
    double pow=1;
    int k = n;

    while(n>0){
        pow*=m;
        n--;
    }
    return pow;
}

int main(){
    cout << power(5);
    cout << endl;
    cout << power(4.6,3);
    cout << endl;
    cout << power(5,3);
    cout << endl;
    return 0;
}