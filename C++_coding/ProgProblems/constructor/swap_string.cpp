#include<iostream>
using namespace std;
int main(){
char arr[] = "kundan Maurya";
int size = sizeof(arr)/sizeof(arr[0]);
char *p = arr;
char *q = &arr[size-1];

while(p<q){
    (*p) = (*p)^(*q);
    (*q) = (*p)^(*q);
    (*p) = (*p)^(*q);
    p++;
    q--;
}

for(int i=0 ; i<size ; i++)
    cout << arr[i];
cout << endl;
return 0;
}
