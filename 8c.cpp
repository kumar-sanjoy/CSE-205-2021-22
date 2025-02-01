#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int data) {
    if(st.empty()) {
        st.push(data);
        return;
    }

    int topElement = st.top();
    st.pop();
    insertAtBottom(st, data);
    st.push(topElement);
}

void rev(stack<int> &st) {
    if(st.empty()) return;
    int topElement = st.top();
    st.pop();

    rev(st);
    insertAtBottom(st, topElement);
}

void printStack(stack<int> st) {
    while(!st.empty()) {
        int data = st.top();
        cout << data << ' ';
        st.pop();
    }
}

int main() {
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    rev(st);
    printStack(st);
}