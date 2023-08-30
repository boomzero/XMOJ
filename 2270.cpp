#include <bits/stdc++.h>
using namespace std;
int n, v[110], lc[110], rs[110], root;
int d(int x)
{
    int ans = 0;
    for (int i = lc[x]; i; i = rs[i])
        ans++;
    return ans;
}
int main()
{
    scanf("%d%d", &n, &root);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d%d", &v[i], &lc[i], &rs[i]);
    int k, x;
    scanf("%d", &k);
    while (k--)
    {
        scanf("%d", &x);
        printf("%d\n", d(x));
    }
    return 0;
}
