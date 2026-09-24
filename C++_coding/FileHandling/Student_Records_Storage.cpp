#include<string>
#include<iostream>
#include<fstream>
using namespace std;
class student{
    private:
        string name;
        int roll;
        int marks;
    public:
        void get_Data(){
            cin >> this->name;
            cin >> this->roll;
            cin >> this->marks;
        }
        void display(){
            cout << roll << " " << endl << name  << " " << marks << " " << endl; 
        }
        string getName()const{
            return name;
        }
        int getRoll()const{
            return roll;
        }
        int getMarks()const{
            return marks;
        }
};

int input(){
    return 2;
}

int main(){
    student s1,s2,s3;
    s1.get_Data();
    s2.get_Data();
    s3.get_Data();

    ofstream fout;
    fout.open("student.txt",ios::app|ios::binary);
    fout << s1.getName() << " " << s1.getRoll() << " " << s1.getMarks()  << endl;
    fout << s2.getName() <<  " " << s2.getRoll() << " " << s3.getMarks() << endl ;
    fout << s3.getName() <<  " " << s3.getRoll() <<  " " << s3.getMarks() << endl;

    fout.close();

    return 0;
}