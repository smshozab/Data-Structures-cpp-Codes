#include <iostream>
#include <stack>
#include <vector> // for vector used in the function template
#include <algorithm>

using namespace std;

template<typename T>
class Stack {
private:
    vector<T> elements;

public:
    bool operator==(const Stack<T>& otherStack) const {
        return elements == otherStack.elements;
    }

    void Push(T element) {
        elements.push_back(element);
    }

    void Pop() {
        if (!IsEmpty()) {
            elements.pop_back();
        }
    }

    T Top() const {
        if (!IsEmpty()) {
            return elements.back();
        }
        return T();
    }

    bool IsEmpty() const {
        return elements.empty();
    }
};

template<typename T>
bool operator==(const Stack<T>& stack1, const Stack<T>& stack2) {
    return stack1 == stack2;
}

int main() {
    Stack<int> stack1;
    stack1.Push(1);
    stack1.Push(2);
    stack1.Push(3);

    Stack<int> stack2;
    stack2.Push(1);
    stack2.Push(2);
    stack2.Push(3);

    Stack<int> stack3;
    stack3.Push(1);
    stack3.Push(4);
    stack3.Push(3);

    cout << "stack1 == stack2: " << boolalpha << (stack1 == stack2) << endl; // true
    cout << "stack1 == stack3: " << boolalpha << (stack1 == stack3) << endl; // false

    return 0;
}
