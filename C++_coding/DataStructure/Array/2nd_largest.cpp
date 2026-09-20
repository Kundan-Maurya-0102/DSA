#include<iostream>
using namespace std;

int main(){
    int arr[] = { 5,7,3,2,9,6,1,8,15,15,14};
    int size = sizeof(arr)/sizeof(int);
    int largest = arr[0];
    for(int i = 0 ; i<size ; i++){
        if(arr[i]>largest)
            largest = arr[i];
    }
    cout<< "Largest " << largest <<endl;

    int second = arr[0];
    for(int i=0 ; i< size ; i++){
        if(arr[i]==largest)
            continue;
        else
            if(arr[i]>second){
                second = arr[i];
            }
    }
    cout << "2nd Largest " << second << endl;

    return 0;
}