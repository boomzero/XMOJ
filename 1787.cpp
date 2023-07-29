#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 500'005;
const ll MAGIC_NUMBER = 1'000'000'007;
ll n, Answer, Power[N], LeftHash[N], RightHash[N];
char s[N];
bool Check(ll LeftBound, ll RightBound, ll x)
{
    ll Temp1 = LeftHash[LeftBound + x - 1] - LeftHash[LeftBound - 1];
    ll Temp2 = RightHash[RightBound + x - 1] - RightHash[RightBound - 1];
    if (LeftBound > RightBound)
    {
        swap(Temp1, Temp2);
        swap(LeftBound, RightBound);
    }
    Temp1 *= Power[RightBound - LeftBound];
    return Temp1 == Temp2;
}
int main()
{
    scanf("%lld%s", &n, s);
    Power[0] = 1;
    for (ll i = 1; i <= n; i++)
        Power[i] = Power[i - 1] * MAGIC_NUMBER;
    for (ll i = 1; i <= n; i++)
        LeftHash[i] = LeftHash[i - 1] + s[i - 1] * Power[i];
    for (ll i = 1; i <= n; i++)
        RightHash[i] = RightHash[i - 1] + (s[n - i] ^ 1) * Power[i];
    for (ll i = 2; i <= n; i++)
    {
        ll LeftBound = 1;
        ll RightBound = min(n - i + 1, i - 1);
        ll Total = 0;
        while (LeftBound <= RightBound)
        {
            ll Middle = (LeftBound + RightBound) >> 1;
            if (Check(i, n - i + 2, Middle))
            {
                Total = max(Middle, Total);
                LeftBound = Middle + 1;
            }
            else
                RightBound = Middle - 1;
        }
        Answer += Total;
    }
    printf("%lld\n", Answer);
    return 0;
}
