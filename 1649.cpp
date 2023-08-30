#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, a[1010][1010], ans = 0, vis[1010][1010];
void dfs(int x, int y)
{
    for (int x2 = x - 1; x2 <= x + 1; ++x2)
        for (int y2 = y - 1; y2 <= y + 1; ++y2)
        {
            if (a[x2][y2] == 1 && !vis[x2][y2])
            {
                vis[x2][y2] = 1;
                dfs(x2, y2);
            }
            else if (abs(x2 - x) + abs(y2 - y) == 1 && a[x2][y2] == 0)
            {
                ++ans;
            }
        }
}
int main()
{
    scanf("%d%d%d%d", &n, &m, &x, &y);
    char str[1010];
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", str);
        for (int j = 1; j <= m; ++j)
            a[i][j] = (str[j - 1] == 'X');
    }
    vis[x][y] = 1;
    dfs(x, y);
    printf("%d\n", ans);
    return 0;
}
