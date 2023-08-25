#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3FFF'FFFF'FFFF'FFFF;
const ll N = 100005;
ll n, c[N], MapDepth, Min[N], Max[N];
stack<ll> Stack;
int main()
{
    scanf("%lld", &n);
    fill(Min, Min + N, INF);
    fill(Max, Max + N, -INF);
    Min[0] = 0;
    Max[0] = n + 1;
    for (ll i = 1; i <= n; ++i)
    {
        scanf("%lld", &c[i]);
        Min[c[i]] = min(Min[c[i]], i);
        Max[c[i]] = max(Max[c[i]], i);
    }
    for (ll i = 0; i <= n + 1; ++i)
    {
        if (i == Min[c[i]])
        {
            Stack.push(c[i]);
            MapDepth = max(MapDepth, (ll)Stack.size());
        }
        if (Stack.top() != c[i])
        {
            printf("-1\n");
            return 0;
        }
        if (i == Max[c[i]])
            Stack.pop();
    }
    printf("%lld\n", MapDepth - 1);
    return 0;
}
