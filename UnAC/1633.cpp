#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<int, int> dot;
int n, m, dirX[] = {0, 0, 1, -1}, dirY[] = {1, -1, 0, 0};
dot start, endd;
char grid[150][150] = {{'\0'}};
bool vis[150][150] = {{false}};
int currS = 0;
map<dot, int> stackSize;
void bfs()
{
    queue<dot> q;
    q.push(start);
    vis[start.x][start.y] = true;
    stackSize[make_pair(start.x, start.y)] = currS;
    while (!q.empty())
    {
        dot c = q.front();
        currS = stackSize[make_pair(c.x, c.y)];
        if (grid[c.x][c.y] == 'E')
        {
            cout << currS << endl;
            break;
        }
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = c.x + dirX[i], ny = c.y + dirY[i];
            if (ny <= 0 || nx <= 0 || nx > n || ny > m)
                continue;
            if (vis[nx][ny] || grid[nx][ny] == '#')
                continue;
            vis[nx][ny] = true;
            stackSize[make_pair(nx, ny)] = currS + 1;
            q.emplace(nx, ny);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        string in;
        cin >> in;
        int j = 0;
        for (char c : in)
        {
            j++;
            grid[i][j] = c;
            if (c == 'S')
            {
                start = make_pair(i, j);
            }
            else if (c == 'E')
            {
                endd = make_pair(i, j);
            }
        }
    }
    bfs();
    if (!vis[endd.x][endd.y])
    {
        puts("-1\n");
    }
    return 0;
}
