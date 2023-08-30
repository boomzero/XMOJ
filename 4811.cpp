#include <bits/stdc++.h>
using namespace std;
int n, b[400010], a, l, r;
int main()
{
    freopen("seq.in", "r", stdin);
    freopen("seq.out", "w", stdout);
    scanf("%d%d", &n, &a);
    b[l = r = 200000] = a;
    for (int i = 2; i <= n; ++i)
    {
        scanf("%d", &a);
        if ((n - i) & 1)
            b[++r] = a;
        else
            b[--l] = a;
    }
    for (int i = l; i <= r; ++i)
        printf("%d%c", b[i], i == r ? '\n' : ' ');
    return 0;
}
