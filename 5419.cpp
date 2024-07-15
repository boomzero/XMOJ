#include <bits/stdc++.h>

using namespace std;
int n, a[1005][1005] = {{0}}, dp[1005][1005][2] = {{{0}}};

int main() {
    cin >> n;
    memset(a, -1, sizeof(a));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> a[i][j];
        }
    }
    dp[1][1][0] = a[1][1];
    dp[1][1][1] = 2 * a[1][1];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i][j][0] = max(dp[i - 1][j][0] + a[i][j], dp[i - 1][j - 1][0] + a[i][j]);
            dp[i][j][1] = max(max(dp[i - 1][j][1] + a[i][j], dp[i - 1][j - 1][1] + a[i][j]),
                              max(dp[i - 1][j][0] + 2 * a[i][j], dp[i - 1][j - 1][0] + 2 * a[i][j]));
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, dp[n][i][1]);
    }
    cout << ans << endl;
    return 0;
}

