#include <bits/stdc++.h>

using namespace std;

int n, m, a[1010], s[1010], dp[1010][1010], mx[1010][1010];

int main()

{

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i)

        scanf("%d", &a[i]), s[i] = s[i - 1] + a[i];

    for (int i = 1; i <= m; ++i)
    {

        for (int j = 1; j <= n; ++j)

            dp[i][j] = 0x8e8e8e8e;

        dp[i][i] = mx[i][i] = s[i];

        for (int j = i + 1; j <= n; ++j)
        {

            dp[i][j] = max(dp[i][j - 1], mx[i - 1][j - 1]) + a[j];

            mx[i][j] = max(mx[i][j - 1], dp[i][j]);
        }
    }

    printf("%d\n", mx[m][n]);

    return 0;
}
