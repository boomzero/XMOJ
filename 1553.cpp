#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, val[400] = {0}, dp[400][400] = {0}, sum[400] = {0};
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> val[i];
    }
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
    cout << dp[1][n] << endl;
    return 0;
}
