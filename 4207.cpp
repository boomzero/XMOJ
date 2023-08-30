#include <bits/stdc++.h>
using namespace std;
int n, b, f[260], s[260], d[260], ans = 1000000;
bool vis[260][260];
void dfs(int ci, int cb)
{
    if (vis[ci][cb])
        return;
    vis[ci][cb] = true;
    if (ci == n - 1)
    {
        ans = min(ans, cb);
        return;
    }
    for (int i = ci + 1; i < n && i - ci <= d[cb]; ++i)
        if (f[i] <= s[cb])
            dfs(i, cb);
    for (int i = cb + 1; i < b; ++i)
        if (f[ci] <= s[i])
            dfs(ci, i);
}
int main()
{
    cin >> n >> b;
    for (int i = 0; i < n; ++i)
        cin >> f[i];
    for (int i = 0; i < b; ++i)
        cin >> s[i] >> d[i];
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}
