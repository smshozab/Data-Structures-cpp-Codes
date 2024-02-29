#include<iostream>
using namespace std;

void search(int n, int m, int **seat);

int main(){
    int n,m,random;
    cout << "Enter number of rows of a conference hall." << endl;
    cin >> n;
    cout << "Enter number of cols of a conference hall." << endl;
    cin >> m;

    if (n <= 0 || m <= 0) {
        cerr << "Error: Rows and columns must be positive integers." << endl;
        return 1;
    }

    int **seat=new int* [n];
    for (int i=0;i<n;i++){
        seat[i]=new int[m];
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            random=rand() % 2;
		    seat[i][j]=random;
		    cout << seat[i][j] << " ";
        }
        cout << endl;
    }   
    search(n,m,seat);

    try {
        search(n, m, seat);
    } catch(const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }

    for (int i=0;i<n;i++) {
        delete[] seat[i];
    }
    delete[] seat;

    return 0;
}

void search(int n, int m, int **seat){
    for (int i=0;i<n;i++){
        for (int j=i+1;j<m-2;j++){   
            if (seat[i][j]==0 && seat[i][j+1]==0 && seat[i][j+2]==0){
                cout << endl << "Following three seats are vacant and free to use: " << endl << "( " << i << " , "  << j << " ) " << endl << "( " << i << " , "  << j+1 << " ) " << endl << "( " << i << " , "  << j+2 << " ) " << endl;
            }
        }
    }

    for (int i=0;i<n-2;i++){
        for (int j=0;j<m;j++){   
            if (seat[i][j]==0 && seat[i+1][j]==0 && seat[i+2][j]==0){
                cout << endl << "Following three seats are vacant and free to use: " << endl << "( " << i << " , "  << j << " ) " << endl << "( " << i+1 << " , "  << j << " ) " << endl << "( " << i+2 << " , "  << j << " ) " << endl;
            }
        }
    }
}