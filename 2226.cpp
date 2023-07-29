#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 500005;
const ll LOG_N = 20;
ll n, k, l, r, Answer, a[N], ST[N][LOG_N];
ll Query(ll l, ll r)
{
    ll k = log2(r - l + 1);
    ll x = ST[l][k];
    ll y = ST[r - (1 << k) + 1][k];
    return a[x] > a[y] ? x : y;
}
struct ELEMENT
{
    ll o, Left, Right, t;
    ELEMENT(ll o, ll Left, ll Right)
    {
        this->o = o;
        this->Left = Left;
        this->Right = Right;
        this->t = Query(Left, Right);
    }
};
bool operator<(ELEMENT First, ELEMENT Second)
{
    return a[First.t] - a[First.o - 1] < a[Second.t] - a[Second.o - 1];
}
std::priority_queue<ELEMENT> Stack;
int main()
{
    scanf("%lld%lld%lld%lld", &n, &k, &l, &r);
    for (ll i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        a[i] += a[i - 1];
    }
    for (ll i = 1; i <= n; i++)
        ST[i][0] = i;
    for (ll j = 1; (1 << j) <= n; j++)
        for (ll i = 1; i + (1 << j) - 1 <= n; i++)
        {
            ll x = ST[i][j - 1];
            ll y = ST[i + (1 << (j - 1))][j - 1];
            ST[i][j] = a[x] > a[y] ? x : y;
        }
    for (ll i = 1; i <= n; i++)
        if (i + l - 1 <= n)
            Stack.push(ELEMENT(i, i + l - 1, min(i + r - 1, n)));
    while (k--)
    {
        ll o = Stack.top().o;
        ll Left = Stack.top().Left;
        ll Right = Stack.top().Right;
        ll t = Stack.top().t;
        Stack.pop();
        Answer += a[t] - a[o - 1];
        if (Left != t)
            Stack.push(ELEMENT(o, Left, t - 1));
        if (t != Right)
            Stack.push(ELEMENT(o, t + 1, Right));
    }
    printf("%lld\n", Answer);
    return 0;
}
