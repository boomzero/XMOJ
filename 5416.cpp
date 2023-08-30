#include <bits/stdc++.h>
using namespace std;
int a[100010], d[100010];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    if (n == 0)
    {
        printf("0\n");
        return 0;
    }
    d[1] = a[1];
    int len = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] >= d[len])
            d[++len] = a[i];
        else
        {
            int j = upper_bound(d + 1, d + len + 1, a[i]) - d;
            d[j] = a[i];
        }
    }
    printf("%d", len);
    return 0;
}
