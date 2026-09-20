#ifndef InsertArray_HPP
#define InsertArray_HPP
#include<iostream>
using namespace std;
void insertAtLast(int arr[],int &capacity,int value){
    arr[capacity] = value;
    capacity++;
    cout << endl << arr[capacity] << endl;
    cout << endl << "Inserted At Last "<<endl;
}
void insertAtFirst(int arr[],int &capacity, int value){
    for(int i=capacity ; i>0 ; i--){
        arr[capacity] = arr[capacity-1];
    }
    arr[0] = value;
    capacity++;
    cout << endl << "Inserted At First "<<endl;
}
void insertAfterPosition(int arr[] , int &capacity, int pos, int val){
    capacity++;
    int n = capacity;
    for(int i=capacity ; i>pos; i--){
        arr[n] = arr[n-1];
        n--;
    }
    arr[pos] = val;
}
void insertAfterValue(int arr[],int &capacity,int val_pos, int val){
    int n = capacity;
    for(int i=0; i<capacity ; i++){
        if(arr[i]==val_pos){
            capacity++;
            for(int j=capacity ; j>i ; j--){
                arr[n] = arr[n-1];
                n--;
            }
            arr[i] = val;
            break;
        }
        else{
            cout << endl << "Value not found "<<endl;
            break;
        }
    }

}

class Array{
    private:
        int *arr;
        int capacity=0;
    public:
        void createArray(int size);
        void insertValues();
        void printArray();
};
void Array::createArray(int size){
    arr = new int[size]{10,20,30,40,50};
    capacity = size;
}
void Array::printArray(){

    for(int i=0; i<capacity ; i++){
        cout << "\033[31m"<< arr[i] << "\033[0m" << " ";
    }
    cout << endl;
}
void Array::insertValues(){
    cout << endl<<"________Enter_______"<<endl;
    cout << "1->Insert At Last "<<endl;
    cout << "2->Insert At First "<<endl;
    cout << "3->Insert After given position "<<endl;
    cout << "4->Insert After Given Value "<<endl;
    int choice;
    cin>>choice;
    switch(choice){
        int val;
        int pos;
        int val_pos;
        case 1:{
            cout << "Enter value to be inserted ";
            cin>>val;
            insertAtLast(arr,capacity,val);
            printArray();
        }
            break;
            
        case 2 :{
            cout << "Enter value to be inserted ";
            cin>>val;
            insertAtFirst(arr,capacity,val);
            printArray();
        }
            break;
        case 3:{
            cout << "Enter position ";
            cin>>pos;
            cout<< "Enter value ";
            cin>>val;
            insertAfterPosition(arr,capacity ,pos,val);
            printArray();
        }
            break;
        case 4:{
            cout << "Enter value(pos) 1: ";
            cin>>val_pos;
            cout << "Enter value(real) ";
            cin>>val;
            insertAfterValue(arr,capacity,val_pos,val);
            printArray();
        }
            break;
        default:
            cout << "Invalid choice : "<<endl;
    }
}
#endif