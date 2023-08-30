#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 50005;
ll n, k, a[N], f[N];
int main()
{
    // freopen("stone.in", "r", stdin);
    // freopen("stone.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for (ll i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    ll LeftPointer = 1, RightPointer = 1;
    while (RightPointer <= n)
    {
        while (RightPointer <= n && a[RightPointer] - a[LeftPointer] <= k)
            RightPointer++;
        f[LeftPointer] = RightPointer - LeftPointer;
        LeftPointer++;
    }
    ll Answer = 0;
    for (ll i = 1; i <= n; i++)
        Answer = max(Answer, f[i] + *max_element(f + i + f[i], f + n + 1));
    printf("%d\n", Answer);
    return 0;
}
