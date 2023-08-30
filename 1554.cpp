#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("stone.in", "r", stdin);
    freopen("stone.out", "w", stdout);
    int n, val[800] = {0}, dp[800][800] = {0}, sum[800] = {0};
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> val[i];
    }
    for (int i = 1; i <= n; ++i) {
        val[i + n] = val[i];
    }
    n *= 2;
    memset(dp, 20, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        dp[i][i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + val[i];
    }
    for (int q = 2; q <= n; q++) {
        for (int i = 1, j = i + q - 1; j <= n; ++i, j++) {
            for (int k = i; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
            }
        }
    }
    int minn = INT32_MAX;
    for (int i = 1; i <= n; i++) {
        minn = min(minn, dp[i][i + n / 2 - 1]);
    }
    cout << minn << endl;
    return 0;
}
