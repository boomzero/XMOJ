#include <bits/stdc++.h>
using namespace std;
int n, m, ans = 0x7fffffff;
int minn[20], maxx[16][101][10001];
void dfs(int k, int r, int h, int s, int v)
{
    if (s + 2 * v / r > ans)
        return;
    if (v < minn[k])
        return;
    if (v > maxx[k][r][h])
        return;
    if (k == m)
    {
        if (v == 0 && ans > s)
            ans = s;
        return;
    }
    for (int tr = r - 1; tr >= m - k; tr--)
        for (int th = h - 1; th >= m - k; th--)
            dfs(k + 1, tr, th, s + 2 * tr * th, v - tr * tr * th);
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        minn[m - i] = minn[m - i + 1] + i * i * i;
    for (int r = 1; r * r <= n; ++r)
        for (int h = 1; h <= n / (r * r); ++h)
            for (int i = 1; i < m; ++i)
                maxx[m - i][r][h] = maxx[m - i + 1][r][h] + (r - i) * (r - i) * (h - i);
    for (int r = m; r * r <= int(double(n) / m); ++r)
        for (int h = n / (r * r); h >= m; --h)
        {
            int s = r * r + 2 * r * h;
            int v = n - r * r * h;
            dfs(1, r, h, s, v);
        }
    if (ans == 0x7fffffff)
        ans = 0;
    cout << ans << endl;
    return 0;
}
