// #include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
    Node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* makeTree(vector<int> v, int start, int end) {
    if(start > end) return nullptr;
    
    int mid = (start + end) / 2;
    Node* root = new Node (v[mid]);
    root->left = makeTree(v, start, mid-1);
    root->right = makeTree(v, mid+1, end);

    return root;
}

void makeArray(Node* root, vector<int> &v) {
    if(!root) return;

    makeArray(root->left, v);
    v.push_back(root->data);
    makeArray(root->right, v);
}

Node* mergeBST(Node* head1, Node* head2) {
    vector<int> v1, v2, mergedNodes;

    makeArray(head1, v1);
    makeArray(head2, v2);

    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(mergedNodes)); // O(m+n);
    // mergedNodes.erase(unique(mergedNodes.begin(), mergedNodes.end()), mergedNodes.end()); // O(m+n);

    // for(auto x: mergedNodes) cout << x << " ";
    // cout << endl;

    return makeTree(mergedNodes, 0, mergedNodes.size()-1);
}

void printBst(Node* root) {
    if(root == nullptr) return;

    printBst(root->left);
    cout << root->data << ' ';
    printBst(root->right);
}

int main() {
    Node* head1 = new Node (10);
    head1->left = new Node (8);
    head1->right = new Node (15);

    Node* head2 = new Node (14);
    head2->left = new Node (12);
    head2->right = new Node (16);

    Node* root = mergeBST(head1, head2);
    printBst(root);
    cout << endl;
    // printBst(root);
    printBst(head1);
    cout << endl;
    printBst(head2);
}