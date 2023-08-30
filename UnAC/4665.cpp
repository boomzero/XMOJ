#include <bits/stdc++.h>
using namespace std;
int n, k, z, dp[100005] = {0};
bool inv[100005] = {false};
const long long mod = 1000000007;
int main() {
    freopen("feeling.in", "r", stdin);
    freopen("feeling.out", "w", stdout);
    cin >> n >> k >> z;
    for (int i = 1; i <= z; ++i) {
        int q;
        cin >> q;
        inv[q] = true;
    }
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (i - j >= 0 && !inv[i - j]) {
                dp[i] += dp[i - j];
                dp[i] %= mod;
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}
