#include<iostream>
using namespace std;
int main(){
    long int n;
    cin>>n;
    long int count=0;
    long int arr[n];
    for(int i=0 ; i<n ; i++)
        cin >> arr[i];

    for(int i=1; i<n ; i++){
        if(arr[i]<arr[i-1]){
            long int sum = arr[i-1]-arr[i];
            count += sum;
            arr[i]+=sum;
        }
    }
    cout << count << endl;
    return 0;
}