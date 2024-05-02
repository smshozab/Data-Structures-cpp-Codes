#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{   
    cout << endl << "For array having a size of 50" << endl << endl << endl;
    int key,arr[50],random,count=0;
    cout << "Unsorted Array, having random values is:" << endl << endl;
    for (int i=0;i<50;i++){
        random=rand() % 100;
        arr[i]=random;
        cout << arr[i] << " ";
    }
    
    for(int i=1;i<50;i++){
        key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
            count++;
        }
        arr[j+1]=key;
    }
    
    
    cout << endl << "Sorted array is:" << endl << endl;
    for (int i=0;i<50;i++){
        cout << arr[i] << " ";
    }
    
    cout << endl << endl << "Number of comparisons performed by the inner array: " << count << endl << endl;
    
    int comparisons=0;
    for (int i=0;i<50;i++){
        cout << arr[i] << " ";
        comparisons++;
        
    }
    
    cout << "The number of comparisons in completely sorted array of 50 numbers: " << comparisons;
    
    
    
    cout << endl << "For array having a size of 100" << endl << endl << endl;
    int arr1[100],random1,count1=0;
    cout << "Unsorted Array having random values is:" << endl << endl;
    for (int i=0;i<100;i++){
        random1=rand() % 100;
        arr1[i]=random1;
        cout << arr1[i] << " ";
    }
    
        for(int i=1;i<100;i++){
        key=arr1[i];
        int j=i-1;
        while(j>=0 && arr1[j]>key){
            arr1[j+1]=arr1[j];
            j=j-1;
            count1++;
        }
        arr1[j+1]=key;
    }


    cout  << endl << endl << "Updated array is:" << endl << endl;
    for (int i=0;i<100;i++){
        cout << arr1[i] << " ";
    }
    
    cout << endl << "Number of comparisons performed by the inner array: " << count1;
    
    cout << endl << "Unsorted array having half sorted values and half unsorted: " << endl << endl;
    for (int i=0;i<25;i++){
        random1=rand() % 100;
        arr[i]=random1; 
        cout << arr[i] << " ";
    }
    
    int count2=0;
    // cout << "Sorted Array" << endl;
    for(int i=1;i<50;i++){
        key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
            count2++;
        }
        arr[j+1]=key;
    }
    cout << endl << "Sorted array is:" << endl << endl;
    for (int i=0;i<50;i++){
        cout << arr[i] << " ";
    }

    cout << endl << endl << "Number of comparisons performed by the inner array: " << count2 << endl << endl;

    return 0;
}
