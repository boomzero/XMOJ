#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
ll m, n, Answer;
int main()
{
    freopen("spp.in", "r", stdin);
    freopen("spp.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    if (n < m)
        swap(n, m);
    Answer = n;
    for (int i = 1; i <= m; i++)
        Answer = Answer * (n + m - i + 1) / i;
    printf("%lld\n", Answer % MOD);
    return 0;
}
