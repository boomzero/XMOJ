#include <bits/stdc++.h>
using namespace std;
struct P
{
    int x, y, v;
};
queue<P> q;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n, m;
int sx, sy, ex, ey;
int tx[2][26], ty[2][26], cnt[26], a[310][310];
bool vis[310][310];
int dis[310][310];
int bfs()
{
    vis[sx][sy] = 1;
    q.push((P){sx, sy, 0});
    while (!q.empty())
    {
        P p = q.front();
        q.pop();
        int x = p.x;
        int y = p.y;
        int v = p.v;
        int x2, y2;
        char c;
        if (x == ex && y == ey)
            return v;
        for (int i = 0; i < 4; ++i)
        {
            x2 = x + dx[i], y2 = y + dy[i];
            c = a[x2][y2];
            if (x2 > 0 && x2 <= n && y2 > 0 && y2 <= m && c != '#')
            {
                if (c >= 'A' && c <= 'Z')
                {
                    if (x2 == tx[0][c - 'A'] && y2 == ty[0][c - 'A'])
                    {
                        x2 = tx[1][c - 'A'];
                        y2 = ty[1][c - 'A'];
                    }
                    else
                    {
                        x2 = tx[0][c - 'A'];
                        y2 = ty[0][c - 'A'];
                    }
                }
                if (!vis[x2][y2])
                {
                    vis[x2][y2] = 1;
                    q.push((P){x2, y2, v + 1});
                }
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        string x;
        cin >> x;
        for (int j = 1; j <= m; j++)
            a[i][j] = x[j - 1];
        for (int j = 1; j <= m; ++j)
        {
            char c = a[i][j];
            if (c == '@')
                sx = i, sy = j;
            else if (c == '=')
                ex = i, ey = j;
            else if (c >= 'A' && c <= 'Z')
            {
                tx[cnt[c - 'A']][c - 'A'] = i;
                ty[cnt[c - 'A']++][c - 'A'] = j;
            }
        }
    }
    cout << bfs();
}
