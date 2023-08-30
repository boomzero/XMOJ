#include <bits/stdc++.h>
using namespace std;
int n, dp[5005] = {0}, a[5005] = {0};
int main() {
    freopen("jump.in", "r", stdin);
    freopen("jump.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int &i: dp) {
        i = numeric_limits<int>::max();
    }
    dp[0] = dp[1] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= a[i]; ++j) {
            dp[i + j] = min(dp[i + j], dp[i] + 1);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
