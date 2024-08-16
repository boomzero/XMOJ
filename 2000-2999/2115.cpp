#include <bits/stdc++.h>
using namespace std;
vector<int> g[100005], rg[100005];
int in[100005], dp[100005];

int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b; //a eats b
        g[b].emplace_back(a);
        in[a]++;
        rg[a].emplace_back(b);
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            dp[i] = 1;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int c = q.front();
        q.pop(); //first, we get a item from the queue
        for (auto i: rg[c]) {
            dp[c] += dp[i];
        }
        for (auto i: g[c]) {
            in[i]--;
            if (in[i] == 0) {
                q.push(i);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (g[i].empty() && (!rg[i].empty())) {
            ans += dp[i];
        }
    }
    cout << ans << endl;
    return 0;
}

