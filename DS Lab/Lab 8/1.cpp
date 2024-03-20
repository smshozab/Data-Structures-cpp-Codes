#include <iostream>
using namespace std;

class Stack {
private:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int topIndex;

public:
    Stack() {
        topIndex = -1;
    }

    bool IsEmpty() {
        return topIndex == -1;
    }

    bool IsFull() {
        return topIndex == MAX_SIZE - 1;
    }

    void Push(int data) {
        if (IsFull()) {
            cout << "Stack overflow! Cannot push element." << endl;
            return;
        }
        topIndex++;
        arr[topIndex] = data;
        cout << "Pushed " << data << " onto the stack." << endl;
    }

    void Pop() {
        if (IsEmpty()) {
            cout << "Stack underflow! Cannot pop element." << endl;
            return;
        }
        int poppedElement = arr[topIndex];
        topIndex--;
        cout << "Popped " << poppedElement << " from the stack." << endl;
    }

    int Top() {
        if (IsEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return arr[topIndex];
    }
};

int main() {
    Stack stack;
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);

    cout << "Top element: " << stack.Top() << endl;

    stack.Pop();
    cout << "Top element after pop: " << stack.Top() << endl;

    stack.Pop();
    stack.Pop();
    stack.Pop();

    return 0;
}
