#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3FFF'FFFF'FFFF'FFFF;
const ll N = 105;
const ll dx[4] = {-1, 0, 0, 1};
const ll dy[4] = {0, -1, 1, 0};
ll n, k, Map[N][N];
bool Visited[N][N];
vector<pair<ll, ll>> Vector;
void Output()
{
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= 10; j++)
            printf("%lld", Map[i][j]);
        printf("\n");
    }
}
void DFS(int x, int y, int d)
{
    if (x < 1 || x > n || y < 1 || y > 10 || Visited[x][y] || Map[x][y] != d)
        return;
    Vector.push_back({x, y});
    Visited[x][y] = true;
    for (ll i = 0; i < 4; i++)
        DFS(x + dx[i], y + dy[i], d);
}
bool MoreDFS()
{
    memset(Visited, false, sizeof(Visited));
    bool Flag = false;
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= 10; j++)
            if (Map[i][j] != 0)
            {
                Vector.clear();
                DFS(i, j, Map[i][j]);
                if (Vector.size() >= k)
                {
                    for (auto &i : Vector)
                        Map[i.first][i.second] = 0;
                    Flag = true;
                }
            }
    return Flag;
}
void Down()
{
    for (ll j = 1; j <= 10; j++)
        for (ll i = 1; i < n; i++)
            if (Map[i][j] != 0 && Map[i + 1][j] == 0)
            {
                swap(Map[i][j], Map[i + 1][j]);
                i = 0;
            }
}
int main()
{
    scanf("%lld%lld", &n, &k);
    for (ll i = 1; i <= n; i++)
    {
        char c[11];
        scanf("%s", c + 1);
        for (ll j = 1; j <= 10; j++)
            Map[i][j] = c[j] - '0';
    }
    while (true)
    {
        if (!MoreDFS())
            break;
        Down();
    }
    Output();
    return 0;
}
