#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
map<int, int> sc;
int main()
{
    freopen("move.in", "r", stdin);
    freopen("move.out", "w", stdout);
    ll cf = 0, sf = 0, cy = -2000000000;
    scanf("%d", &n);
    for (int i = 0, a, b; i < n; ++i)
    {
        scanf("%d%d", &a, &b);
        cf += abs(a - b);
        if (abs(a) > abs(a - b))
            continue;
        sc[b] += 2;
        if ((a < b && a < 0) || (a >= b && a >= 0))
        {
            sc[0]--;
            sc[2 * b]--;
        }
        if ((a < b && a >= 0) || (a >= b && a < 0))
        {
            sc[2 * b - 2 * a]--;
            sc[2 * a]--;
        }
    }
    ll ans = cf;
    for (auto p : sc)
    {
        int ny = p.first, d = p.second;
        cf += sf * (ny - cy);
        cy = ny;
        sf += d;
        ans = min(ans, cf);
    }
    printf("%lld\n", ans);
    return 0;
}
