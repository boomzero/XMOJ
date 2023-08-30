#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 505;
const ll M = 55;
ll n, m, a[N][M], b[N][M];
const map<char, int> Map = {
    {'A', 0},
    {'C', 1},
    {'G', 2},
    {'T', 3}};
unordered_set<ll> Set;
int main()
{
    scanf("%lld%lld", &n, &m);
    for (ll i = 0; i < n; i++)
    {
        char Buffer[M];
        scanf("%s", Buffer);
        for (ll j = 0; j < m; j++)
            a[i][j] = Map.at(Buffer[j]);
    }
    for (ll i = 0; i < n; i++)
    {
        char Buffer[M];
        scanf("%s", Buffer);
        for (ll j = 0; j < m; j++)
            b[i][j] = Map.at(Buffer[j]);
    }
    ll Answer = 0;
    for (ll x = 0; x < m; x++)
        for (ll y = x + 1; y < m; y++)
            for (ll z = y + 1; z < m; z++)
            {
                Set.clear();
                for (ll i = 0; i < n; i++)
                    Set.insert(a[i][x] * 16 + a[i][y] * 4 + a[i][z]);
                bool Flag = true;
                for (ll i = 0; i < n && Flag; i++)
                    if (Set.count(b[i][x] * 16 + b[i][y] * 4 + b[i][z]))
                        Flag = false;
                if (Flag)
                    Answer++;
            }
    printf("%lld\n", Answer);
    return 0;
}
