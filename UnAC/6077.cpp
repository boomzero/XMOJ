#include <bits/stdc++.h>
using namespace std;
int h, n;
int wt[505], dp[45005];
int main() {
    cin >> h >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> wt[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = h; j >= wt[i]; j--) {
            dp[j] = max(dp[j], dp[j - wt[i]] + wt[i]);
        }
    }
    cout << dp[h] << endl;
    return 0;
}
