#include <bits/stdc++.h>
int n, a[100];
void print()
{
    for (int i = 1; i < 2 * n; ++i)
        printf("%d ", a[i]);
    printf("%d\n", a[2 * n]);
}
bool dfs(int d)
{
    if (d == 0)
    {
        print();
        return true;
    }
    for (int i = 1; i + d + 1 <= 2 * n; ++i)
    {
        if (!a[i] && !a[i + d + 1])
        {
            a[i] = a[i + d + 1] = d;
            if (dfs(d - 1))
                return true;
            a[i] = a[i + d + 1] = 0;
        }
    }
    return false;
}
int main()
{
    scanf("%d", &n);
    dfs(n);
    return 0;
}
