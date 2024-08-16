#include <bits/stdc++.h>
using namespace std;
const int N = 15;
char n[N], ans[N];
int main()
{
    freopen("big.in", "r", stdin);
    freopen("big.out", "w", stdout);
    scanf("%s", n);
    strcpy(ans, n);
    for (int i = 0; i < strlen(n); i++)
        for (int j = 0; j < strlen(n); j++)
        {
            swap(n[i], n[j]);
            if (strcmp(ans, n) < 0)
                strcpy(ans, n);
            swap(n[i], n[j]);
        }
    printf("%s\n", ans);
    return 0;
}
