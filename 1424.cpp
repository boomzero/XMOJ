#include <bits/stdc++.h>

using namespace std;

int n, m, s[1010];

long long ans;

struct P
{
    int id, t;
} p[1010];

bool cmp(const P &a, const P &b)

{

    return a.t < b.t || (a.t == b.t && a.id < b.id);
}

int main()

{

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i)
    {

        scanf("%d", &p[i].t);

        p[i].id = i;
    }

    sort(p + 1, p + n + 1, cmp);

    for (int i = 1; i <= m; ++i)

        s[i] = p[i].t;

    for (int i = m + 1; i <= n; ++i)
    {

        int which = i % m;

        if (which == 0)
            which = m;

        ans += s[which];

        s[which] += p[i].t;
    }

    for (int i = 1; i < n; ++i)
        printf("%d ", p[i].id);

    printf("%d\n", p[n].id);

    printf("%.2lf\n", (double)ans / n);

    return 0;
}
