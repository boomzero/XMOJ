#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("credit.in", "r", stdin);
    freopen("credit.out", "w", stdout);
    long long v = -1, n[105] = {0}, k = -1, c[105][105] = {{0}}, w[105][105] = {{0}}, dp[2000] = {0};
    while (v != 0 && k != 0) {
        memset(n, 0, sizeof(n));
        memset(c, 0, sizeof(c));
        memset(dp, 0, sizeof(dp));
        cin >> k >> v;
        if (k == 0 && v == 0) break;
        for (int i = 1; i <= k; ++i) {
            n[i] = v;
            for (int j = 1; j <= n[i]; ++j) {
                cin >> w[i][j];
                c[i][j] = j;
            }
        }
        for (int i = 1; i <= k; ++i) {
            for (int j = v; j >= 0; --j) {
                for (int l = 1; l <= n[i]; ++l) {
                    if (j >= c[i][l])
                        dp[j] = max(dp[j], dp[j - c[i][l]] + w[i][l]);
                }
            }
        }
        cout << dp[v] << endl;
    }
    return 0;
}
