#include <bits/stdc++.h>

using namespace std;

struct A
{

    int x, y, v;

    bool operator<(const A &a) const
    {

        return v > a.v;
    }
};

A nuts[410];

int n, m, k, ans, x, y, sz;

int main()

{

    scanf("%d%d%d", &n, &m, &k);

    for (int i = 1; i <= n; i++)

        for (int j = 1, v; j <= m; j++)
        {

            scanf("%d", &v);

            if (v > 0)
                nuts[sz++] = (A){i, j, v};
        }

    sort(nuts, nuts + sz);

    x = 0;
    y = nuts[0].y;

    for (int i = 0; i < sz && k > 0; ++i)
    {

        int x2 = nuts[i].x, y2 = nuts[i].y;

        int t = 1 + abs(x2 - x) + abs(y2 - y);

        if (x2 + t > k)
            break;

        k -= t;

        x = x2;
        y = y2;

        ans += nuts[i].v;
    }

    printf("%d\n", ans);

    return 0;
}
