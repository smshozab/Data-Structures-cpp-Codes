#include<iostream>
using namespace std;

class friends{
private:
    bool **arr;
    int row=5,col=5,i,j;

public:
    friends(){
        arr = new bool*[row];
        for(int i = 0; i < row; ++i)
            arr[i] = new bool[col];
    }  
    bool& operator()(int i, int j) {
        if (i < 0 || i >= row || j < 0 || j >= col) {
            throw out_of_range("Boundary Error");
        }
        return arr[i][j];
    }

    ~friends() {
        for(int i = 0; i < row; ++i)
            delete[] arr[i];
        delete[] arr;
    }
};

int main(){
    int key;
    friends f;
    for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){
            cout << "Enter 1 if row " << i << " and col " << j << " are friends" << endl;
            cin >> key;
            if (key==1){
                f(i,j)=true;
            }
            else{
                f(i,j)=NULL;
            }
            if (f(i,j)==true){
                f(i,j)="*";
            }  
        }
    }

    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 5; ++j) {
            cout << f(i, j) << " ";
        }
        cout << endl;
    }


}