#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f, MAX = 110;
int dx[16] = {0, 1, 2, 3, 2, 1, 0, -1, -2, -3, -2, -1, -1, 1, 0, 0}, dy[16] = {3, 2, 1, 0, -1, -2, -3, -2, -1, 0, 1, 2, 0, 0, -1, 1};
int n, t, a[MAX][MAX], dist[MAX][MAX], ans = INF;
priority_queue<pair<int, pair<int, int>>> pq;
int main()
{
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
    memset(dist, 0x3f, sizeof(dist));
    dist[0][0] = 0;
    pq.push(make_pair(0, make_pair(0, 0)));
    while (!pq.empty())
    {
        int d = -pq.top().first, r = pq.top().second.first, c = pq.top().second.second;
        pq.pop();
        if (d != dist[r][c])
        {
            continue;
        }
        int d2 = abs(n - 1 - r) + abs(n - 1 - c);
        if (d2 <= 2)
        {
            ans = min(ans, d + d2 * t);
        }
        for (int i = 0; i < 16; ++i)
        {
            int nr = r + dx[i], nc = c + dy[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n)
            {
                continue;
            }
            if (dist[nr][nc] < d + a[nr][nc] + 3 * t)
            {
                continue;
            }
            dist[nr][nc] = d + a[nr][nc] + 3 * t;
            pq.push(make_pair(-dist[nr][nc], make_pair(nr, nc)));
        }
    }
    printf("%d", ans);
    return 0;
}
