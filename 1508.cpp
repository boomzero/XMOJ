#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, v, c[600] = {0}, w[600] = {0},q;
    int f[20001] = {0};
    cin >> v >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> q >>c[i] >> w[i];
    }
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; ++i) {
        for (int j = c[i]; j <= v; ++j) {
            f[j] = max(f[j], f[j - c[i]] + w[i]);
        }
    }
    cout << f[v] << endl;
    return 0;
}
