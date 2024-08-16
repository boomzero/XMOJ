#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
ll n, m;
ll Multiply(ll x, ll y)
{
    return x * y % MOD;
}
ll Power(ll a, ll b)
{
    ll Answer = 1;
    while (b)
    {
        if (b % 2 == 1)
            Answer = Multiply(Answer, a);
        b /= 2;
        a = Multiply(a, a);
    }
    return Answer;
}
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    if (n > m)
        swap(n, m);
    if (n == 1)
        printf("%lld\n", Power(2, m));
    else if (n == 2)
        printf("%lld\n", Multiply(4, Power(3, m - 1)));
    else if (n == 3)
        printf("%lld\n", Multiply(112, Power(3, m - 3)));
    else
    {
        if (m == n)
            printf("%lld\n", (83 * Power(8, n) % MOD + 5 * Power(2, n + 7) % MOD) * 190104168 % MOD);
        else
            printf("%lld\n", (83 * Power(8, n) % MOD + Power(2, n + 8)) * Power(3, m - n - 1) % MOD * 570312504 % MOD);
    }
    return 0;
}
