#include<fstream>
#include<iostream>
using namespace std;
int main(){
    ofstream fout;
    fout.open("example.txt");
    fout << "This is class of JAVA\n It is object oriented programming";
    fout.close();

    ifstream fin("example.txt");
    // char c;
    string c;


    // while(getline(fin,c))
    //     cout << c << endl;

    // while(fin>>c){
    //     cout << c << endl;
    // // }

    // char x = fin.get();
    // while(!fin.eof()){
    //     cout << x ;
    //     x = fin.get();
    // }
    // cout << endl;


    return 0;
}
