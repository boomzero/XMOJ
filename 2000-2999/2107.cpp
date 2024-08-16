#include <bits/stdc++.h>

using namespace std;
bool dp[50000] = {false};

int main() {
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int ans = 0;
        memset(dp, 0, sizeof(dp));
        int a[200] = {0}, n, max = -1;
        cin >> n;
        for (int j = 1; j <= n; ++j) {
            cin >> a[j];
            if (a[j] > max) max = a[j];
        }
        sort(a + 1, a + n + 1);
        for (int j = 1; j <= n; ++j) {
            if (dp[a[j]]) continue;
            ans++;
            dp[a[j]] = true;
            for (int k = a[j]; k <= max; ++k) {
                if (dp[k - a[j]]) dp[k] = true;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

