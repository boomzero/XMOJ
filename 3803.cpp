#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int INF = 0x3FFF'FFFF;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
int n, Map[N][N];
namespace BF
{
    int Answer = INF, CurrentAnswer;
    bool Visited[N][N];
    struct POINT
    {
        int x, y;
    } Start, End;
    bool operator==(const POINT &a, const POINT &b)
    {
        return a.x == b.x && a.y == b.y;
    }
    void DFS(POINT x, int LastDirection)
    {
        if (x == End)
        {
            Answer = min(Answer, CurrentAnswer);
            return;
        }
        else if (CurrentAnswer >= Answer)
            return;
        for (int i = 0; i < 4; i++)
        {
            POINT New = {x.x + dx[i], x.y + dy[i]};
            if (New.x < 0 || New.x >= n || New.y < 0 || New.y >= n ||
                Map[New.x][New.y] == 1 || Visited[New.x][New.y])
                continue;
            Visited[New.x][New.y] = true;
            if (LastDirection != -1 && LastDirection != i)
                CurrentAnswer++;
            DFS(New, i);
            if (LastDirection != -1 && LastDirection != i)
                CurrentAnswer--;
            Visited[New.x][New.y] = false;
        }
    }
    void Solve()
    {
        for (int i = 0; i < n; i++)
        {
            char Temp[N];
            scanf("%s", Temp);
            for (int j = 0; j < n; j++)
                if (Temp[j] == 'x')
                    Map[i][j] = 1;
                else if (Temp[j] == 'A')
                    Start = {i, j};
                else if (Temp[j] == 'B')
                    End = {i, j};
        }
        DFS(Start, -1);
        printf("%d\n", Answer);
    }
}
namespace SOLVE
{
    int maze[N][N];
    int Visited[N][N][4];
    int sx, sy, ex, ey;
    struct NODE
    {
        int x, y, dir, turns;
        bool operator<(const NODE &a) const
        {
            return turns > a.turns;
        }
    };
    int BFS()
    {
        priority_queue<NODE> q;
        set<pair<int, int>> st;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        q.push({sx, sy, -1, 0});
        st.insert({sx, sy});
        while (!q.empty())
        {
            NODE cur = q.top();
            q.pop();
            if (cur.x == ex && cur.y == ey)
            {
                return cur.turns;
            }
            for (int i = 0; i < 4; i++)
            {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if (nx < 1 || nx > n || ny < 1 || ny > n || maze[nx][ny] == 1)
                    continue;
                int turns = cur.turns;
                if (cur.dir != -1 && (cur.dir + i) % 2 == 1)
                    turns++;
                if (st.count({nx, ny}) && Visited[nx][ny][i] <= turns)
                    continue;
                q.push({nx, ny, i, turns});
                st.insert({nx, ny});
                Visited[nx][ny][i] = turns;
            }
        }
        return -1;
    }
    void Solve()
    {
        for (int i = 1; i <= n; i++)
        {
            char c[N];
            scanf("%s", c);
            for (int j = 1; j <= n; j++)
            {
                if (c[j - 1] == 'x')
                {
                    maze[i][j] = 1;
                }
                else if (c[j - 1] == 'A')
                {
                    sx = i;
                    sy = j;
                }
                else if (c[j - 1] == 'B')
                {
                    ex = i;
                    ey = j;
                }
            }
        }
        printf("%d\n", BFS());
    }
}
int main()
{
    freopen("maze.in", "r", stdin);
    freopen("maze.out", "w", stdout);
    scanf("%d", &n);
    if (n < 30)
        BF::Solve();
    else
        SOLVE::Solve();
    return 0;
}
