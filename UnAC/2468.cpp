#include <bits/stdc++.h>
using namespace std;
char grid[150][150] = {{0}};
bool vis[150][150] = {{false}};
int xMod[] = {0, 1, -1, 0, 0}, yMod[] = {0, 0, 0, 1, -1};
int maxAns = 0, ans = 0, n, m;
void dfs(int x, int y)
{
    vis[x][y] = true;
    for (int i = 1; i <= 4; ++i)
    {
        if (grid[x + xMod[i]][y + yMod[i]] == '.' /*|| grid[x + xMod[i]][y + yMod[i]] == '@'*/)
        {
            if (!vis[x + xMod[i]][y + yMod[i]])
            {
                ans++;
                if (ans > maxAns)
                    maxAns = ans;
                dfs(x + xMod[i], y + yMod[i]);
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    int x, y;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            grid[i][j] = getchar();
            if (grid[i][j] == '\n')
                grid[i][j] = getchar();
            if (grid[i][j] == '@')
            {
                x = i;
                y = j;
            }
        }
    }
    ans = 1;
    if (ans > maxAns)
        maxAns = ans;
    dfs(x, y);
    cout << maxAns << endl;
}
