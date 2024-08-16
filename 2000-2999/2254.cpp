#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int hm[205], tmd[205], dp[800][800];

signed main() {
    freopen("energy.in", "r", stdin);
    freopen("energy.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> hm[i];
        tmd[i - 1] = hm[i];
    }
    tmd[n] = hm[1];
    for (int i = 1; i <= n; ++i) {
        tmd[i + n] = tmd[i];
        hm[i + n] = hm[i];
    }
    n *= 2;
    for (int i = 1; i <= n; ++i) {
        dp[i][i] = 0;
    }
    for (int q = 2; q <= n; q++) {
        for (int i = 1, j = i + q - 1; j <= n; ++i, j++) {
            for (int k = i; k < j; ++k) {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + hm[i] * tmd[k] * tmd[j]);
            }
        }
    }
    int maxn = numeric_limits<int>::min();
    for (int i = 1; i <= n; i++) {
        maxn = max(maxn, dp[i][i + n / 2 - 1]);
    }
    cout << maxn << endl;
    return 0;
}
