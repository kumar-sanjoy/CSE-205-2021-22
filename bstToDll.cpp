#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

// Helper function to perform in-order traversal and convert BST to DLL
void BstToDLLHelper(Node* root, Node*& head, Node*& prev) {
    if (!root) return;

    // Recursively convert left subtree
    BstToDLLHelper(root->left, head, prev);

    // If prev is null, it means we're at the leftmost node (smallest value)
    if (!prev) {
        head = root;  // Set head of DLL
    } else {
        prev->right = root; // Connect prev and current node
        root->left = prev;
    }
    prev = root; // Move prev to current node

    // Recursively convert right subtree
    BstToDLLHelper(root->right, head, prev);
}

// Wrapper function to convert BST to DLL
Node* BstToDLL(Node* root) {
    Node* head = nullptr;
    Node* prev = nullptr;
    BstToDLLHelper(root, head, prev);
    prev->right = head;
    head->left = prev;
    return head;
}

// Function to print DLL
void printDLL(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(20);

    Node* head = BstToDLL(root);
    printDLL(head);

    return 0;
}
