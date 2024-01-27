#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	int row=0,
	col=0,
	matrix1[10][10]
	,matrix2[10][10]
	,sum[2][2]
	,sub[2][2]
	,mul[2][2]
	,div[2][2];
	
    cout << "Input the number of rows and cols" << endl;
	cin >> row;
	cin >> col;

	//Taking input in matrix 1
	for (int i=0;i<row;i++){
		for (int j=0;j<col;j++){
			cout << "In matrix 1, enter the value of " << i << " row and " << j << " col" << endl;
			cin >> matrix1[i][j];
		}
	}
	
	//Taking input in matrix 2
	for (int i=0;i<row;i++){
		for (int j=0;j<col;j++){
			cout << "In matrix 2, enter the value of " << i << " row and " << j << " col" << endl;
			cin >> matrix2[i][j];
		}
	}
	
	//Performing Matrix Addition
	for (int i=0;i<row;i++){
		for (int j=0;j<col;j++){
			sum[i][j]=matrix1[i][j]+matrix2[i][j];
		}
	}
	//Printing Matrix Addition
	cout << "Matrix Addition is as follows:";
	for (int i=0;i<row;i++){
		cout << "\n";
		for (int j=0;j<col;j++){
			cout << sum[i][j] << "\t";
		}
	}
	//Performing Matrix Sub
	for (int i=0;i<row;i++){
		for (int j=0;j<col;j++){
			sub[i][j]=matrix1[i][j]-matrix2[i][j];
		}
	}
	//Printing Matrix Sub
	cout << endl << "Matrix Sub is as follows:";
	for (int i=0;i<row;i++){
				cout << "\n";
		for (int j=0;j<col;j++){
			cout << sub[i][j] << "\t";
		}
	}	
    //Performing Matrix multiplication
	for (int i=0;i<row;i++){
		for (int j=0;j<col;j++){
			mul[i][j]=matrix1[i][j]*matrix2[i][j];
		}
	}
	//Printing Matrix multiplication
	cout << endl << "Matrix multiplication is as follows:";
	for (int i=0;i<row;i++){
				cout << "\n";
		for (int j=0;j<col;j++){
			cout << mul[i][j] << "\t";
		}
	}	
    //Performing Matrix division
	for (int i=0;i<row;i++){
		for (int j=0;j<col;j++){
			div[i][j]=matrix1[i][j]/matrix2[i][j];
		}
	}
	//Printing Matrix Division
	cout << endl << "Matrix division is as follows:";
	for (int i=0;i<row;i++){
				cout << "\n";
		for (int j=0;j<col;j++){
			cout << div[i][j] << "\t";
		}
	}
}
