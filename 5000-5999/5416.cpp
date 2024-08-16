#include <bits/stdc++.h>

using namespace std;
int a[100006] = {0}, n, dp[100006] = {0}, len = 1;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dp[1] = a[1];
    for (int i = 2; i <= n; ++i) {
        int pos = upper_bound(dp + 1, dp + len + 1, a[i]) - dp;
        dp[pos] = a[i];
        len = max(len, pos);
    }
    cout << len << endl;
    return 0;
}
