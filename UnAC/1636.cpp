#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<int, int> dot;
int n, m, dirX[] = {0, -2, -1, 1, 2, 2, 1, -1, -2}, dirY[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
dot start, endd;
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
        if (c.x == endd.x && c.y == endd.y)
        {
            cout << currS << endl;
            break;
        }
        q.pop();
        for (int i = 0; i < 9; i++)
        {
            int nx = c.x + dirX[i], ny = c.y + dirY[i];
            if (ny <= 0 || nx <= 0 || nx > n || ny > m)
                continue;
            if (vis[nx][ny])
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
    cin >> start.x >> start.y;
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> endd.x >> endd.y;
        memset(vis, false, sizeof(vis));
        stackSize.clear();
        currS = 0;
        bfs();
    }
    return 0;
}
