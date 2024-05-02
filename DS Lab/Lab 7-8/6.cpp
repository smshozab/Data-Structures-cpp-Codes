#include <iostream>
#include <queue>
using namespace std;

class Stack {
private:
    queue<int> q1;
    queue<int> q2;

public:
    void Push(int data) {
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(data);
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int Pop() {
        if (IsEmpty()) {
            cout << "Stack is empty. Cannot pop element." << endl;
            return -1;
        }
        int topElement = q1.front();
        q1.pop();
        return topElement;
    }

    int Top() {
        if (IsEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return q1.front();
    }

    bool IsEmpty() {
        return q1.empty();
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

    return 0;
}
