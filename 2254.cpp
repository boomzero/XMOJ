#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 305;
int n, e[N], f[N][N], Answer = -1;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &e[i]);
        e[i + n] = e[i];
    }
    for (int i = 2; i < 2 * n; i++)
        for (int j = i - 1; i - j < n && j >= 1; j--)
        {
            for (int k = j; k < i; k++)
                f[j][i] = max(f[j][i], f[j][k] + f[k + 1][i] + e[j] * e[k + 1] * e[i + 1]);
            if (f[j][i] > Answer)
                Answer = f[j][i];
        }
    printf("%d\n", Answer);
    return 0;
}
