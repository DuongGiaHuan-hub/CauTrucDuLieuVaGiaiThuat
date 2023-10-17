#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};
class Linklist{
public:
    Linklist(){
        head = nullptr;
        size = 0;
    }
    void insert(int p, int x)
    {
        Node* new_node = new Node;
        new_node->data = x;
        if(p == 0)
        {
            new_node->next = head;
            head = new_node;
        }
        else
        {
            Node* prev_node = get_node(p - 1);
            new_node->next = prev_node->next;
            prev_node->next = new_node;
        }
        size++;
    }
    void remove(int p){
        Node* node_to_delete;
        if(p == 0){
            node_to_delete = head;
            head = head->next;
        }
        else
        {
            Node* prev_node = get_node(p - 1);
            node_to_delete = prev_node->next;
            prev_node->next = node_to_delete->next;
        }
        delete node_to_delete;
        size--;
    }
    void print()
    {
        Node* current_node = head;
        while (current_node != NULL) {
            cout << current_node->data << " ";
            current_node = current_node->next;
        }
    }
private:
    Node* head;
    int size;
    Node* get_node(int p)
    {
         Node* current_node = head;
        for (int i = 0; i < p; i++) {
            current_node = current_node->next;
        }
        return current_node;
    }
};

int main()
{
    Linklist list;
    int n, p, x;
    cin >> n;
    string s;

    for(int i = 0; i < n; i++){
        cin >> s >> p;

        if(s == "insert")
        {
            cin >> x;
            list.insert(p, x);
        }
        else if(s == "delete")
        {
            list.remove(p);
        }
    }
    list.print();

    return 0;
}
