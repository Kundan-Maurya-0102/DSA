#include<fstream>
#include<iostream>
using namespace std;
int main(){
    ofstream fout;
    fout.open("sample.txt",ios::app);
    // fout.write();

    fout.close();

    ifstream fin;
    fin.open("sample.txt",ios::in);
    char x;
    x = fin.get();
    while(!fin.eof()){
        cout << x ;
        x = fin.get();
    }
    fin.close();

    return 0;
}