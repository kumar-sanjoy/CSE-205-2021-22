#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

vector<pair<int, int>> schedule(vector<pair<int, int>> v) {
    vector<pair<int, int>> ans;

    sort(all(v), [] (const pair<int, int> &a, const pair<int, int> &b) {
        return a.second < b.second;
    });

    ans.push_back(v[0]);
    for(int i = 1; i < v.size(); i++) {
        if(ans.back().second <= v[i].first) {
            ans.push_back(v[i]);
        }
    }

    return ans;
}

int main() {
    int n; cin >> n;

    vector<pair<int, int>> v(n);
    for(auto &x: v) cin >> x.first >> x.second;

    auto ans = schedule(v);
    for(auto x: ans) cout << x.first << ' '  << x.second << endl;
}