#include <bits/stdc++.h>
#define maxn 5010
using namespace std;
int sum[maxn + 10][maxn + 10];
int main()
{
    int n, r;
    scanf("%d%d", &n, &r);
    for (int i = 0, x, y, v; i < n; i++)
    {
        scanf("%d%d%d", &x, &y, &v);
        sum[x + 1][y + 1] = v;
    }
    for (int i = 1; i <= maxn; i++)
        for (int j = 1; j <= maxn; j++)
            sum[i][j] += sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
    int maxx = 0;
    for (int i = r; i <= maxn; i++)
        for (int j = r; j <= maxn; j++)
            maxx = max(maxx, sum[i][j] - sum[i - r][j] - sum[i][j - r] + sum[i - r][j - r]);
    printf("%d\n", maxx);
}
