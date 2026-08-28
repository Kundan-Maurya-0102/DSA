#include<iostream>
#include<array>
#include<cstddef>
#include<iomanip>

using namespace std;

int main(){
    const size_t ARRAY_SIZE = 5;
    array<int,5>a;
    int sum=0;
    cout << "Get Value into array : " <<endl;
    for(size_t i=0;i<ARRAY_SIZE ; i++){
        cin>>a.at(i);
    }
    cout << endl <<"Printing the value of array : " <<endl;
    for(size_t i = 0 ; i<ARRAY_SIZE ; i++){
        sum+=a.at(i);
    }
    cout << endl << "Sum of array is " << sum << endl;
    
    cout <<"Printing the value of Array  : " <<endl;
    
    cout << "Elements" << setw(13) << "Values"<<endl;

    for(size_t i=0; i<ARRAY_SIZE ;i++){
        cout << setw(7)<<i<<setw(13)<<a.at(i) << endl;
    }
}