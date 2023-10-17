#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = nullptr;

        if (top == nullptr) {
            top = newNode;
        } else {
            newNode->prev = top;
            top->next = newNode;
            top = newNode;
        }
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty." << endl;
        } else {
            Node* temp = top;
            top = top->prev;

            if (top != nullptr) {
                top->next = nullptr;
            }

            delete temp;
        }
    }

    void display() {
            Node* current = top;

            while (current->prev != nullptr) {
                current = current->prev;
            }
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
};

int main() {
    int n;
    cin >> n;

    Stack stack;

    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;

        if (operation == "push") {
            int x;
            cin >> x;
            stack.push(x);
        } else if (operation == "pop") {
            stack.pop();
        }
    }

    stack.display();

    return 0;
}
