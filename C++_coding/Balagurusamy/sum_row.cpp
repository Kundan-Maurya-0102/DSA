#include<iostream>
using namespace std;
int main(){
    int row  = 3;
    int col = 2;
    int matrix[row][col] = {
        {4,6},
        {5,3},
        {2,7}
    };

    for(int i=0 ; i<row; i++){
        int sum=0;
        for(int j =0 ;j<col ; j++){
            cout << matrix[i][j] << " ";
            sum+=matrix[i][j];
        }
        cout << sum << endl;
        
    }


    return 0;

}