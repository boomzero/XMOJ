#include <bits/stdc++.h>

using namespace std;

int main() {
    int c[30] = {0}, w[30] = {0}, dp[30001] = {0}, n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> c[i] >> w[i];
        w[i] *= c[i];
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = n; j >= 0; --j) {
            if (j - c[i] >= 0)
                dp[j] = max(dp[j], dp[j - c[i]] + w[i]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}


