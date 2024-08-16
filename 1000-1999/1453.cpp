#include <bits/stdc++.h>

using namespace std;
int fa[1001];
int rootId[1001] = {0};

int find(int t) {
    if (fa[t] == t) return t;
    return fa[t] = find(fa[t]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        fa[x] = y;
    }
}

int main() {
    int t;
    int n, m;
    int a, b;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n + 1; ++i) {
            rootId[i] = fa[i] = 0;
        }
        for (int i = 0; i < n; ++i) {
            fa[i + 1] = i + 1;
        }
        for (int i = 0; i < m; ++i) {
            cin >> a >> b;
            merge(a, b);
        }
        int ans = 0;
        for (int i = n; i >= 1; i--) {
            rootId[find(i)]++;
        }
        for (int i = 1; i <= n; ++i) {
            if (rootId[i] % 10 == 0) {
                ans += rootId[i] / 10;
            } else {
                ans += rootId[i] / 10 + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

