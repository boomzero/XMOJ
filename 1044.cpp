#include <bits/stdc++.h>

using namespace std;

int n, c, d[2][100010], num[100010], col[100010];

long long sum[2][100010], maxx;

int main()

{

    freopen("sum.in", "r", stdin);

    freopen("sum.out", "w", stdout);

    scanf("%d%d", &n, &c);

    for (int i = 1; i <= n; i++)
    {

        scanf("%d", &num[i]);

        num[i] %= 10007;
    }

    for (int i = 1; i <= n; i++)
    {

        scanf("%d", &col[i]);

        sum[i & 1][col[i]] = (sum[i & 1][col[i]] + num[i]) % 10007;

        ++d[i & 1][col[i]];
    }

    for (int i = 1; i <= n; i++)
    {

        maxx += i * (sum[i & 1][col[i]] + (d[i & 1][col[i]] - 2) * num[i]);

        maxx %= 10007;
    }

    printf("%lld\n", maxx);

    return 0;
}
