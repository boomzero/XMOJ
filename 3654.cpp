#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, g[N], f[N], a[N], Answer;
int main()
{
    freopen("chorus.in", "r", stdin);
    freopen("chorus.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    fill(f + 1, f + n + 1, 1);
    fill(g + 1, g + n + 1, 1);
    for (int i = n - 1; i >= 1; i--)
        for (int j = i + 1; j <= n; j++)
            if (a[i] > a[j] && f[i] <= f[j] + 1)
                f[i] = f[j] + 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j < i; j++)
            if (a[i] > a[j] && g[i] <= g[j] + 1)
                g[i] = g[j] + 1;
    for (int i = 1; i <= n; i++)
        Answer = max(Answer, f[i] + g[i] - 1);
    printf("%d\n", n - Answer);
}
