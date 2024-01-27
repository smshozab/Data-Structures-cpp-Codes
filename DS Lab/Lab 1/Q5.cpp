#include <iostream>
using namespace std;

int main() {
    int s;
    cout << "Enter the size of the array: " << endl;
    cin >> s;

	int array[100];
	
    // Taking input
    for (int i = 0; i < s; i++) {
        cout << "Enter the value at index " << i << " in the array: ";
        cin >> array[i];
    }

    // int *ptr=&array[0];

    int temp=*(array+0);
    *(array+0)=*(array+(s-1));
    *(array+(s-1))=temp;

    cout << "Updated Array:" << endl;
    for (int i = 0; i < s; i++){
        cout << *(array+i) << endl;
    }
}