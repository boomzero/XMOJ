#include <bits/stdc++.h>

using namespace std;

struct node
{

    int x, y, t;
};

int n, sx, sy, ex, ey;

bool vis[10100][10100];

string mp[10010];

queue<node> qu;

int dir[10][10] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool in(int x, int y)
{

    return 1 <= x && x <= n && 1 <= y && y <= n;
}

int BFS()
{

    node tmp;

    tmp.x = sx;

    tmp.y = sy;

    tmp.t = 0;

    qu.push(tmp);

    vis[sx][sy] = 1;

    while (!qu.empty())
    {

        node now = qu.front();

        qu.pop();

        for (int i = 0; i < 4; i++)
        {

            int tx = now.x + dir[i][0];

            int ty = now.y + dir[i][1];

            if (in(tx, ty) && mp[tx][ty] == '0' && vis[tx][ty] == 0)
            {

                if (tx == ex && ty == ey)
                {

                    return now.t + 1;
                }

                node tmp2;

                tmp2.x = tx;

                tmp2.y = ty;

                tmp2.t = now.t + 1;

                qu.push(tmp2);

                vis[tx][ty] = 1;
            }
        }
    }

    return -1;
}

int main()
{

    cin >> n;

    for (int i = 1; i <= n; i++)
    {

        cin >> mp[i];

        mp[i] = " " + mp[i];
    }

    cin >> sx >> sy >> ex >> ey;

    cout << BFS();

    return 0;
}
