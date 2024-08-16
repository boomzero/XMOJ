#include <bits/stdc++.h>

using namespace std;
int price[105][105] = {0}, dp[10005];

int main() {
    freopen("souvenir.in", "r", stdin);
    freopen("souvenir.out", "w", stdout);
    int t, n, m;
    cin >> t >> n >> m;
    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> price[i][j];
        }
    }
    for (int i = 1; i <= t; i++) {
        memset(dp, 0, sizeof(dp));
        for (int j = 1; j <= n; j++) {
            for (int k = price[i][j]; k <= m; k++) {
                dp[k] = max(dp[k], dp[k - price[i][j]] + price[i + 1][j] - price[i][j]);
            }
        }
        m += dp[m];
    }
    cout << m << endl;
    return 0;
}
