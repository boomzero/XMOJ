#include <bits/stdc++.h>
#define Fox ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
const int N = 1e4 + 10;
const int INF = 0x3f3f3f3f;
int n, m, k, cnt;
int up[N], down[N];
int high[N], low[N], dp[10005][1005];
int main() {
    Fox;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> up[i] >> down[i];
    for (int i = 0; i <= n; i++)
        high[i] = m + 1, low[i] = -1;
    for (int i = 1, p, l, h; i <= k; i++) {
        cin >> p >> l >> h;
        high[p] = h, low[p] = l;
    }
    memset(dp, INF, sizeof(dp));
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = up[i - 1]; j <= m; j++)
            dp[i][j] = min(dp[i][j], min(dp[i - 1][j - up[i - 1]], dp[i][j - up[i - 1]]) + 1);
        for (int j = m - up[i - 1] + 1; j <= m; j++)
            dp[i][m] = min(dp[i][m], min(dp[i][j], dp[i - 1][j]) + 1);
        for (int j = 1; j + down[i - 1] <= m; j++)
            dp[i][j] = min(dp[i][j], dp[i - 1][j + down[i - 1]]);
        for (int j = 0; j <= low[i]; j++)
            dp[i][j] = INF;
        for (int j = high[i]; j <= m; j++)
            dp[i][j] = INF;
        int v = 0;
        for (int j = max(low[i] + 1, 1); j < high[i] && !v; j++)
            if (dp[i][j] != INF)
                v = 1;
        if (low[i] >= 0)
            cnt++;
        //for(int j=0;j<=m;j++)cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
        if (v)
            continue;
        cout << 0 << "\n" << cnt - 1;
        return 0;
    }
    int ans = INF;
    for (int i = 1; i <= m; i++)
        ans = min(ans, dp[n][i]);
    cout << 1 << "\n" << ans;
    return 0;
}
