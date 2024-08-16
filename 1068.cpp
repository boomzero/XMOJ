#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int fa[N], sizes[N];
int n, minn = INT_MAX;
int get(int u) {
    if (fa[u] != u) {
        int v = fa[u];
        fa[u] = get(fa[u]);
        sizes[u] += sizes[v];
    }
    return fa[u];
}
void merge(int u, int v) {
    int _u = get(u), _v = get(v);
    if (_u != _v) {
        fa[_u] = _v;
        sizes[u] = sizes[v] + 1;
    } else {
        minn = min(minn, sizes[u] + sizes[v] + 1);
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
    for (int u = 1; u <= n; ++u) {
        int v;
        cin >> v;
        merge(u, v);
    }
    cout << minn << '\n';
    return 0;
}
