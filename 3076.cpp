#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100005;
ll n, m, MCount, Min, PeopleCount;
struct
{
    string Sex;
    ll Count;
} Input[N];
int main()
{
    // freopen("queue.in", "r", stdin);
    // freopen("queue.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    for (ll i = 0; i < m; i++)
    {
        char c[200005];
        scanf("%s%lld", c, &Input[i].Count);
        Input[i].Sex = c;
        for (size_t j = 0; j < Input[i].Sex.length(); j++)
        {
            if (Input[i].Sex[j] == 'M')
                MCount += Input[i].Count;
            PeopleCount += Input[i].Count;
        }
    }
    if (MCount * 2 > PeopleCount)
    {
        printf("-1\n");
        return 0;
    }
    ll Temp = 0;
    for (ll i = m - 1; i >= 0; i--)
    {
        for (ll j = Input[i].Sex.length() - 1; j >= 0; j--)
        {
            if (Input[i].Sex[j] == 'M')
            {
                Temp -= Input[i].Count;
                Min = min(Min, Temp);
            }
            else
                Temp += Input[i].Count;
        }
    }
    printf("%lld\n", -Min - 1);
    return 0;
}
