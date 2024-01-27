#include <iostream>
#include <iomanip>
using namespace std;

void maximum(int index, int &max, int size, int matrix[]){
//    int max=0;
    if (index==size){
        return;
    }

    if(matrix[index]>max){
        max=matrix[index];
    }
    // else{
    //     max=matrix[index+1]
    // }
    //recrsive call
    maximum(index+1, max, size, matrix);
}

void posneg(int index, int size, int &countp, int &countn, int matrix[]) {
    // Base case
    if (index == size) {
        return;
    }

    if (matrix[index] > 0) {
        countp++;
    } 
	else if (matrix[index] < 0) {
        countn++;
    }
    // else if (matrix[index]==0){
    // 	cout << "ERROR" << endl;
	// }

    // Recursive call
    posneg(index + 1, size, countp, countn, matrix);
}

int main() {
    int s;
    cout << "Enter the size of the matrix: " << endl;
    cin >> s;

    int matrix[100];

    // Taking input
    for (int i = 0; i < s; i++) {
        cout << "Enter the value at index " << i << " in the matrix: ";
        cin >> matrix[i];
    }

    int countp = 0, countn = 0;
	int max=0;
    // function 1 call
    posneg(0, s, countp, countn, matrix);

    cout << "Count of positive elements: " << countp << endl;
    cout << "Count of negative elements: " << countn << endl;

    //function 2 call
    maximum(0,max,s,matrix);
    cout << "The max element is: " << max << endl;

    return 0;
}
