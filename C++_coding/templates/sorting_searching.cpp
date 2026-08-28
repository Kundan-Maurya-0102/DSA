#include<iostream>
#include<array>
#include<cstddef>
#include<iomanip>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    const size_t array_size = 7;
    string searchColor;
    array<string,array_size>colors = {"White","Black","Red","Blue","Yellow","Green","Pink"};
    for (string &c : colors) {
        for (char &ch : c) {
            ch = static_cast<char>(tolower(static_cast<unsigned char>(ch)));
        }
    }
    cout<<endl<<"Before Sorting : " <<endl;
    for(size_t i=0; i<array_size ; i++){
        cout << colors.at(i) << " ";
    }
    sort(colors.begin(),colors.end());
    cout << endl;

    for(size_t i=0; i<array_size ; i++){
        cout << colors.at(i) << " ";
    }
    
    cout <<endl;

    cout <<endl<<"Enter color to be searched : ";
    cin>>searchColor;


    bool found = binary_search(colors.begin(),colors.end(),searchColor);
    cout << (found ? "Found" : "Not Found ") <<endl;


    
    return 0;
}