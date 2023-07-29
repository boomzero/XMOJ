#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N = 200005;
const ll MOD = 1000000007;
const ll MAGIC_NUMBER = 403219;
ll HashTable1[N], HashTable2[N], Operator[N], a[N], n;
map<ll, bool> Map;
vector<ll> Record;
ll get_hash1(ll x, ll y)
{
    return (HashTable1[y] - HashTable1[x - 1] * Operator[y - x + 1] % MOD + MOD) % MOD;
}
ll get_hash2(ll x, ll y)
{
    return (HashTable2[x] - HashTable2[y + 1] * Operator[y - x + 1] % MOD + MOD) % MOD;
}
int main()
{
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    Operator[0] = 1;
    for (ll i = 1; i <= n; i++)
        Operator[i] = Operator[i - 1] * MAGIC_NUMBER % MOD;
    for (ll i = 1; i <= n; i++)
        HashTable1[i] = (HashTable1[i - 1] * MAGIC_NUMBER % MOD + (ll)a[i]) % MOD;
    for (ll i = n; i >= 1; i--)
        HashTable2[i] = (HashTable2[i + 1] * MAGIC_NUMBER % MOD + (ll)a[i]) % MOD;
    ll Max = 0;
    for (ll k = 1; k <= n; k++)
    {
        Map.clear();
        ll Count = 0;
        for (ll i = 1; i <= n; i += k)
        {
            if (i + k - 1 > n)
                continue;
            ll Hash = get_hash1(i, i + k - 1) * get_hash2(i, i + k - 1);
            if (Map.count(Hash))
                continue;
            Map[Hash] = true;
            Count++;
        }
        if (Count > Max)
        {
            Max = Count;
            Record.clear();
            Record.push_back(k);
        }
        else if (Count == Max)
            Record.push_back(k);
    }
    printf("%lld %lld\n", Max, Record.size());
    for (ll i = 0; i <= Record.size() - 1; i++)
        printf("%lld ", Record[i]);
    printf("\n");
    return 0;
}
