#include <iostream>
#include <array>
#include <iomanip>
#include <cstddef>
#include <algorithm>

using namespace std;

int main()
{
    cout << endl << "Hii EveryOne Kaise ho "<<endl;
    const size_t columns = 6;
    const size_t rows = 2;

    array<array<int, columns>, rows> arr;
    for(size_t i=0; i<rows ; i++){
        for(size_t j=0; j<columns ; j++){
            cin>>arr[i][j];
        }
    }
    cout << "student" << setw(12) << "SerialNo" << setw(25) << "Mark1" << setw(35) << "Mark2" << setw(45) << "Mark3" << setw(15) << "Mark3" << endl;

    for(size_t i=0; i<rows ; i++){
        for(size_t j=0 ; j<columns ; j++){
            if(j==columns-1)
            cout << arr[i][j];
            else
            cout <<setw(8)<< arr[i][j];
        }
        cout<<endl;
    }
    return 0;
}