#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = (x << 3) + (x << 1) + ch - '0';
        ch = getchar();
    }
    return (f == 1) ? x : -x;
}
int t, n, flag, a[101010], cnt[101010];
signed main()
{
    freopen("f.in", "r", stdin);
    freopen("f.out", "w", stdout);
    t = read();
    while (t--)
    {
        flag = 0;
        memset(cnt, 0, sizeof(cnt));
        n = read();
        for (int i = 1; i <= n; i++)
            a[i] = read();
        for (int i = 1; i <= n; i++)
            cnt[a[i]]++;
        sort(a + 1, a + 1 + n);
        int zj = a[n], mid = a[1];
        if (mid != zj && mid != (zj + 1) / 2)
            flag = 1;
        if (cnt[mid] != 1 + zj % 2)
            flag = 1;
        for (int i = mid + 1; i <= zj; i++)
            if (cnt[i] < 2)
                flag = 1;
        if (flag)
            puts("Impossible");
        else
            puts("Possible");
    }
    return 0;
}
