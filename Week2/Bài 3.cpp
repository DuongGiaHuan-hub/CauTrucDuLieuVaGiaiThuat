#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void insert(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (*head == nullptr) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

int count_triplets(Node* head) {
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
        return 0;
    }

    int count = 0;
    Node* current = head->next;

    while (current->next != nullptr) {
        Node* prevNode = current->prev;
        Node* nextNode = current->next;

        while (prevNode != nullptr && nextNode != nullptr) {
            int sum = prevNode->data + current->data + nextNode->data;

            if (sum == 0) {
                count++;
            }

            prevNode = prevNode->prev;
            nextNode = nextNode->next;
        }

        current = current->next;
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        insert(&head, num);
    }

    cout << count_triplets(head) << endl;

    return 0;
}
