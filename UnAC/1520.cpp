#include <bits/stdc++.h>
using namespace std;
long long v, tw, n, c[200] = {0}, w[200] = {0}, t[200] = {0}, dp[2000][2000] = {{0}};
int main()
{
    cin >> v >> tw >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> c[i] >> w[i] >> t[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = v; j >= c[i]; --j)
        {
            for (int k = tw; k >= w[i]; --k)
            {
                dp[j][k] = max(dp[j][k], dp[j - c[i]][k - w[i]] + t[i]);
            }
        }
    }
    cout << dp[v][tw] << endl;
    return 0;
}
