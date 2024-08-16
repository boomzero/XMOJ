#include <bits/stdc++.h>

using namespace std;
int n, m, in[100005], ans[100005];
vector<int> g[100005];

bool tps() {
    int cnt = 0;
    priority_queue<int, vector<int>, greater<>> q;
    for (int i = 1; i <= n; ++i) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int c = q.top();
        q.pop();
        ans[++cnt] = c;
        for (int i: g[c]) {
            if (--in[i] == 0) {
                q.push(i);
            }
        }
    }
    return cnt == n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].emplace_back(y);
        in[y]++;
    }
    if (tps()) {
        for (int i = 1; i <= n; ++i) {
            cout << ans[i] << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
