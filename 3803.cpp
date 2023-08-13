#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3FFF'FFFF'FFFF'FFFF;
const ll N = 105;
const ll dx[4] = {-1, 0, 0, 1};
const ll dy[4] = {0, -1, 1, 0};
ll n, TurnRecord[N][N][4], Answer = INF;
pair<ll, ll> Start, End;
bool Map[N][N];
void BFS()
{
    queue<tuple<ll, ll, ll>> Queue;
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= n; j++)
            for (ll k = 0; k < 4; k++)
                TurnRecord[i][j][k] = INF;
    for (ll i = 0; i < 4; i++)
    {
        Queue.push({Start.first, Start.second, i});
        TurnRecord[Start.first][Start.second][i] = 0;
    }
    while (!Queue.empty())
    {
        auto [x, y, Direction] = Queue.front();
        Queue.pop();
        for (ll i = 0; i < 4; i++)
        {
            ll nx = x + dx[i];
            ll ny = y + dy[i];
            ll Turns = TurnRecord[x][y][Direction];
            if (nx < 1 || nx > n || ny < 1 || ny > n || !Map[nx][ny])
                continue;
            if (Direction != i)
                Turns++;
            if (TurnRecord[nx][ny][i] > Turns)
            {
                TurnRecord[nx][ny][i] = Turns;
                Queue.push({nx, ny, i});
            }
        }
    }
}
int main()
{
    freopen("maze.in", "r", stdin);
    freopen("maze.out", "w", stdout);
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++)
    {
        char Buffer[N] = {0};
        scanf("%s", Buffer + 1);
        for (ll j = 1; j <= n; j++)
        {
            Map[i][j] = (Buffer[j] != 'x');
            if (Buffer[j] == 'A')
                Start = {i, j};
            else if (Buffer[j] == 'B')
                End = {i, j};
        }
    }
    BFS();
    for (ll i = 0; i < 4; i++)
        Answer = min(Answer, TurnRecord[End.first][End.second][i]);
    printf("%lld\n", (Answer == INF ? -1 : Answer));
    return 0;
}
