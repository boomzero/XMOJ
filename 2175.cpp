#include <bits/stdc++.h>

using namespace std;

int n, m, a[100010];

int main()

{

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i)

        scanf("%d", &a[i]);

    for (int i = 1, x; i <= m; ++i)
    {

        scanf("%d", &x);

        int p1 = upper_bound(a + 1, a + n + 1, x) - a;

        int p2 = lower_bound(a + 1, a + n + 1, x) - a;

        int ans1 = (p1 == n + 1 ? -1 : p1);

        int ans2 = (p2 == n + 1 ? -1 : p2);

        int ans3 = (p2 <= 1 ? -1 : p2 - 1);

        int ans4 = (p1 <= 1 ? -1 : p1 - 1);

        int ans5 = (a[1] < x ? 1 : -1);

        int ans6 = (a[n] > x ? n : -1);

        printf("%d %d %d %d %d %d\n",

               ans1, ans2, ans3, ans4, ans5, ans6);
    }

    return 0;
}
