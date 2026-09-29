#include<iostream>
using namespace std;

void bubbleSort(int arr[], int size){
    for(int i=0 ; i<size-1 ; i++){
        for(int j=0 ; j<size-i-1 ; j++){
            if(arr[j]>arr[j+1]){
                arr[j] = arr[j]^arr[j+1];
                arr[j+1] = arr[j]^arr[j+1];
                arr[j] = arr[j]^arr[j+1];
            }
        }
    }
}

void insertionSort(int arr[] , int size){
    for(int i=1; i<size ; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void display(int arr[], int size){
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl; // Added for a clean new line
}


int main(){

    int arr[] =  {8,7,6,2,4,9,2};
    int brr[] = {8,7,6,2,4,9,2};

    int size1 = sizeof(brr)/sizeof(brr[0]);
    int size2 = sizeof(arr)/sizeof(arr[0]);

    display(arr,size1);
    bubbleSort(arr,size1);
    display(arr,size1);
    cout << endl;

    display(brr,size2);
    insertionSort(brr,size2);
    display(brr,size2);
    cout << endl;

    return 0;
}

