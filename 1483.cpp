#include <bits/stdc++.h>

using namespace std;
int n, m;
const int mn = 10010;
vector<int> g[mn], scc[mn + 1];
bool inStack[mn];
int dfn[mn], low[mn], idx, scc_cnt, in_scc[mn];
stack<int> st;

void tarjan(int u) {
    dfn[u] = low[u] = ++idx;
    inStack[u] = true;
    st.push(u);
    for (int i: g[u]) {
        if (!dfn[i]) {
            tarjan(i);
            low[u] = min(low[u], low[i]);
        } else if (inStack[i]) {
            low[u] = min(low[u], dfn[i]);
        }
    }
    if (dfn[u] == low[u]) {
        scc_cnt++;
        int c = 0;
        do {
            c = st.top();
            st.pop();
            inStack[c] = false;
            in_scc[c] = scc_cnt;
            scc[scc_cnt].emplace_back(c);
        } while (c != u);
    }
}

void solve() {
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
}

int out[mn], in[mn];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
    }
    solve();
    for (int i = 1; i <= n; ++i) {
        for (int j: g[i]) {
            if (in_scc[j] == in_scc[i]) continue;
            in[in_scc[j]]++;
            out[in_scc[i]]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= scc_cnt; ++i) {
        if (out[i] == 0) {
            ans++;
        }
    }
    if (ans != 1) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= scc_cnt; ++i) {
        if (out[i] == 0) {
            cout << scc[i].size() << endl;
        }
    }
    return 0;
}
