#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2005;
ll n, a[N], d[N][N], c[N];
int main()
{
    freopen("stick.in", "r", stdin);
    freopen("stick.out", "w", stdout);
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        c[i] = a[i];
    }
    sort(c + 1, c + n + 1);
    for (int i = 1; i <= n; i++)
        d[1][i] = abs(a[1] - c[i]);
    for (int i = 2; i <= n; i++)
    {
        ll Min = d[i - 1][1];
        for (int j = 1; j <= n; j++)
        {
            Min = min(Min, d[i - 1][j]);
            d[i][j] = Min + abs(a[i] - c[j]);
        }
    }
    ll Answer = d[n][1];
    for (int i = 1; i <= n; i++)
        Answer = min(Answer, d[n][i]);
    printf("%lld\n", Answer);
    return 0;
}
