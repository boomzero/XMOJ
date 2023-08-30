#include <cstdio>
#include <cstdlib>
#include <cstring>
const int mod = 1000000007, SIZE1 = 1005, SIZE2 = 40;
using namespace std;
int n, m, dp[SIZE1][SIZE2];
void dfs(int i, int j, int k, int p)
{
    if (j == n)
    {
        dp[i + 1][p] += dp[i][k];
        dp[i + 1][p] %= mod;
        return;
    }
    if (((1 << j) & k) > 0)
        dfs(i, j + 1, k, p);
    if (((1 << j) & k) == 0)
        dfs(i, j + 1, k, p | (1 << j));
    if (((1 << j) & k) == 0 && j + 1 < n && ((1 << (j + 1)) & k) == 0)
        dfs(i, j + 2, k, p);
    return;
}
int main()
{
    freopen("board.in", "r", stdin);
    freopen("board.out", "w", stdout);
    scanf("%d%d", &n, &m);
    dp[1][0] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < (1 << n); j++)
        {
            if (dp[i][j])
                dfs(i, 0, j, 0);
        }
    }
    printf("%d\n", dp[m + 1][0] % mod);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
