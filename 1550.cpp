#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x[400] = {0}, dp[400][400] = {0}, y[400] = {0};
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        y[i - 1] = x[i];
    }
    cin >> y[n];
    memset(dp, 20, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        dp[i][i] = 0;
    }
    for (int q = 2; q <= n; q++) {
        for (int i = 1, j = i + q - 1; j <= n; ++i, j++) {
            for (int k = i; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + x[i] * y[k] * y[j]);
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}
