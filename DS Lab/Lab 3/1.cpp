#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{	
	cout << "For array having a size of 50" << endl << endl;
	int arr[50],random,count=0;
	bool swapped;
	cout << "Unsorted Array, having random values is:" << endl << endl;
	for (int i=0;i<50;i++){
		random=rand() % 100;
		arr[i]=random;
		cout << arr[i] << " ";
	}
	
	for (int j=0;j<49;j++){
		swapped=false;
		for (int k=0;k<49-j;k++){
			if (arr[k]>arr[k+1]){
				swap(arr[k],arr[k+1]);
				count++;
				swapped=true;
			}
			if (swapped=false){
					break;
				}
		}
	}
	
	
	cout << endl << "Sorted array is:" << endl;
	for (int i=0;i<50;i++){
		cout << arr[i] << " ";
	}
	
	cout << endl << "Number of comparisons performed by the inner array: " << count << endl;
	
	int comparisons=0;
	for (int i=0;i<50;i++){
		cout << arr[i] << " ";
		comparisons++;
		
	}
	
	cout << "The number of comparisons in completely sorted array of 50 numbers: " << comparisons;
	
	
	
	cout << endl << "For array having a size of 100" << endl << endl;
	int arr1[100],random1,count1=0;
	cout << "Unsorted Array having random values is:" << endl << endl;
	for (int i=0;i<100;i++){
		random1=rand() % 100;
		arr1[i]=random1;
		cout << arr1[i] << " ";
	}
	
	for (int j=0;j<99;j++){
		for (int k=0;k<99-j;k++){
			if (arr1[k]>arr1[k+1]){
				swap(arr1[k],arr1[k+1]);
				count1++;
			}
		}
	}
	cout << endl << "Updated array is:" << endl;
	for (int i=0;i<100;i++){
		cout << arr1[i] << " ";
	}
	
	cout << endl << "Number of comparisons performed by the inner array: " << count1;
	
return 0;
}
