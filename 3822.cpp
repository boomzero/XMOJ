#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100005;
ll n, m;
struct PERSON
{
    ll Price, Taste;
} People[N];
struct YOGHURT
{
    ll Price, Taste;
} Yoghurts[N];
int main()
{
    freopen("yoghurt.in", "r", stdin);
    freopen("yoghurt.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld%lld", &People[i].Price, &People[i].Taste);
    for (int i = 1; i <= m; i++)
        scanf("%lld%lld", &Yoghurts[i].Price, &Yoghurts[i].Taste);
    sort(People + 1, People + n + 1, [](PERSON a, PERSON b)
         { return a.Taste > b.Taste; });
    sort(Yoghurts + 1, Yoghurts + m + 1, [](YOGHURT a, YOGHURT b)
         { return a.Taste > b.Taste; });
    multiset<ll> MultiSet;
    ll Answer = 0;
    int YoghurtIndex = 1;
    for (int i = 1; i <= n; i++)
    {
        while (YoghurtIndex <= m && Yoghurts[YoghurtIndex].Taste >= People[i].Taste)
            MultiSet.insert(Yoghurts[YoghurtIndex++].Price);
        auto it = MultiSet.lower_bound(People[i].Price);
        if (it == MultiSet.end())
        {
            printf("-1\n");
            return 0;
        }
        Answer += *it;
        MultiSet.erase(it);
    }
    printf("%lld\n", Answer);
    return 0;
}
