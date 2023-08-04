#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace IN
{
    typedef unsigned uint;
    uint a, b, c, d;
    void init(uint A, uint B, uint C, uint D)
    {
        a = A, b = B, c = C, d = D;
    }
    uint rand()
    {
        c = (long long)c * b % a;
        return c;
    }
    void Getop(int &type, int &x)
    {
        type = rand() / 10 % 3 + 1;
        x = rand() % d + 1;
    }
}
ll n, a, b, c, d;
multiset<ll> Set;
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%lld%lld%lld%lld%lld", &n, &a, &b, &c, &d);
    IN::init(a, b, c, d);
    Set.insert(0);
    Set.insert(10000001);
    for (ll i = 0; i < n; i++)
    {
        int op, x;
        IN::Getop(op, x);
        if (op == 1)
            Set.insert(x);
        else if (op == 2)
            printf("%lld\n", *--Set.lower_bound(x));
        else
            printf("%lld\n", *Set.upper_bound(x));
    }
    return 0;
}
