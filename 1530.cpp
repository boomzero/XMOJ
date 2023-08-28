#include <bits/stdc++.h>

using namespace std;
int dp[2005] = {0};

int main() {
    int v, n;
    cin >> v >> n;
    int m[200] = {0}, c[200] = {0}, w[200] = {0};
    for (int i = 1; i <= n; ++i) {
        cin >> m[i] >> c[i] >> w[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (m[i] == 0) {
            for (int j = v; j >= c[i]; --j) {
                dp[j] = max(dp[j], dp[j - c[i]] + w[i]);
            }
        } else {
            for (int j = c[i]; j <= v; ++j) {
                dp[j] = max(dp[j], dp[j - c[i]] + w[i]);
            }
        }
    }
    cout << dp[v] << endl;
    return 0;
}


