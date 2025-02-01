#include <bits/stdc++.h>
using namespace std;

int kthLargest(vector<int> &arr, int k) {
    int n = arr.size();
    vector<int> pf(n + 1, 0);
    for (int i = 0; i < n; i++)
        pf[i + 1] = pf[i] + arr[i];

    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int sum = pf[j] - pf[i - 1];

            if (minHeap.size() < k)
                minHeap.push(sum);
            else if (sum > minHeap.top()) {
                minHeap.pop();
                minHeap.push(sum);
            }
        }
    }
    return minHeap.top();
}

int main() {
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(auto &x : v) cin >> x;

    cout << kthLargest(v, k) << endl;
}