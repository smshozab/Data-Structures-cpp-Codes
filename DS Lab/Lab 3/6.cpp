#include <iostream>
using namespace std;

struct Book {
    string title;
    int dueDate; 
};

void insertionSort(Book books[], int n) {
    for (int i=1;i<n;++i) {
        Book key=books[i];
        int j=i-1;
        while (j>=0 && books[j].dueDate>key.dueDate) {
            books[j+1]=books[j];
            j=j-1;
        }
        books[j+1]=key;
    }
}

int main() {
    const int num = 5;
    Book books[num] = {
        {"Book 1", 5},
        {"Book 2", 3},
        {"Book 3", 7},
        {"Book 4", 1},
        {"Book 5", 4}
    };

    cout << "Books before sorting:" << endl;
    for (int i=0;i<num;++i) {
        cout << books[i].title << " Due Date:" << books[i].dueDate << endl;
    }

    insertionSort(books, num);

    cout << "\nBooks after sorting:" << endl;
    for (int i=0;i<num;++i) {
        cout << books[i].title << " Due Date:" << books[i].dueDate << endl;
    }
    return 0;
}