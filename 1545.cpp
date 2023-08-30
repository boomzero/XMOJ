#include <bits/stdc++.h>

using namespace std;

char s1[1005], s2[1005];

int len, lcs, dp[1005][1005];

int LCS(int i, int j)

{

    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] >= 0)
        return dp[i][j];

    if (s1[i] == s2[j])

        dp[i][j] = LCS(i - 1, j - 1) + 1;

    else

        dp[i][j] = max(LCS(i - 1, j), LCS(i, j - 1));

    return dp[i][j];
}

int main()

{

    cin >> s1;

    len = strlen(s1);

    for (int i = 0; i < len; ++i)

        s2[i] = s1[len - 1 - i];

    memset(dp, -1, sizeof(dp));

    lcs = LCS(len - 1, len - 1);

    cout << len - lcs;

    return 0;
}
