#include<iostream>
#include<fstream>
using namespace std;

int main(){
    // ofstream fout("tell.txt");
    // cout << fout.tellp()<<endl;
    // fout<<"Kundan";
    // cout << fout.tellp()<<endl;
    // fout.close();

    // ifstream fin("tell.txt");
    // char c;
    // cout << fin.tellg()<<endl;

    // cout << fin.tellg()<<endl;
    // fin.close();
    // return 0;

    fstream fout("seek.txt");
    cout << fout.tellp()<<endl;
    fout.seekp(5);
    fout << "JAVA PROGRAMMING";
    fout.close();

    ifstream fin("seek.txt");
    fin.seekg(-2);
    


}