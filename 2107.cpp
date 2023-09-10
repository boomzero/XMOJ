#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 105;
const ll M = 25005;
ll T, n, a[N];
bool Visited[M];
int main()
{
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
    scanf("%lld", &T);
    while (T-- > 0)
    {
        memset(Visited, 0, sizeof(Visited));
        ll MaxN = 0;
        ll Answer = 0;
        scanf("%lld", &n);
        for (ll i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
            MaxN = max(MaxN, a[i]);
        }
        sort(a + 1, a + n + 1);
        for (ll i = 1; i <= n; i++)
        {
            if (Visited[a[i]])
                continue;
            Visited[a[i]] = true;
            Answer++;
            for (ll j = a[i]; j <= MaxN; j++)
                if (Visited[j - a[i]])
                    Visited[j] = true;
        }
        printf("%lld\n", Answer);
    }
    return 0;
}
