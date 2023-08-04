#include <bits/stdc++.h>
using namespace std;
const int dx[8] = {1, 2, 1, 2, -1, -2, -1, -2};
const int dy[8] = {2, 1, -2, -1, 2, 1, -2, -1};
const int N = 55;
int x, y, Answer, Distances[N][N];
void GoInto50()
{
    while (x + y > 50)
    {
        if (x < y)
            swap(x, y);
        if (x - 4 < y * 2)
            y -= 2;
        x -= 4;
        Answer += 2;
    }
}
void BFS()
{
    memset(Distances, -1, sizeof(Distances));
    queue<pair<int, int>> Queue;
    Distances[0][0] = 0;
    Queue.push(make_pair(0, 0));
    while (!Queue.empty())
    {
        int ux = Queue.front().first, uy = Queue.front().second;
        Queue.pop();
        for (int i = 0; i < 8; i++)
        {
            int tx = ux + dx[i], ty = uy + dy[i];
            if (tx < 0 || ty < 0 || tx > 100 || ty > 100)
                continue;
            if (Distances[tx][ty] != -1)
                continue;
            Distances[tx][ty] = Distances[ux][uy] + 1;
            Queue.push(make_pair(tx, ty));
        }
    }
    Answer += Distances[x][y];
}
int main()
{
    // freopen("knight.in", "r", stdin);
    // freopen("knight.out", "w", stdout);
    int xp, yp, xs, ys;
    scanf("%d%d%d%d", &xp, &yp, &xs, &ys);
    x = abs(xp - xs);
    y = abs(yp - ys);
    GoInto50();
    BFS();
    printf("%d\n", Answer);
    return 0;
}
