#include <iostream>
using namespace std;

int main() {
    int s,temp=0;
    cout << "Enter the size of the array: " << endl;
    cin >> s;

	int array[100];
	
    // Taking input
    for (int i = 0; i < s; i++) {
        cout << "Enter the value at index " << i << " in the array: ";
        cin >> array[i];
    }

    // int *ptr=&array[0];

    // int temp=*(array+0);
    
    for (int i = 0; i < s/2; i++){
        temp=*(array+i);
        *(array+i)=*(array+(s-1-i));
        *(array+(s-1-i))=temp;
    }
    // *(array+(s-1))=temp;

    cout << "Reversed Array:" << endl;
    for (int i = 0; i < s; i++){
        cout << *(array+i) << endl;
    }
}