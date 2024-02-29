#include <iostream>
using namespace std;

class Item {
public:
    string object;
    int age;
    float price;
};

int main() {
    int n;
    cout << "How many items are there?" << endl;
    cin >> n;

    Item *items = new Item[n];

    for (int i=0;i<n;i++) {
        cout << "Enter age " << i + 1 << endl;
        cin >> items[i].age;
        cout << "Enter price " << i + 1 << endl;
        cin >> items[i].price;
        cout << "Enter object " << i + 1 << endl;
        cin >> items[i].object;
    }

    cout << "Before Sorting" << endl;
    cout << "Age: ";
    for (int i=0;i<n;i++) {
        cout << items[i].age << " ";
    }
    cout << endl << "Price: ";
    for (int i=0;i<n;i++) {
        cout << items[i].price << " ";
    }
    cout << endl << "Item: ";
    for (int i=0;i<n;i++) {
        cout << items[i].object << " ";
    }

    // Sorting
    for (int i=0;i<n-1;i++) {
        for (int j=0;j<n-i-1;j++) {
            if (items[j].age > items[j+1].age || (items[j].age == items[j+1].age && items[j].price < items[j+1].price)) {
                swap(items[j], items[j + 1]);
            }
        }
    }

    cout << endl << endl << "After Sorting" << endl;
    cout << "Age: ";
    for (int i=0;i<n;i++) {
        cout << items[i].age << " ";
    }
    cout << endl << "Price: ";
    for (int i=0;i<n;i++) {
        cout << items[i].price << " ";
    }
    cout << endl << "Item: ";
    for (int i=0;i<n;i++) {
        cout << items[i].object << " ";
    }

    delete[] items;
    return 0;
}