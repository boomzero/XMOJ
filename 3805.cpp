#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1005;
const ll dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const ll dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
ll n, k, Field[N][N], Cover[N][N][8];
ll FastRead()
{
    ll x = 0;
    char Char = getchar();
    while (Char >= '0' && Char <= '9')
    {
        x = x * 10 + Char - '0';
        Char = getchar();
    }
    return x;
}
int main()
{
    freopen("corndolly.in", "r", stdin);
    freopen("corndolly.out", "w", stdout);
    // scanf("%lld%lld", &n, &k);
    n = FastRead();
    k = FastRead();
    for (ll i = 0; i < k; i++)
    {
        ll x, y;
        // scanf("%lld%lld", &x, &y);
        x = FastRead();
        y = FastRead();
        Field[x - 1][y - 1]++;
    }
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
            for (ll Direction = 0; Direction < 8; Direction++)
            {
                ll x = i + dx[Direction];
                ll y = j + dy[Direction];
                while (x >= 0 && x < n && y >= 0 && y < n)
                {
                    Cover[i][j][Direction] += Field[x][y];
                    x += dx[Direction];
                    y += dy[Direction];
                }
            }
    ll Answer = 0;
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
        {
            ll Count = Field[i][j];
            for (ll Direction = 0; Direction < 8; Direction++)
                Count += Cover[i][j][Direction];
            if (Count == k)
                Answer++;
        }
    printf("%lld\n", Answer);
    return 0;
}
