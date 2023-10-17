#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    vector<Node*> children;
};

// Hàm tính chiều cao của cây
int calculateHeight(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int maxHeight = -1;
    for (Node* child : root->children) {
        int height = calculateHeight(child);
        maxHeight = max(maxHeight, height);
    }

    return maxHeight + 1;
}

// Hàm duyệt cây theo thứ tự trước (preorder traversal)
void preorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    for (Node* child : root->children) {
        preorderTraversal(child);
    }
}

// Hàm duyệt cây theo thứ tự sau (postorder traversal)
void postorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    for (Node* child : root->children) {
        postorderTraversal(child);
    }

    cout << root->data << " ";
}

// Hàm kiểm tra xem cây đã cho có phải là cây nhị phân hay không
bool isBinaryTree(Node* root) {
    if (root == nullptr) {
        return true;
    }

    if (root->children.size() > 2) {
        return false;
    }

    for (Node* child : root->children) {
        if (!isBinaryTree(child)) {
            return false;
        }
    }

    return true;
}

// Hàm duyệt cây theo thứ tự giữa (inorder traversal)
void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    if (root->children.size() > 2) {
        cout << "NOT BINARY TREE";
        return;
    }

    if (root->children.size() == 2) {
        inorderTraversal(root->children[0]);
    }

    cout << root->data << " ";

    if (root->children.size() == 2) {
        inorderTraversal(root->children[1]);
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<Node*> nodes(N);
    for (int i = 0; i < N; i++) {
        nodes[i] = new Node();
        nodes[i]->data = i + 1;
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        nodes[u - 1]->children.push_back(nodes[v - 1]);
    }

    Node* root = nodes[0];

    // Tính chiều cao của cây
    int height = calculateHeight(root);
    cout << height << endl;

    // In ra thứ tự các nút theo thứ tự duyệt theo thứ tự trước
    preorderTraversal(root);
    cout << endl;

    // In ra thứ tự các nút theo thứ tự duyệt theo thứ tự sau
    postorderTraversal(root);
    cout << endl;

    // Kiểm tra xem cây đã cho có phải là cây nhị phân hay không
    if (isBinaryTree(root)) {
        // In ra thứ tự các nút theo thứ tự duyệt theo thứ tự giữa
        inorderTraversal(root);
    } else {
        cout << "NOT BINARY TREE";
    }

    return 0;
}
