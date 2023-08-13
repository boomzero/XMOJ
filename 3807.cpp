#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1000005;
const ll M = 1005;
ll n, m, r, f[N];
struct EXERCISE
{
    ll s, e, p;
} Exercises[M];
int main()
{
    freopen("gym.in", "r", stdin);
    freopen("gym.out", "w", stdout);
    scanf("%lld%lld%lld", &n, &m, &r);
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld%lld%lld", &Exercises[i].s, &Exercises[i].e, &Exercises[i].p);
        Exercises[i].s -= r;
        Exercises[i].e--;
    }
    for (int i = 1; i <= n; i++)
    {
        f[i] = f[i - 1];
        for (int j = 1; j <= m; j++)
            if (Exercises[j].e == i)
                f[i] = max(f[i], f[Exercises[j].s - 1] + Exercises[j].p);
    }
    printf("%lld\n", f[n]);
    return 0;
}
