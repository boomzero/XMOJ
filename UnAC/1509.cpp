#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long v, n[105] = {0}, k, c[105][105] = {{0}}, w[105][105] = {{0}}, dp[2000] = {0};
    cin >> v >> k;
    for (int i = 1; i <= k; ++i)
    {
        cin >> n[i];
        for (int j = 1; j <= n[i]; ++j)
        {
            cin >> c[i][j] >> w[i][j];
        }
    }
    for (int i = 1; i <= k; ++i)
    {
        for (int j = v; j >= 0; --j)
        {
            for (int l = 1; l <= n[i]; ++l)
            {
                if (j >= c[i][l])
                    dp[j] = max(dp[j], dp[j - c[i][l]] + w[i][l]);
            }
        }
    }
    cout << dp[v] << endl;
    return 0;
}
