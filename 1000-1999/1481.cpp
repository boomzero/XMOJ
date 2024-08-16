#include <bits/stdc++.h>
using namespace std;
int height[1000010];
int n, m;
bool check(int h)
{
    long long s = 0;
    for (int i = 1; i <= n; ++i)
        if (height[i] > h)
            s += height[i] - h;
    return s >= m;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &height[i]);
    int l = 1, r = 1000000000;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    printf("%d\n", r);
    return 0;
}
