#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x, y, z;
int main()
{
    freopen("change.in", "r", stdin);
    freopen("change.out", "w", stdout);
    scanf("%lld%lld%lld", &x, &y, &z);
    printf("%lld\n", z % 25 + (z / 25 + y) % 4 + ((z / 25 + y) / 4 + x) % 10);
    return 0;
}
