#include <bits/stdc++.h>

using namespace std;

int n, ans, f[6005][2]; // 1上司来，0上司不来

int main()
{

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &f[i][1]);

    ans = f[1][1];

    for (int i = 1; i < n; i++)
    {

        int a, b;

        scanf("%d%d", &a, &b);

        f[b][1] += f[a][0];

        f[b][0] += max(f[a][0], f[a][1]);

        ans = max(ans, f[b][1]);

        ans = max(ans, f[b][0]);
    }

    printf("%d", ans);

    return 0;
}
