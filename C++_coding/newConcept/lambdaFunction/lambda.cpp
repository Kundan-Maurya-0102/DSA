#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Sample{
    public:
        int operator()(int a,int b){
            if(a>b)
                return a;
            return b;
        }
};



int main(){
    vector<int>vc = {10,20,30,40,50,60,70};
    sort(vc.begin(),vc.end(),[](int a, int b){
        return a>b;
    });
    for(auto x : vc){
        cout << x << " ";
    }
    return 0;
}

// int main(){
//     int a=10,b=20;
//     [=,&a]()->void{
//         cout << a << " " << b << endl;
//         a = 50;
//     }();
//     cout << a << " " << b << endl;
//     return 0;
// }


