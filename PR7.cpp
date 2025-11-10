#include <iostream>
#include <string.h>
using namespace std;

const int MAX_SIZE = 100;

class Stack {
private:
    char arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop from an empty stack." << endl;
            return -1;
        }
        return arr[top--];
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MAX_SIZE - 1);
    }

    char peek() {
        if (isEmpty())
            return '\0';
        return arr[top];
    }
};

// Function to check whether parentheses are balanced or not
bool isBalanced(char exp[]) {
    Stack stack;
    for (int i = 0; i < strlen(exp); i++) {
        char ch = exp[i];

        // Push opening brackets
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        }
        // Check closing brackets
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.isEmpty())
                return false;

            char topChar = stack.pop();

            // Check matching pairs
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return false;
            }
        }
    }

    // If stack is empty → balanced
    return stack.isEmpty();
}

int main() {
    char exp[100];

    cout << "Enter the mathematical expression: ";
    cin.getline(exp, 100);

    if (isBalanced(exp))
        cout << "The expression is balanced." << endl;
    else
        cout << "The expression is NOT balanced." << endl;

    return 0;
}
