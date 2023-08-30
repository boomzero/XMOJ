#include <bits/stdc++.h>
using namespace std;
int n, m, num[100001], l, r, mid;
bool check(int expense)
{
    int cnt = 1, x = 0;
    for (int i = 1; i <= n; i++)
    {
        x += num[i];
        if (x > expense)
        {
            ++cnt;
            x = num[i];
        }
    }
    return cnt <= m;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &num[i]);
        if (num[i] > l)
            l = num[i];
        r += num[i];
    }
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (!check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    printf("%d\n", l);
    return 0;
}
