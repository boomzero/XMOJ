#include <bits/stdc++.h>
using namespace std;
int n, w[1005] = {0};
int dp[305][305] = {0};
int main()
{
    cin >> n;
    memset(dp, 23, sizeof(dp));
    for (int i = 1; i <= n; ++i)
    {
        cin >> w[i];
        dp[i][i] = 0;
        dp[i][i + 1] = 0;
    }
    for (int L = 2; L <= n; ++L)
    {
        for (int i = 1, j = i + L - 1; j <= n; i++, j++)
        {
            for (int k = i; k < j; ++k)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + w[i] + w[j] + w[k]);
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}
