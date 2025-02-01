#include <bits/stdc++.h>
using namespace std;

class Node {
    public: 
    int data;
    Node* next;
    Node* down;

    Node(int data) {
        this->data = data;
        next = down = nullptr;
    }
};

Node* convertToLL(Node* root) {
    if (!root) return nullptr;

    Node* head = new Node(root->data);
    Node* temp = head; 

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();

        while(curr) {
            if(curr->down) q.push(curr->down);
            if(curr != root) {
                temp->next = new Node(curr->data);
                temp = temp->next;
            }
            curr = curr->next;                
        }
    }

    return head;
}


void printLL(Node* head) {
    Node* temp = head;

    while(temp) {

        cout << temp->data << ' ';
        temp = temp->next;
    }

    cout << endl;
}

int main() {


    Node* head = new Node(10);
    head->next = new Node(5);
    head->next->next = new Node(12);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(11);

    head->down = new Node(4);
    head->down->next = new Node(20);
    head->down->next->next = new Node(13);

    head->down->next->down = new Node(2);
    head->down->next->next->down = new Node(16);
    head->down->next->next->down->down = new Node(3);

    head->next->next->next->down = new Node(17);
    head->next->next->next->down->down = new Node(9);
    head->next->next->next->down->down->next = new Node(8);
    head->next->next->next->down->down->down = new Node(19);
    head->next->next->next->down->down->down->next = new Node(15);


    Node* hello = convertToLL(head);
    printLL(hello);
}