#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
char grid[1005][1005] = {{0}};
bool vis[1005][1005] = {{false}};
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0}, ans = 0;
void dfs(int cx, int cy)
{
    vis[cx][cy] = true;
    if (!vis[cx - 1][cy])
        ans++;
    else
        ans--;
    if (!vis[cx][cy - 1])
        ans++;
    else
        ans--;
    if (!vis[cx + 1][cy])
        ans++;
    else
        ans--;
    if (!vis[cx][cy + 1])
        ans++;
    else
        ans--;
    for (int i : dx)
    {
        for (int j : dy)
        {
            if (!vis[cx + i][cy + j] && grid[cx + i][cy + j] == 'X')
                dfs(cx + i, cy + j);
        }
    }
}
int main()
{
    cin >> n >> m >> x >> y;
    memset(grid, '.', sizeof(grid));
    for (int i = 1; i <= n; ++i)
    {
        string in;
        cin >> in;
        int p = 0;
        for (char j : in)
        {
            p++;
            grid[i][p] = j;
        }
    }
    dfs(x, y);
    cout << ans << endl;
    return 0;
}
