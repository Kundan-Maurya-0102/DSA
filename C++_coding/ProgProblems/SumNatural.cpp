#include<iostream>
using namespace std;
int main(){
    int num;
    cout << "Enter the number eg 10 we calculate the sum from 1-10 " << endl;
    cin>>num;

    int sum = (num*(num-1))/2;
    cout << "Sum is " << sum << endl ;
}