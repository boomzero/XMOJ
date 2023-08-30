#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100010
#define mod 100007
#define lowbit(x) ((x) & (-x))

struct Point
{
    int x, y;
    bool friend operator<(Point a, Point b)
    {
        return a.x < b.x;
    }
} p[N];
int n, m, k;
int dp[N][15][2], bit[N][15][2];

void add(int p, int a, int b, int v)
{
    for (int i = p; i < N; i += lowbit(i))
        bit[i][a][b] = (bit[i][a][b] + v) % mod;
}
int query(int p, int a, int b)
{
    int sum = 0;
    for (int i = p; i; i -= lowbit(i))
        sum = (sum + bit[i][a][b]) % mod;
    return sum;
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &p[i].x, &p[i].y);
    sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        dp[i][0][0] = dp[i][0][1] = 1;
        add(p[i].y, 0, 0, 1);
        add(p[i].y, 0, 1, 1);
        for (int j = 1; j <= k; ++j)
        {
            dp[i][j][0] = (dp[i][j][0] + query(p[i].y - 1, j, 0) + query(p[i].y - 1, j - 1, 1)) % mod;
            dp[i][j][1] = (dp[i][j][1] + query(N - 1, j, 1) - query(p[i].y, j, 1) + query(N - 1, j - 1, 0) - query(p[i].y, j - 1, 0)) % mod;
            if (dp[i][j][1] < 0)
                dp[i][j][1] += mod;
            add(p[i].y, j, 0, dp[i][j][0]);
            add(p[i].y, j, 1, dp[i][j][1]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = (ans + dp[i][k][0] + dp[i][k][1]) % mod;
    printf("%d\n", ans);
    return 0;
}
