#include <bits/stdc++.h>
using namespace std;
double num[1000010], x, b, ans;
int a, w, n, t, pos;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        memset(num, 0, sizeof(num));
        pos = ans = 0;
        scanf("%d%d", &w, &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d%lf", &a, &b);
            b /= double(a);
            for (int j = 1; j <= a; ++j)
                num[++pos] = b;
        }
        sort(num + 1, num + pos + 1);
        for (int i = pos, j = 1; i >= 1 && j <= w; --i, ++j)
            ans += num[i];
        printf("%.2lf\n", ans);
    }
    return 0;
}
