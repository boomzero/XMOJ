#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100005;
const ll W = 1000000;
ll n, k, w[N], cnt[W], ans, f[N];
int main()
{
    freopen("train.in", "r", stdin);
    freopen("train.out", "w", stdout);
    scanf("%lld%lld", &n, &k);
    for (ll i = 1; i <= n; i++)
    {
        scanf("%lld", &w[i]);
        if (w[i] > 0)
        {
            if (f[1] + f[w[i] + 1] < k)
            {
                cnt[w[i]]++;
                ans++;
                f[1]++;
                f[w[i] + 2]--;
            }
        }
        else if (w[i] < 0)
        {
            w[i] = -w[i];
            if (cnt[w[i]] > 0)
            {
                cnt[w[i]]--;
                ans--;
                f[1]--;
                f[w[i] + 2]++;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
