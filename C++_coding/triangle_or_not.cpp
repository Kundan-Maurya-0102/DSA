#include<iostream>
using namespace std;

bool is_triangle(float a, float b, float c){
    if (a <= 0 || b <= 0 || c <= 0) 
        return false;
    if((a+b)>c && (a+c)>b && (b+c)>a)
        return true;
    return false;
}

int main(){
    cout << "Enter sides of triangle " << endl ;
    float a,b,c;
    cin>>a>>b>>c;
    if(is_triangle(a,b,c))
        cout << "yes this is valid triangle \n and its perimeter is : " << (a+b+c)/3.0;
    else 
        cout << "This is not a valid triangle " << endl;

    return 0;
}