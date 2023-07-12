#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll q, l, r;
int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%lld", &q);
    while (q-- > 0)
    {
        scanf("%lld%lld", &l, &r);
        printf("%lld\n", (r - l) * (r - l + 1) / 2);
    }
    return 0;
}
