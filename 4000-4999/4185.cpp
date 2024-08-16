#include <bits/stdc++.h>
using namespace std;
struct A
{
    int t, id;
} a[100010 * 2];
bool cmp(const A &x, const A &y)
{
    return x.t < y.t;
}
int n, alone[100010], tot, lst, ans;
set<int> s;
int main()
{
    scanf("%d", &n);
    for (int i = 1, s, e; i <= n; ++i)
    {
        scanf("%d%d", &s, &e);
        a[2 * i - 1] = (A){s, i};
        a[2 * i] = (A){e, i};
    }
    sort(a + 1, a + n * 2 + 1, cmp);
    for (int i = 1; i <= n * 2; ++i)
    {
        if (s.size() == 1)
            alone[*s.begin()] += a[i].t - lst;
        if (s.size() > 0)
            tot += a[i].t - lst;
        if (s.find(a[i].id) != s.end())
            s.erase(a[i].id);
        else
            s.insert(a[i].id);
        lst = a[i].t;
    }
    for (int i = 1; i <= n; ++i)
        ans = max(ans, tot - alone[i]);
    printf("%d", ans);
    return 0;
}
