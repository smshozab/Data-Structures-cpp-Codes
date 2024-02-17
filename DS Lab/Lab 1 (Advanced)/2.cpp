#include<iostream>
using namespace std;

int main(){
    int arr[5];
    int *ptr_array=arr;
    // int *(arr)+5;
    int max=0,min=0;
    
    for (int i=0;i<5;i++){
        cin >> *(ptr_array+i);
    }

    max=*ptr_array;
    min=*ptr_array;
    for (int i=0;i<5;i++){
            if (*(ptr_array+i)>max){
                max=*(ptr_array+i);
            }
    }
    for (int i=0;i<5;i++){
            if (*(ptr_array+i)<min){
                min=*(ptr_array+i);
            }
    }

    cout << "The max value is:" << max << endl;
    cout << "The min value is:" << min << endl;
}