#include <iostream>
#include <string>

using namespace std;

class Stack {
private:
    static const int MAX_SIZE = 100;
    char arr[MAX_SIZE];
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

    void Push(char symbol) {
        if (IsFull()) {
            cout << "Stack overflow! Cannot push element." << endl;
            return;
        }
        topIndex++;
        arr[topIndex] = symbol;
    }

    char Pop() {
        if (IsEmpty()) {
            cout << "Stack underflow! Cannot pop element." << endl;
            return '\0'; // Assuming '\0' denotes an empty character
        }
        char poppedSymbol = arr[topIndex];
        topIndex--;
        return poppedSymbol;
    }

    char Top() {
        if (IsEmpty()) {
            cout << "Stack is empty." << endl;
            return '\0'; // Assuming '\0' denotes an empty character
        }
        return arr[topIndex];
    }
};

bool hasMatchingSymbols(const string& expression) {
    Stack symbolStack;

    for (char symbol : expression) {
        if (symbol == '(' || symbol == '{' || symbol == '[') {
            symbolStack.Push(symbol);
        } else if (symbol == ')' || symbol == '}' || symbol == ']') {
            if (symbolStack.IsEmpty()) {
                return false; // Found a closing symbol without a matching opening symbol
            }
            char topSymbol = symbolStack.Pop();
            if ((symbol == ')' && topSymbol != '(') ||
                (symbol == '}' && topSymbol != '{') ||
                (symbol == ']' && topSymbol != '[')) {
                return false; 
            }
        }
    }

    return symbolStack.IsEmpty();
}

int main() {
    string expression1 = "{25 + (3 - 6) * 8}";
    string expression2 = "7 + 8 * 2";
    string expression3 = "5 + {(13 + 7) / 8 - 2 * 9";

    cout << "Expression 1: " << boolalpha << hasMatchingSymbols(expression1) << endl;
    cout << "Expression 2: " << boolalpha << hasMatchingSymbols(expression2) << endl;
    cout << "Expression 3: " << boolalpha << hasMatchingSymbols(expression3) << endl;

    return 0;
}
