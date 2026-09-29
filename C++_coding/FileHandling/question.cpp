//write the program to count words present in the file
//write a program to write a table of number n in a file
//

#include<iostream>
#include<fstream>
using namespace std;

int main(){
    int n;
    n = 10;

    ofstream fout;
    fout.open("table.txt");

    for(int i=1 ; i<=n ; i++){
        fout << i*n << endl;
    }
    fout.close();

    return 0;
}