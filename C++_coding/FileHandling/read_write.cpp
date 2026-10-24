#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class student{
    private:
        int id;
        char sub[100];
    public:
        void getData(){
            cin>>id;
            cin.ignore();
            cin.getline(sub,100);
        }
        void showData(){
            cout << id << " " << sub;        
        }
};
int main(){
    student s1;
    s1.getData();
    ofstream fout("sample2",ios::binary);
    fout.write((char*)&s1 , sizeof(s1));
    fout.close();

    ifstream fin("sample2",ios::binary);
    student s2;
    fin.read((char*)&s2,sizeof(s2));
    fin.close();
    s2.showData();
    return 0;
}