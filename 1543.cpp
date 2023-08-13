// 最长公共子序列 LCS
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1005;
ll l1, l2, s1[N], s2[N], f[N][N];
int main()
{
    scanf("%lld%lld", &l1, &l2);
    for (ll i = 1; i <= l1; i++)
        scanf("%lld", &s1[i]);
    for (ll i = 1; i <= l2; i++)
        scanf("%lld", &s2[i]);
    for (ll i = 1; i <= l1; i++)
        for (ll j = 1; j <= l2; j++)
            if (s1[i] == s2[j])
                f[i][j] = f[i - 1][j - 1] + 1;
            else
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
    printf("%lld\n", f[l1][l2]);
    return 0;
}
