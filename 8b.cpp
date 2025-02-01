#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

void dfs(int node, vector<int> adj[], vector<bool> &vis) {
    vis[node] = true;
    for(auto adjNode: adj[node]) {
        if(!vis[adjNode]) dfs(adjNode, adj, vis);
    }
}
 
int components(vector<int> adj[], int n) {
    vector<bool> vis(n, false); // 0 based graph
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i, adj, vis);
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n, e; cin >> n >> e;

    vector<int> adj[n];
    for(int i = 0; i < e; i++) {
        int u, v; cin >> u >> v;

        adj[u].push_back(v);
    }

    cout << "Edges needed: \n";
    cout << components(adj, n) - 1 << endl;

}