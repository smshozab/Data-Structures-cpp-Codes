#include <iostream>
#include <cstring>

using namespace std;

class Memory_Array {
private:
    int size;
    int capacity; // Track the capacity of the array
    int *vals;

public:
    Memory_Array() {
        size = 0;
        capacity = 0;
        vals = NULL;
    }

    Memory_Array(int s) {
        size = 0;
        capacity = s;
        vals = new int[capacity];
    }

    Memory_Array(const Memory_Array& other) {
        size = other.size;
        capacity = other.capacity;
        vals = new int[capacity];
        memcpy(vals, other.vals, sizeof(int) * size);
    }

    Memory_Array& operator=(const Memory_Array& other) {
        if (this == &other)
            return *this;

        delete[] vals;
        vals = NULL;

        size = other.size;
        capacity = other.capacity;
        vals = new int[capacity];
        memcpy(vals, other.vals, sizeof(int) * size);

        return *this;
    }

    ~Memory_Array() {
        delete[] vals;
        vals = NULL;
    }

    void fillArray() {
        cout << "Enter " << capacity << " values: ";
        for (int i = 0; i < capacity; ++i) {
            cin >> vals[i];
        }
        size = capacity;
    }

    void insert(int element) {
    // if (size == capacity) {
    //     // If the array is full, double the capacity
    //     capacity *= 2;
    //     int *temp = new int[capacity];
    //     memcpy(temp, vals, sizeof(int) * size);
    //     delete[] vals;
    //     vals = temp;
    // }
    // vals[size] = element;
    // size++;
    // vals = new int[capacity+1];
    // vals[capacity+1]=element;
    int *temp = new int[capacity + 1];
    memcpy(temp, vals, sizeof(int) * size); // Copy elements from the old array
    temp[size] = element; // Insert the new element at the end
    delete[] vals; // Delete the old array
    vals = temp; // Update the pointer
    size++; // Increment size
    capacity++;
}


    void deleteLast() {
        if (size == 0) {
            cout << "Array is empty" << endl;
            return;
        }

        size--;
    }

    int getElementAt(int index) const {
        if (index < 0 || index >= size) {
            cout << "Invalid index" << endl;
            return -1;
        }

        return vals[index];
    }

    int printarray(){
    for (int i=0;i<size;i++){
        cout << vals[i];
    }
    }

    int getsize() const{
        cout << sizeof(vals);
    }
};

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    Memory_Array arr(size);

    cout << "Filling the array:" << endl;
    arr.fillArray();

    
    cout << "Deleted last element" << endl;
    arr.deleteLast();
    // cout << "Updated array" << endl;
    // for (int i=0;i<size;i++){
    //     cout << *(arr+i);
    // }

    cout << "Inserted element: 100" << endl;
    arr.insert(100);

    cout << "Elements at 1st index in the array:" << endl;
        cout << arr.getElementAt(1) << " ";
    cout << endl;

    cout << "Modified Array: " << arr.printarray() << " ";

    return 0;
}
