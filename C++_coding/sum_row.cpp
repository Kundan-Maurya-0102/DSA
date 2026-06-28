#include <iostream>
#include<limits.h>
using namespace std;

bool search_value(int arr[][4], int key, int row, int col)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[i][j] == key)
            {
                cout << "Element found at position (" << i << "," << j << ")" << endl;
                return true;
            }
        }
    }
    cout << "Note found " << endl;
    return false;
    
}


int max(int arr[][4] , int row ,int col){
    int max = INT_MIN;
    for(int i=0 ; i<row ; i++){
        for(int j= 0 ; j<col ; j++){
            if(max<arr[i][j]){
                max = arr[i][j];
            }
        }
    }
    return max;
}

int main()
{
    int arr[5][4] = {
        {1, 2, 3, 4},
        {2, 3, 4, 1},
        {5, 6, 1, 3},
        {2, 4, 6, 8},
        {1, 14, 9, 6}};
    cout << "Row wise sum " << endl;
    for (int i = 0; i < 5; i++)
    {
        int sum = 0;
        for (int j = 0; j < 4; j++)
        {
            sum += arr[i][j];
        }
        cout << sum;
        cout << endl;
    }
    cout << "Column wise sum " << endl;
    for (int i = 0; i < 4; i++)
    {
        int sum = 0;
        for (int j = 0; j < 5; j++)
        {
            sum += arr[j][i];
        }
        cout << sum;
        cout << endl;
    }

    cout << endl;
    int key = 12;

    search_value(arr, key, 5, 4) ;
    cout << endl ;
    cout << "Max is : " << max(arr,5,4);
    return 0;
}