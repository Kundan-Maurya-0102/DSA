#include<fstream>
#include<iostream>
using namespace std;
int main(){
    int count=0;

    ofstream fout;
    fout.open("example.txt");
    fout << "This is class of JAVA\nIt is object oriented programming";
    fout.close();

    ifstream fin("example.txt");
    // char c;
    string c;


    // while(getline(fin,c)){
    //     cout << c << endl;
    //     count++;
    // }


    while(fin>>c){
        cout << c << " ";
        count++;
    }

    // char x = fin.get();
    // while(!fin.eof()){
    //     cout << x ;
    //     x = fin.get();
    // }
    // cout << endl;


    // char x;
    // while(fin.get(x)){
    //     cout << x ;
    //     count++;
    // }
    cout << endl << count << endl;


    return 0;
}
