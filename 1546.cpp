#include <bits/stdc++.h>

using namespace std;
int h[100005] = {0}, n, len = 1, g[100005] = {0};

int main() {
    freopen("lis.in", "r", stdin);
    freopen("lis.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    g[1] = h[1];
    for (int i = 2; i <= n; ++i) {
        int j = lower_bound(g + 1, g + 1 + len, h[i]) - g;
        g[j] = h[i];
        len = max(len, j);
    }
    cout << len << endl;
    return 0;
}
