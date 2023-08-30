#include <bits/stdc++.h>
using namespace std;
int n, l, d, p;
int a[10010];
int l1[10010];
int r[10010];
bool vis[100010];
int dis[100010];
int dp[2][100010];
int main()
{
    cin >> n >> l;
    d = l / (n - 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        l1[i] = max((i - 1) * d, l - (n - i) * (d + 1));
        r[i] = min((i - 1) * (d + 1), l - (n - i) * d);
    }
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    dp[p][0] = a[1];
    for (int i = 2; i <= n; ++i)
    {
        int p1 = p;
        for (int j = l1[i]; j <= r[i]; ++j)
        {
            dp[p ^ 1][j] = dp[p][j - d];
            if (j - d - 1 >= l1[i - 1])
                dp[p ^ 1][j] = min(dp[p ^ 1][j], dp[p][j - d - 1]);
            dp[p ^ 1][j] += abs(j - a[i]);
        }
        p ^= 1;
    }
    cout << dp[p][l];
    return 0;
}
