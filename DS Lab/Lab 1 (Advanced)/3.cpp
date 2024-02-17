#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n" << endl;
    cin >> n;
    int *array = new int[n];
    int *count = new int[n];
    fill(count, count + n, 1);
    // int array[100], count[100]={1,1,1,1,1};
    for (int i=0;i<n;i++) {
        cout << "Enter " << i + 1 << " element: ";
        cin >> array[i];
    }

    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (array[i]==array[j]){
                count[i]++;
            }
        }
    }
    int max_count=count[0];
    for (int i=1;i<n;i++){
            if (count[i]>max_count){
                max_count=count[i];
                // cout << array[i];
            }
    }
    int a,coutn=0,min=array[0];
    for (int i=0;i<n;i++){
        if (count[i]==max_count){
            // cout << array[i];
            coutn++;
            if(coutn>1){
                if(min>array[i]){
                    min=array[i];
                }
            }
            else{
                min=array[i];
            }
            // a=coutn;
        }
    }
    cout << min;
    // cout << a;
    delete[] array;
    delete[] count;

    return 0;
}