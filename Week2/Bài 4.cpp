#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class Queue {
private:
    Node* head;
    Node* tail;

public:
    Queue() {
        head = nullptr;
        tail = nullptr;
    }

    void enqueue(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void dequeue() {
        if (head == nullptr) {
            cout << "Queue is empty." << endl;
        } else {
            Node* temp = head;
            head = head->next;

            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }

            delete temp;
        }
    }

    void display() {
            Node* current = head;

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

    Queue queue;

    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;

        if (operation == "enqueue") {
            int x;
            cin >> x;
            queue.enqueue(x);
        } else if (operation == "dequeue") {
            queue.dequeue();
        }
    }

    queue.display();

    return 0;
}
