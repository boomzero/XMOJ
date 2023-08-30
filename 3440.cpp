#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
int n, m, f[8][3] = {{1, 1, 1}, {1, 1, -1}, {1, -1, 1}, {1, -1, -1}, {-1, 1, 1}, {-1, 1, -1}, {-1, -1, 1}, {-1, -1, -1}};
long long x[MAXN], y[MAXN], z[MAXN], s[MAXN], tmp, ans;
int main()
{
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i] >> z[i];
    for (int p = 0; p < 8; ++p)
    {
        for (int q = 0; q < n; ++q)
            s[q] = x[q] * f[p][0] + y[q] * f[p][1] + z[q] * f[p][2];
        for (int i = n - 1; i > 0; --i)
            for (int j = 0; j < i; ++j)
                if (s[j] < s[j + 1])
                    swap(s[j], s[j + 1]);
        tmp = 0;
        for (int i = 0; i < m; ++i)
            tmp += s[i];
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
