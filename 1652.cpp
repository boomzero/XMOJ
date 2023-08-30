#include <bits/stdc++.h>
using namespace std;
struct Point
{
    int x, y;
    Point()
    {
        x = 0, y = 0;
    }
} route[10000];
int side[20][20];
int n, m, f1, f2, z1, z2;
int dy[4] = {0, 1, 0, -1}, dx[4] = {-1, 0, 1, 0};
bool flag = false;
void dfs(int x, int y, int step)
{
    if (x == z1 && y == z2)
    {
        for (int i = 0; i < step; i++)
            printf("(%d,%d)->", route[i].x, route[i].y);
        printf("(%d,%d)\n", x, y);
        flag = true;
        return;
    }
    route[step].x = x;
    route[step].y = y;
    for (int i = 0; i < 4; i++)
    {
        if (side[x + dx[i]][y + dy[i]] == 1)
        {
            side[x][y] = 0;
            dfs(x + dx[i], y + dy[i], step + 1);
            side[x][y] = 1;
        }
    }
}
int main()
{
    memset(side, 0, sizeof(side));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &side[i][j]);
        }
    }
    scanf("%d%d%d%d", &f1, &f2, &z1, &z2);
    dfs(f1, f2, 0);
    if (!flag)
        printf("-1\n");
    return 0;
}
