#include<iostream>
using namespace std;

class Fraction{
    private:
        int n,d;
    public:
        void getData(int n , int d){
            this->n = n;
            this->d = d;
        }
        friend void addFraction(Fraction frac1,Fraction frac2);
};

void addFraction(Fraction frac1, Fraction frac2){
    if(frac1.d == frac2.d){
        cout << (frac1.n+frac2.n) << "/" << frac1.d << endl;
    }
    else{
        cout << (frac1.n*frac2.d + frac1.d*frac2.n) << "/" << (frac1.d*frac2.d)<<endl;
    }
}

int main(){
    Fraction frac1,frac2,frac3,frac4;
    frac1.getData(4,5);
    frac2.getData(3,5);

    frac3.getData(4,6);
    frac4.getData(2,3);

    addFraction(frac1,frac2);
    
    addFraction(frac3,frac4);

    return 0;
}