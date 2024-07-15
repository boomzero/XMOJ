#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[100005] = {0}, n, s, t, l;
bool hs[100005] = {false};

signed main() {
    cin >> l >> s >> t >> n;
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        hs[p] = true;
    }
    memset(dp, 25, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= l+5; ++i) {
        for (int j = s; j <= t; j++) {
            if (i - j < 0) continue;
            int cv = 0;
            if (hs[i]) cv = 1;
            dp[i] = min(dp[i], dp[i - j] + cv);
        }
    }
    cout << min(dp[l],dp[l+1]) << endl;
    return 0;
}
